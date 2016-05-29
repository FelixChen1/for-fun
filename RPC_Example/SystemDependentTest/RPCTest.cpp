#include "stdafx.h"
#include "CppUnitTest.h"
#include <time.h>
#include <list>
#include "..\global.h"
#include "..\RPCServer\RPCServer.h"
#include "..\RPCClient\RPCClient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SystemDependentTest
{
    #define BUF_SIZE 50
    const int MAX_SIZE_TO_TRANSMIT = 100;

    int allocCount;
    int pullCount;
    int pushCount;

	std::list<void*> memoryToFree;

    RPCServer server;
    RPCClient client;

	template<typename T>
	void __RPC_USER PipeAlloc(char *state, unsigned long bsize, T **buf, unsigned long *bcount)
	{
		if (bsize > (BUF_SIZE * sizeof(T)))
		{
			*bcount = BUF_SIZE * sizeof(T);
		}
		else
		{
			*bcount = bsize;
		}

		(*buf) = (T *)malloc(sizeof(T) * (*bcount));
		memoryToFree.push_back(*buf);

		for (int i = 0; i < (*bcount); i++)
		{
			(*buf)[i] = i;
		}

		allocCount++;
	}

	template<typename T>
	void __RPC_USER PipePull(char* state, T *buffer, unsigned long esize, unsigned long *ecount)
	{
		unsigned long i;
		byte elementsToRead;

		if (*state >= MAX_SIZE_TO_TRANSMIT)
		{
			*ecount = 0; /* end of pipe data */
			*state = 0; /* Reset the state = global index */
		}
		else
		{
			elementsToRead = esize > BUF_SIZE ? BUF_SIZE : esize;

			for (int i = 0; i < elementsToRead; i++)
			{
				/*client sends data */
				buffer[i] = i;
			}

			*state += elementsToRead;
			*ecount = elementsToRead;
		}
		pullCount++;
	}

	template<typename T>
	void __RPC_USER PipePush(char *state, T *buf, unsigned long ecount)
	{
		unsigned long elementsToCopy;
		T local_pipe_data[BUF_SIZE];
		for (int i = 0; i < BUF_SIZE; i++)
		{
			local_pipe_data[i] = 63;
		}
		if (ecount == 0)/* end of data */
		{
			*state = 0; /* Reset the state = global index */
		}
		else
		{
            elementsToCopy = ecount > BUF_SIZE ? BUF_SIZE : ecount;

			for (int i = 0; i < elementsToCopy; i++)
			{
				/*client receives data */
				local_pipe_data[i] = buf[i];
				(*state)++;
                Assert::AreEqual((T)(i + 1), buf[i]);
			}
		}
		pushCount++;
	}

    TEST_CLASS(RPCTest)
    {
    public:
        TEST_CLASS_INITIALIZE(TestClassInitialize)
        {
            server.InitRPCServer();
            client.InitRPCClient();
        }
        TEST_CLASS_CLEANUP(TestClassCleanUp)
        {
        }
        TEST_METHOD_INITIALIZE(TestMethodInitialize)
        {
        }
        TEST_METHOD_CLEANUP(TestMethodCleanUp)
        {
            if (!memoryToFree.empty())
            {
                std::list<void*>::iterator it = memoryToFree.begin();
                std::list<void*>::iterator end = memoryToFree.end();
                while (it != end)
                {
                    free((void *)(*it));
                    it++;
                }
                memoryToFree.clear();
            }
        }

        TEST_METHOD(BaseTypeTest)
        {
            boolean booleanValue = true;
            byte byteValue = 'a';
            unsigned char unsignedCharValue = 'a';
            double doubleValue = 6.3;
            float floatValue = 6.3f;
            hyper hyperValue = 9223372036854775807;       //2^63 - 1
            int intValue = 2147483647;                    //2^31 - 1
            __int3264 int3264Value = 2147483647;          //2^31 - 1
            long longValue = 2147483647;                  //2^31 - 1
            short shortValue = 32767;                     //2^15 - 1
            small smallValue = 'a';
            wchar_t wchar_tValue = L'a';

            bool ret = client.BaseType(&booleanValue, &byteValue, &unsignedCharValue, &doubleValue, &floatValue,
                &hyperValue, &intValue, &int3264Value, &longValue, &shortValue, &smallValue, &wchar_tValue);

            Assert::IsTrue(ret);
            Assert::AreEqual((boolean)false, booleanValue);
            Assert::AreEqual((byte)'b', byteValue);
            Assert::AreEqual((unsigned char)'b', unsignedCharValue);
            Assert::AreEqual(7.3, doubleValue);
            Assert::AreEqual(7.3f, floatValue);
            Assert::AreEqual(true, (hyperValue - 9223372036854775808) == 0);
            Assert::AreEqual((int)2147483648, intValue);
            Assert::AreEqual((__int3264)2147483648, int3264Value);
            Assert::AreEqual((long)2147483648, longValue);
            Assert::AreEqual((short)32768, shortValue);
            Assert::AreEqual('b', smallValue);
            Assert::AreEqual(L'b', wchar_tValue);
        }

        TEST_METHOD(UnionParamProcTest)
        {
            DISCRIM_UNION_PARAM_TYPE Union;
            short sUtype = 0;
            Union.sVal = 32767;

            short ret = client.UnionParamProc(&Union, sUtype);

            Assert::AreEqual(ret, sUtype);
            Assert::AreEqual((short)32768, Union.sVal);

            sUtype = 1;
            Union.fVal = 1.1f;

            ret = client.UnionParamProc(&Union, sUtype);

            Assert::AreEqual(ret, sUtype);
            Assert::AreEqual(2.1f, Union.fVal);

            sUtype = 2;
            Union.chVal = 'a';

            ret = client.UnionParamProc(&Union, sUtype);

            Assert::AreEqual(ret, sUtype);
            Assert::AreEqual((unsigned char)'b', Union.chVal);
        }

        TEST_METHOD(UnionStructProcTest)
        {
            DISCRIM_UNION_STRUCT_TYPE u1;
            u1.utype = 0;
            u1.u.sVal = 32767;

            short ret = client.UnionStructProc(&u1);

            Assert::AreEqual(ret, u1.utype);
            Assert::AreEqual((short)32768, u1.u.sVal);

            u1.utype = 1;
            u1.u.fVal = 1.1f;

            ret = client.UnionStructProc(&u1);

            Assert::AreEqual(ret, u1.utype);
            Assert::AreEqual(2.1f, u1.u.fVal);

            u1.utype = 2;
            u1.u.chVal = 'a';

            ret = client.UnionStructProc(&u1);

            Assert::AreEqual(ret, u1.utype);
            Assert::AreEqual((unsigned char)'b', u1.u.chVal);
        }

        TEST_METHOD(EncapsulatedUnionProcTest)
        {
            UNION_ENCAPSULATED encapsulatedUnion;
            encapsulatedUnion.uType = 1024;
            encapsulatedUnion.uValue.f1 = 1.1f;

            long ret = client.EncapsulatedUnionProc(&encapsulatedUnion);

            Assert::AreEqual(ret, encapsulatedUnion.uType);
            Assert::AreEqual(2.1f, encapsulatedUnion.uValue.f1);

            encapsulatedUnion.uType = 2048;
            encapsulatedUnion.uValue.d2 = 3.3;

            ret = client.EncapsulatedUnionProc(&encapsulatedUnion);

            Assert::AreEqual(ret, encapsulatedUnion.uType);
            Assert::AreEqual(4.3, encapsulatedUnion.uValue.d2);
        }

        TEST_METHOD(EnumProcTest)
        {
            ENUM_WEEK enumWeek = THURSDAY;
            ENUM_WEEK *pEnumWeek = &enumWeek;

            client.EnumProc(pEnumWeek);

            Assert::IsTrue(enumWeek == FRIDAY);

            enumWeek = SUNDAY;

            client.EnumProc(pEnumWeek);

            Assert::IsTrue(enumWeek == 7);
        }

        // first and last elements won't change
        // those beyond the range won't change too
        // those in between will be in reverse order
        TEST_METHOD(VaryingArrayProcTest)
        {
            unsigned char achArray[ARRAY_SIZE];
            for (int i = 0; i < 26; i++)
            {
                achArray[i] = 'a' + i;
            }
            long lFirstElement = 1;
            long lChunkSize = 24;

            client.VaryingArrayProc(lFirstElement, lChunkSize, achArray);

            Assert::IsTrue((lFirstElement - 1) == 0);
            Assert::IsTrue((lChunkSize - 24) == 0);
            Assert::AreEqual((unsigned char)('a'), achArray[0]);
            Assert::AreEqual((unsigned char)('z'), achArray[25]);
            for (int i = 1; i < 25; i++)
            {
                Assert::AreEqual((unsigned char)('z' - i), achArray[i]);
            }
        }

        TEST_METHOD(ConformantArrayProcTest)
        {
            unsigned char achArray[26];
            unsigned char achArray2[10];
            for (int i = 0; i < 26; i++)
            {
                achArray[i] = 'a' + i;
            }
            for (int i = 0; i < 10; i++)
            {
                achArray2[i] = '0' + i;
            }
            long lArraySize = 26;
            long lMaxSize = 10;

            client.ConformantArrayProc(lArraySize, achArray, lMaxSize, achArray2);

            for (int i = 0; i < 26; i++)
            {
                Assert::AreEqual((unsigned char)('z' - i), achArray[i]);
            }
            for (int i = 0; i < 10; i++)
            {
                Assert::AreEqual((unsigned char)('9' - i), achArray2[i]);
            }
        }

        TEST_METHOD(PointerTypeProcTest)
        {
            unsigned char referenceChar = 'a';
            unsigned char *referenceCharPointer = &referenceChar;
            unsigned char *referenceCharPointer2 = referenceCharPointer;
            unsigned char *referenceCharPointer3 = referenceCharPointer;
            unsigned char referenceChar2 = 'a';

            client.PointerTypeProc(&referenceChar, nullptr, nullptr);
            Assert::AreEqual((unsigned char)('b'), referenceChar);

            client.PointerTypeProc(referenceCharPointer, nullptr, nullptr);
            Assert::AreEqual((unsigned char)('c'), *referenceCharPointer);

            client.PointerTypeProc(referenceCharPointer2, nullptr, nullptr);
            Assert::AreEqual((unsigned char)('d'), *referenceCharPointer2);

            client.PointerTypeProc(referenceCharPointer3, nullptr, nullptr);
            Assert::AreEqual((unsigned char)('e'), *referenceCharPointer3);

            client.PointerTypeProc(&referenceChar2, nullptr, nullptr);
            Assert::AreEqual((unsigned char)('b'), referenceChar2);

            unsigned char uniqueChar = 'a';
            unsigned char uniqueChar2 = 'a';
            unsigned char *uniqueCharPointer = &uniqueChar;
            unsigned char *uniqueCharPointer2 = uniqueCharPointer;
            unsigned char *uniqueCharPointer3 = uniqueCharPointer;

            client.PointerTypeProc(&referenceChar, &uniqueChar, nullptr);
            Assert::AreEqual((unsigned char)('b'), uniqueChar);

            client.PointerTypeProc(&referenceChar, uniqueCharPointer, nullptr);
            Assert::AreEqual((unsigned char)('c'), *uniqueCharPointer);

            client.PointerTypeProc(&referenceChar, uniqueCharPointer2, nullptr);
            Assert::AreEqual((unsigned char)('d'), *uniqueCharPointer2);

            client.PointerTypeProc(&referenceChar, uniqueCharPointer3, nullptr);
            Assert::AreEqual((unsigned char)('e'), *uniqueCharPointer3);

            client.PointerTypeProc(&referenceChar, &uniqueChar2, nullptr);
            Assert::AreEqual((unsigned char)('b'), uniqueChar2);

            unsigned char fullChar = 'a';
            unsigned char *fullCharPointer = &fullChar;

            client.PointerTypeProc(&referenceChar, nullptr, &fullChar);
            Assert::AreEqual((unsigned char)('b'), fullChar);

            client.PointerTypeProc(&referenceChar, nullptr, fullCharPointer);
            Assert::AreEqual((unsigned char)('c'), *fullCharPointer);
        }

		TEST_METHOD(InOutPipeTest)
		{
			CHAR_PIPE pipe;
			allocCount = 0;
			pullCount = 0;
            pushCount = 0;

			char pipeDataIndex = 0;
			pipe.state = &pipeDataIndex;
			pipe.pull = PipePull<unsigned char>;
			pipe.alloc = PipeAlloc<unsigned char>;
			pipe.push = PipePush<unsigned char>;

            client.InOutPipe(&pipe); /* Make the rpc */

			Assert::AreEqual(6, allocCount);
			Assert::AreEqual(3, pullCount);
            Assert::AreEqual(3, pushCount);
        }

        TEST_METHOD(TwoInterfaceTest)
        {
            time_t timeData;
            client.GetTime(reinterpret_cast<long long *>(&timeData));

            time_t timeDataExpected;
            time(&timeDataExpected);

            Assert::IsTrue(timeDataExpected - timeData == 0);
        }

        TEST_METHOD(ShutdownTest)
        {
        }
    };

}
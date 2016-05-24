#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RPCServer\RPCServer.h"
#include "..\RPCClient\RPCClient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SystemDependentTest
{
    RPCServer server;
    RPCClient client;
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
            // test class cleanup  code
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

            int difference = hyperValue - 9223372036854775808;
            Assert::AreEqual(0, difference);
            Assert::AreEqual((int)2147483648, intValue);
            Assert::AreEqual((__int3264)2147483648, int3264Value);
            Assert::AreEqual((long)2147483648, longValue);
            Assert::AreEqual((short)32768, shortValue);
            Assert::AreEqual('b', smallValue);
            Assert::AreEqual(L'b', wchar_tValue);
		}

	};
}
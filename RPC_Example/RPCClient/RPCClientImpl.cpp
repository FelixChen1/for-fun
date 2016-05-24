#include <iostream>
#include"RPCClientImpl.h"

/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}

void DisplayString(unsigned char *p1)
{
    std::cout << p1 << std::endl;
}

void UnionParamProcTest()
{
    std::cout << "========== UnionParamProcTest ==========" << std::endl;
    DISCRIM_UNION_PARAM_TYPE Union;
    short sUtype = 0;
    Union.sVal = 32767;
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << sUtype << std::endl
        << "\tunion: " << Union.sVal << " - " << Union.fVal << " - " << Union.chVal << std::endl;
    short ret = UnionParamProc(&Union, sUtype);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << sUtype << std::endl
        << "\tunion: " << Union.sVal << " - " << Union.fVal << " - " << Union.chVal << std::endl;

    sUtype = 1;
    Union.fVal = 1.1f;
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << sUtype << std::endl
        << "\tunion: " << Union.sVal << " - " << Union.fVal << " - " << Union.chVal << std::endl;
    ret = UnionParamProc(&Union, sUtype);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << sUtype << std::endl
        << "\tunion: " << Union.sVal << " - " << Union.fVal << " - " << Union.chVal << std::endl;

    sUtype = 2;
    Union.chVal = 'a';
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << sUtype << std::endl
        << "\tunion: " << Union.sVal << " - " << Union.fVal << " - " << Union.chVal << std::endl;
    ret = UnionParamProc(&Union, sUtype);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << sUtype << std::endl
        << "\tunion: " << Union.sVal << " - " << Union.fVal << " - " << Union.chVal << std::endl;

    std::cout << std::endl;
}

void UnionStructProcTest()
{
    std::cout << "========== UnionStructProcTest ==========" << std::endl;
    DISCRIM_UNION_STRUCT_TYPE u1;
    u1.utype = 0;
    u1.u.sVal = 32767;
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << u1.utype << std::endl
        << "\tunion: " << u1.u.sVal << " - " << u1.u.fVal << " - " << u1.u.chVal << std::endl;
    short ret = UnionStructProc(&u1);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << u1.utype << std::endl
        << "\tunion: " << u1.u.sVal << " - " << u1.u.fVal << " - " << u1.u.chVal << std::endl;

    u1.utype = 1;
    u1.u.fVal = 1.1f;
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << u1.utype << std::endl
        << "\tunion: " << u1.u.sVal << " - " << u1.u.fVal << " - " << u1.u.chVal << std::endl;
    ret = UnionStructProc(&u1);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << u1.utype << std::endl
        << "\tunion: " << u1.u.sVal << " - " << u1.u.fVal << " - " << u1.u.chVal << std::endl;

    u1.utype = 2;
    u1.u.chVal = 'a';
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << u1.utype << std::endl
        << "\tunion: " << u1.u.sVal << " - " << u1.u.fVal << " - " << u1.u.chVal << std::endl;
    ret = UnionStructProc(&u1);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << u1.utype << std::endl
        << "\tunion: " << u1.u.sVal << " - " << u1.u.fVal << " - " << u1.u.chVal << std::endl;

    std::cout << std::endl;
}

void EncapsulatedUnionProcTest()
{
    std::cout << "========== EncapsulatedUnionProcTest ==========" << std::endl;
    UNION_ENCAPSULATED encapsulatedUnion;
    encapsulatedUnion.uType = 1024;
    encapsulatedUnion.uValue.f1 = 1.1f;
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << encapsulatedUnion.uType << std::endl
        << "\tunion: " << encapsulatedUnion.uValue.f1 << " - " << encapsulatedUnion.uValue.d2 << std::endl;
    long ret = EncapsulatedUnionProc(&encapsulatedUnion);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << encapsulatedUnion.uType << std::endl
        << "\tunion: " << encapsulatedUnion.uValue.f1 << " - " << encapsulatedUnion.uValue.d2 << std::endl;

    encapsulatedUnion.uType = 2048;
    encapsulatedUnion.uValue.d2 = 3.3;
    std::cout << "send:" << std::endl;
    std::cout << "\ttype: " << encapsulatedUnion.uType << std::endl
        << "\tunion: " << encapsulatedUnion.uValue.f1 << " - " << encapsulatedUnion.uValue.d2 << std::endl;
    ret = EncapsulatedUnionProc(&encapsulatedUnion);
    std::cout << "receive:" << ret << std::endl;
    std::cout << "type\t: " << encapsulatedUnion.uType << std::endl
        << "\tunion: " << encapsulatedUnion.uValue.f1 << " - " << encapsulatedUnion.uValue.d2 << std::endl;

    std::cout << std::endl;
}

void EnumProcTest()
{
    std::cout << "========== EnumProcTest ==========" << std::endl;
    ENUM_WEEK enumWeek = THURSDAY;
    std::cout << "send:" << enumWeek << std::endl;

    EnumProc(&enumWeek);

    std::cout << "receive:" << enumWeek << std::endl;
    std::cout << std::endl;
}

void VaryingArrayProcTest()
{
    std::cout << "========== VaryingArrayProcTest ==========" << std::endl;
    unsigned char achArray[ARRAY_SIZE];
    for (int i = 0; i < 26; i++)
    {
        achArray[i] = 'a' + i;
    }
    long lFirstElement = 1;
    long lChunkSize = 20;
    std::cout << "send: " << std::endl;
    std::cout << "\tlFirstElement: " << lFirstElement << std::endl
        << "\tlChunkSize: " << lChunkSize << std::endl
        << "\tarcArray : ";
    for (int i = 0; i < 26; i++)
    {
        std::cout << achArray[i];
    }
    std::cout << "." << std::endl;

    VaryingArrayProc(lFirstElement, lChunkSize, achArray);

    std::cout << "receive: " << std::endl;
    std::cout << "\tlFirstElement: " << lFirstElement << std::endl
        << "\tlChunkSize: " << lChunkSize << std::endl
        << "\tarcArray : ";
    for (int i = 0; i < 26; i++)
    {
        std::cout << achArray[i];
    }
    std::cout << "." << std::endl;
    std::cout << std::endl;
}

void ConformantArrayProcTest()
{
    std::cout << "========== ConformantArrayProcTest ==========" << std::endl;
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

    std::cout << "send: " << std::endl;
    std::cout << "\tlArraySize: " << lArraySize << std::endl
        << "\tarcArray : ";
    for (int i = 0; i < 26; i++)
    {
        std::cout << achArray[i];
    }
    std::cout << "." << std::endl;

    std::cout << "\tlMaxSize: " << lMaxSize << std::endl
        << "\tarcArray2 : ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << achArray2[i];
    }
    std::cout << "." << std::endl;

    ConformantArrayProc(lArraySize, achArray, lMaxSize, achArray2);

    std::cout << "receive: " << std::endl;
    std::cout << "\tlArraySize: " << lArraySize << std::endl
        << "\tarcArray : ";
    for (int i = 0; i < 26; i++)
    {
        std::cout << achArray[i];
    }
    std::cout << "." << std::endl;

    std::cout << "\tlMaxSize: " << lMaxSize << std::endl
        << "\tarcArray2 : ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << achArray2[i];
    }
    std::cout << "." << std::endl;
    std::cout << std::endl;
}

void PointerTypeProcTest()
{
    std::cout << "========== PointerTypeProcTest ==========" << std::endl;
    unsigned char referenceChar = 'a';
    unsigned char *referenceCharPointer = &referenceChar;
    unsigned char *referenceCharPointer2 = referenceCharPointer;
    unsigned char *referenceCharPointer3 = referenceCharPointer;
    unsigned char uniqueChar = 'a';
    unsigned char *uniqueCharPointer = &uniqueChar;
    unsigned char fullChar = 'a';
    unsigned char *fullCharPointer = &fullChar;
    std::cout << "send:" << std::endl;
    std::cout << "reference char: " << referenceChar << std::endl
        << "unique char: " << uniqueChar  << std::endl
        << "full char: " << fullChar << std::endl;

    PointerTypeProc(referenceCharPointer3, uniqueCharPointer, fullCharPointer);

    std::cout << "receive:" << std::endl;
    std::cout << "reference char: " << referenceChar << std::endl
        << "unique char: " << uniqueChar << std::endl
        << "full char: " << fullChar << std::endl;
    std::cout << std::endl;
}

#define BUF_SIZE 50
#define PIPE_SIZE 100
long *globalPipeData;
long globalBuffer[BUF_SIZE];

char pipeDataIndex; /* state variable */

void InPipeTest()
{
    std::cout << "========== InPipeTest ==========" << std::endl;
    LONG_PIPE inPipe;
    int i;
    globalPipeData = (long *)malloc(sizeof(long) * PIPE_SIZE);

    for (i = 0; i < PIPE_SIZE; i++)
    {
        globalPipeData[i] = 5;
    }

    pipeDataIndex = 0;
    inPipe.state = &pipeDataIndex;
    inPipe.pull = PipePull;
    inPipe.alloc = PipeAlloc;

    InPipe(inPipe); /* Make the rpc */

    free((void *)globalPipeData);
    std::cout << std::endl;

}//end SendLongs

void __RPC_USER PipeAlloc(char* stateInfo, unsigned long requestedSize, long **allocatedBuffer, unsigned long *allocatedSize)
{
    std::cout << "\tPipeAlloc("
        << (int)*stateInfo << " , "
        << requestedSize << " , "
        << allocatedBuffer << " , "
        << *allocatedSize << ")" << std::endl;
    char *state = stateInfo;
    if (requestedSize > (BUF_SIZE*sizeof(long)))
    {
        *allocatedSize = BUF_SIZE * sizeof(long);
    }
    else
    {
        *allocatedSize = requestedSize;
    }
    *allocatedBuffer = globalBuffer;
    std::cout << "\t         ("
        << (int)*stateInfo << " , "
        << requestedSize << " , "
        << allocatedBuffer << " , "
        << *allocatedSize << ")" << std::endl;
} //end PipeAlloc

void __RPC_USER PipePull(char* stateInfo, long *inputBuffer, unsigned long maxBufSize, unsigned long *sizeToSend)
{
    std::cout << "\tPipePull("
        << (int)*stateInfo << " , "
        << inputBuffer << " , "
        << maxBufSize << " , "
        << *sizeToSend << ")" << std::endl;
    small currentIndex;
    unsigned long i;
    small elementsToRead;
    char *state = stateInfo;

    currentIndex = *state;
    if (*state >= PIPE_SIZE)
    {
        std::cout << "\tend of pipe data" << std::endl;
        *sizeToSend = 0; /* end of pipe data */
        *state = 0; /* Reset the state = global index */
    }
    else
    {
        if (currentIndex + maxBufSize > PIPE_SIZE)
            elementsToRead = PIPE_SIZE - currentIndex;
        else
            elementsToRead = maxBufSize;

        for (i = 0; i < elementsToRead; i++)
        {
            /*client sends data */
            inputBuffer[i] = globalPipeData[i + currentIndex];
        }

        *state += elementsToRead;
        *sizeToSend = elementsToRead;
    }
    std::cout << "\t        ("
        << (int)*stateInfo << " , "
        << inputBuffer << " , "
        << maxBufSize << " , "
        << *sizeToSend << ")" << std::endl;
}//end PipePull

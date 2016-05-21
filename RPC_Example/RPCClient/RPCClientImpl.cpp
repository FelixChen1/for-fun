#include <iostream>
#include"RPCClientImpl.h"

void BaseValueTest()
{
    std::cout << "========== BaseValueTest ==========" << std::endl;
    boolean booleanValue = true;
    byte byteValue = 'a';
    unsigned char unsignedCharValue = 'a';
    double doubleValue = 6.3L;
    float floatValue = 6.3f;
    hyper hyperValue = 9223372036854775807;       //2^63 - 1
    int intValue = 2147483647;                    //2^31 - 1
    __int3264 int3264Value = 2147483647;          //2^31 - 1
    long longValue = 2147483647;                  //2^31 - 1
    short shortValue = 32767;                     //2^15 - 1
    small smallValue = 'a';
    wchar_t wchar_tValue = L'a';

    std::cout << "send:" << std::endl;
    std::cout << "\tboolean:" << (booleanValue ? "true" : "false") << std::endl
        << "\tbyte:" << byteValue << std::endl
        << "\tunsigned char:" << unsignedCharValue << std::endl
        << "\tdouble:" << doubleValue << std::endl
        << "\tfloat:" << floatValue << std::endl
        << "\thyper:" << hyperValue << std::endl
        << "\tint:" << intValue << std::endl
        << "\tlong:" << longValue << std::endl
        << "\tshort:" << shortValue << std::endl
        << "\tsmall:" << smallValue << std::endl;
    std::wcout << L"\twchar_t:" << wchar_tValue << std::endl;

    BaseType(&booleanValue, &byteValue, &unsignedCharValue, &doubleValue, &floatValue,
        &hyperValue, &intValue, &int3264Value, &longValue, &shortValue, &smallValue, &wchar_tValue);

    std::cout << "receive:" << std::endl;
    std::cout << "boolean:" << (booleanValue ? "true" : "false") << std::endl
        << "\tbyte:" << byteValue << std::endl
        << "\tunsigned char:" << unsignedCharValue << std::endl
        << "\tdouble:" << doubleValue << std::endl
        << "\tfloat:" << floatValue << std::endl
        << "\thyper:" << hyperValue << std::endl
        << "\tint:" << intValue << std::endl
        << "\tlong:" << longValue << std::endl
        << "\tshort:" << shortValue << std::endl
        << "\tsmall:" << smallValue << std::endl;
    std::wcout << L"\twchar_t:" << wchar_tValue << std::endl;
    std::cout << std::endl;
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
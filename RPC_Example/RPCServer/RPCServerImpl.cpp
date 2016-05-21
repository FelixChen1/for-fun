#include <iostream>
#include "..\RPCInterface\hello.h"


void HelloProc(unsigned char * pszString)
{
	std::cout << pszString << std::endl;
}

void Shutdown(void)
{
    // callback first
    DisplayString(reinterpret_cast<unsigned char *>("Ther server is shutting down"));
	RPC_STATUS status;

	status = RpcMgmtStopServerListening(NULL);

	if (status)
	{
		exit(status);
	}

	status = RpcServerUnregisterIf(NULL, NULL, FALSE);

	if (status)
	{
		exit(status);
	}
}

void BaseType(
    /* [out][in] */ boolean *pBoolean,
    /* [out][in] */ byte *pByte,
    /* [out][in] */ unsigned char *pChar,
    /* [out][in] */ double *pDouble,
    /* [out][in] */ float *pFloat,
    /* [out][in] */ hyper *pHyper,
    /* [out][in] */ int *pInt,
    /* [out][in] */ __int3264 *pInt3264,
    /* [out][in] */ long *pLong,
    /* [out][in] */ short *pShort,
    /* [out][in] */ small *pSmall,
    /* [out][in] */ wchar_t *pWchar_t)
{
    (*pBoolean) == TRUE ? (*pBoolean) = FALSE : (*pBoolean) = TRUE;
    (*pByte)++;
    (*pChar)++;
    (*pDouble)++;
    (*pFloat)++;
    (*pHyper)++;
    (*pInt)++;
    (*pInt3264)++;
    (*pLong)++;
    (*pShort)++;
    (*pSmall)++;
    (*pWchar_t)++;
}

short UnionParamProc(
    /* [switch_is][out][in] */ DISCRIM_UNION_PARAM_TYPE *Union,
    /* [in] */ short sUtype)
{
    switch (sUtype)
    {
    case 0: { Union->sVal++;  break; }
    case 1: { Union->fVal++;  break; }
    case 2: { Union->chVal++; break; }
    }
    return sUtype;
}

short UnionStructProc(
    /* [out][in] */ DISCRIM_UNION_STRUCT_TYPE *u1)
{
    switch (u1->utype)
    {
    case 0: { u1->u.sVal++;  break; }
    case 1: { u1->u.fVal++;  break; }
    case 2: { u1->u.chVal++; break; }
    }
    return u1->utype;
}

long EncapsulatedUnionProc(
    /* [out][in] */ UNION_ENCAPSULATED *encapsulatedUnion)
{
    switch (encapsulatedUnion->uType)
    {
    case 1024: { encapsulatedUnion->uValue.f1++;  break; }
    case 2048: { encapsulatedUnion->uValue.d2++;  break; }
    }
    return encapsulatedUnion->uType;
}

void EnumProc(
    /* [out][in] */ ENUM_WEEK *pEnumWeek)
{
    (*pEnumWeek) = (ENUM_WEEK)((*pEnumWeek) + 1);
}

void VaryingArrayProc(
    /* [in] */ long lFirstElement,
    /* [in] */ long lChunkSize,
    /* [length_is][first_is][out][in] */ unsigned char achArray[1000])
{
    unsigned char tempChar;
    int first = lFirstElement;
    int last = lFirstElement + lChunkSize - 1;
    int count = lChunkSize;
    while(count > 1)
    {
        tempChar = achArray[first];
        achArray[first] = achArray[last];
        achArray[last] = tempChar;
        first++;
        last--;
        count -= 2;
    }
    achArray[lFirstElement + lChunkSize] = '0';
    lFirstElement--;
    lChunkSize--;
}

void ConformantArrayProc(
    long lArraySize,
    /* [size_is][out][in] */ unsigned char achArray[],
    long lMaxSize,
    /* [max_is][out][in] */ unsigned char achArray2[])
{
    unsigned char tempChar;
    int first = 0;
    int last = lArraySize - 1;
    int count = lArraySize;
    while (count > 1)
    {
        tempChar = achArray[first];
        achArray[first] = achArray[last];
        achArray[last] = tempChar;
        first++;
        last--;
        count -= 2;
    }

    first = 0;
    last = lMaxSize - 1;
    count = lMaxSize;
    while (count > 1)
    {
        tempChar = achArray2[first];
        achArray2[first] = achArray2[last];
        achArray2[last] = tempChar;
        first++;
        last--;
        count -= 2;
    }
}

void PointerTypeProc(
    /* [ref][out][in] */ unsigned char *pReferenceChar,
    /* [unique][out][in] */ unsigned char *pUniqueChar,
    /* [string][full][out][in] */ unsigned char *pFullChar)
{
    if (pReferenceChar) { (*pReferenceChar)++; }
    if (pUniqueChar) { (*pUniqueChar)++; }
    if (pFullChar) { (*pFullChar)++; }
}
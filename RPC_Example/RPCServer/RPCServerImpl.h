#pragma once

#include "..\RPCInterface\hello.h"

/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/
void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);
void HelloProc(unsigned char * pszString);
void Shutdown(void);
void BaseType(boolean *pBoolean,
    byte *pByte,
    unsigned char *pChar,
    double *pDouble,
    float *pFloat,
    hyper *pHyper,
    int *pInt,
    __int3264 *pInt3264,
    long *pLong,
    short *pShort,
    small *pSmall,
    wchar_t *pWchar_t);
short UnionParamProc(DISCRIM_UNION_PARAM_TYPE *Union, short sUtype);
short UnionStructProc(DISCRIM_UNION_STRUCT_TYPE *u1);
long EncapsulatedUnionProc(UNION_ENCAPSULATED *encapsulatedUnion);
void EnumProc(ENUM_WEEK *pEnumWeek);
void VaryingArrayProc(long lFirstElement, long lChunkSize, unsigned char achArray[1000]);
void ConformantArrayProc(
    long lArraySize,
    unsigned char achArray[],
    long lMaxSize,
    unsigned char achArray2[]);
void PointerTypeProc(
    unsigned char *pReferenceChar,
    unsigned char *pUniqueChar,
    unsigned char *pFullChar);
void InPipe(LONG_PIPE long_pipe);
void OutPipe(LONG_PIPE *outputPipe);
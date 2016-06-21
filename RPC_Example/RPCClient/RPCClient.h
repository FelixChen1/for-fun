#pragma once
#include "..\global.h"
#include "..\RPCInterface\hello.h"
#include "..\spn.h"

class RPC_API RPCClient
{
public:
    RPCClient();
    ~RPCClient();

    void InitRPCClient(ClientBindingParam *bindingParam, SpnParam *spnParam, ClientAuthInfoParam* authInfoParam);

    void **GetPrimaryHandle();

    void HelloProc(unsigned char * pszString);
    bool BaseType(boolean *pBoolean,
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
    void VaryingArrayProc(
        long lFirstElement,
        long lChunkSize,
        unsigned char achArray[1000]);
    void ConformantArrayProc(
        long lArraySize,
        unsigned char achArray[],
        long lMaxSize,
        unsigned char achArray2[]);
    void PointerTypeProc(
        unsigned char *pReferenceChar,
        unsigned char *pUniqueChar,
        unsigned char *pFullChar);
    void InOutPipe(CHAR_PIPE *pipe_data);
    bool Shutdown(void);

    void GetTime(long long *timeData);

    short RemoteOpen(PPCONTEXT_HANDLE_TYPE pphContext, unsigned char *pszFileName);
    short RemoteRead(PCONTEXT_HANDLE_TYPE phContext, unsigned char achBuf[], short *pcbBuf);
    void RemoteClose(PPCONTEXT_HANDLE_TYPE pphContext);
private:
    void **primaryHandle;
    bool MakeSpn(SpnParam *spnParam);
    bool SetAuthInfo(ClientAuthInfoParam *authInfoParam);
    bool bInitialized;
};


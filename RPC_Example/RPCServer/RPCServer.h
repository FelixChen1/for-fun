#pragma once
#include "..\global.h"
#include "..\RPCInterface\hello.h"

class RPC_API RPCServer
{
public:
    RPCServer();
    ~RPCServer();

    bool InitRPCServer();

    void HelloProc(unsigned char * pszString);
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
        /* [out][in] */ wchar_t *pWchar_t);
    void Shutdown(void);
private:
    unsigned char * pszProtocolSequence;
    unsigned char * pszSecurity;
    unsigned char * pszEndpoint;
    unsigned int    cMinCalls;
    unsigned int    fDontWait;
};


#pragma once
#ifdef RPC_EXPORTS
#define RPC_API __declspec(dllexport)
#else
#define RPC_API __declspec(dllimport)
#endif
#include "..\RPCInterface\hello.h"

class RPC_API RPCClient
{
public:
    RPCClient();
    ~RPCClient();

    void InitRPCClient();

    //void HelloProc(unsigned char * pszString);
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
    bool Shutdown(void);

private:
    unsigned char * pszUuid;
    unsigned char * pszProtocolSequence;
    unsigned char * pszNetworkAddress;
    unsigned char * pszEndpoint;
    unsigned char * pszOptions;
    unsigned char * pszStringBinding;
    bool bInitialized;
};


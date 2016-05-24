#include <iostream>
#include "RPCClient.h"
#include "RPCClientImpl.h"

RPCClient::RPCClient()
{
    pszUuid = NULL;
    pszProtocolSequence = reinterpret_cast<unsigned char*>("ncacn_np");
    pszNetworkAddress = NULL;
    pszEndpoint = reinterpret_cast<unsigned char*>("\\pipe\\hello");
    pszOptions = NULL;
    pszStringBinding = NULL;
    bInitialized = false;
}

RPCClient::~RPCClient()
{
    RPC_STATUS status;
    if (pszStringBinding)
    {
        status = RpcStringFree(&pszStringBinding);
        if (status)
        {
            std::cout << "FAILED to free RPC binding string: " << pszStringBinding << std::endl;
            std::cout << "Error code: " << status << "." << std::endl;
        }
    }

    status = RpcBindingFree(&hello_IfHandle);
    if (status)
    {
        std::cout << "FAILED to free RPC binding, error code " << status << "." << std::endl;
    }
}

void RPCClient::InitRPCClient()
{
    RPC_STATUS status;

    status = RpcStringBindingCompose(pszUuid,
        pszProtocolSequence,
        pszNetworkAddress,
        pszEndpoint,
        pszOptions,
        &pszStringBinding);
    if (status)
    {
        return;
    }

    // hello_IfHandle is found from <interface-name>_c.c
    status = RpcBindingFromStringBinding(pszStringBinding, &hello_IfHandle);

    if (status)
    {
        return;
    }
    bInitialized = true;
}
//void RPCClient::HelloProc(unsigned char * pszString)
//{
//    RpcTryExcept
//    {
//        ::HelloProc(pszString);
//    }
//    RpcExcept(1)
//    {
//        unsigned long ulCode = RpcExceptionCode();
//        std::cout << "Runtime reported exception " << ulCode << std::endl;
//    }
//    RpcEndExcept
//}

bool RPCClient::BaseType(boolean *pBoolean,
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
    wchar_t *pWchar_t)
{
    bool ret = false;
    RpcTryExcept
    {
        ::BaseType(pBoolean, pByte, pChar, pDouble, pFloat, pHyper, pInt, pInt3264, pLong, pShort, pSmall, pWchar_t);
        ret = true;
    }
        RpcExcept(1)
    {
        unsigned long ulCode = RpcExceptionCode();
        std::cout << "Runtime reported exception " << ulCode << std::endl;
    }
    RpcEndExcept
    return ret;
}

bool RPCClient::Shutdown(void)
{
    ::Shutdown();
    return true;
}
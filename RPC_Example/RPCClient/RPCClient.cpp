#include <iostream>
#include "RPCClient.h"
#include "RPCClientImpl.h"
#include <dsparse.h>

RPCClient::RPCClient()
{
    primaryHandle = &hello_IfHandle;
    bInitialized = false;
}

RPCClient::~RPCClient()
{
    RPC_STATUS status;

    status = RpcBindingFree(primaryHandle);
    if (status)
    {
        std::cout << "FAILED to free RPC binding, error code " << status << "." << std::endl;
    }
}

void RPCClient::InitRPCClient(ClientBindingParam *bindingParam, SpnParam *spnParam, ClientAuthInfoParam* authInfoParam)
{
    RPC_STATUS status;

    if (bindingParam)
    {
        if (RpcStringBindingCompose(bindingParam->objUuid,
            bindingParam->protSeq,
            bindingParam->networkAddress,
            bindingParam->endpoint,
            bindingParam->options,
            &(bindingParam->stringBinding)))
        {
            return;
        }

        if (RpcBindingFromStringBinding(bindingParam->stringBinding, authInfoParam->binding))
        {
            return;
        }

        status = RpcStringFree(&(bindingParam->stringBinding));
        if (status)
        {
            std::cout << "FAILED to free RPC binding string: " << bindingParam->stringBinding << std::endl;
            std::cout << "Error code: " << status << "." << std::endl;
        }
    }

    if (spnParam)
    {
        if (!MakeSpn(spnParam))
        {
            return;
        }
    }

    if (authInfoParam)
    {
        if (!SetAuthInfo(authInfoParam))
        {
            return;
        }
    }

    bInitialized = true;
}

bool RPCClient::MakeSpn(SpnParam *spnParam)
{
    bool result = false;
    if (spnParam)
    {
        if (!DsMakeSpn(spnParam->serviceClass,
            spnParam->serviceName,
            spnParam->instanceName,
            spnParam->instancePort,
            spnParam->referrer,
            &(spnParam->spnLength),
            spnParam->spn))
        {
            result = true;
        }
    }
    return result;
}

bool RPCClient::SetAuthInfo(ClientAuthInfoParam *authInfoParam)
{
    bool result = false;
    if (authInfoParam)
    {
        if (!RpcBindingSetAuthInfo(
            *authInfoParam->binding,
            authInfoParam->spn,
            authInfoParam->authnLevel,
            authInfoParam->authnService,
            authInfoParam->authIdentity,
            authInfoParam->authzService))
        {
            result = true;
        }
    }
    return result;
}

void **RPCClient::GetPrimaryHandle()
{
    return primaryHandle;
}

void RPCClient::HelloProc(unsigned char * pszString)
{
    RpcTryExcept
    {
        ::HelloProc(pszString);
    }
    RpcExcept(1)
    {
        unsigned long ulCode = RpcExceptionCode();
        std::cout << "Runtime reported exception " << ulCode << std::endl;
    }
    RpcEndExcept
}

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

short RPCClient::UnionParamProc(DISCRIM_UNION_PARAM_TYPE *Union, short sUtype)
{
    return ::UnionParamProc(Union, sUtype);
}

short RPCClient::UnionStructProc(DISCRIM_UNION_STRUCT_TYPE *u1)
{
    return ::UnionStructProc(u1);
}

long RPCClient::EncapsulatedUnionProc(UNION_ENCAPSULATED *encapsulatedUnion)
{
    return ::EncapsulatedUnionProc(encapsulatedUnion);
}

void RPCClient::EnumProc(ENUM_WEEK *pEnumWeek)
{
    ::EnumProc(pEnumWeek);
}

void RPCClient::VaryingArrayProc(
    long lFirstElement,
    long lChunkSize,
    unsigned char achArray[1000])
{
    ::VaryingArrayProc(lFirstElement, lChunkSize, achArray);
}

void RPCClient::ConformantArrayProc(
    long lArraySize,
    unsigned char achArray[],
    long lMaxSize,
    unsigned char achArray2[])
{
    ::ConformantArrayProc(lArraySize, achArray, lMaxSize, achArray2);
}

void RPCClient::PointerTypeProc(
    unsigned char *pReferenceChar,
    unsigned char *pUniqueChar,
    unsigned char *pFullChar)
{
    ::PointerTypeProc(pReferenceChar, pUniqueChar, pFullChar);
}

void RPCClient::InOutPipe(CHAR_PIPE *pPipe)
{
	::InOutPipe(pPipe);
}

bool RPCClient::Shutdown(void)
{
    ::Shutdown();
    return true;
}

void RPCClient::GetTime(long long *timeData)
{
    ::GetTime(hello_IfHandle, timeData);
}

short RPCClient::RemoteOpen(PPCONTEXT_HANDLE_TYPE pphContext, unsigned char *pszFileName)
{
    return ::RemoteOpen(pphContext, pszFileName);
}

short RPCClient::RemoteRead(PCONTEXT_HANDLE_TYPE phContext, unsigned char achBuf[], short *pcbBuf)
{
    return ::RemoteRead(phContext, achBuf, pcbBuf);
}

void RPCClient::RemoteClose(PPCONTEXT_HANDLE_TYPE pphContext)
{
    ::RemoteClose(pphContext);
}
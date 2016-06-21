#include "RPCServer.h"
#include "RPCServerImpl.h"
#include <dsparse.h>

RPCServer::RPCServer()
{
    primaryHandle = &hello_v1_0_s_ifspec;
    secondaryHandle = &aux_v1_0_s_ifspec;
}

RPCServer::~RPCServer()
{
}

bool RPCServer::InitRPCServer(SpnParam *spnParam,
    AuthInfoParam *authInfoParam,
    ProtocalSeqParam *protSeqParam,
    InterfaceParam *ifParam,
    ListenParam *listenParam)
{
    RPC_STATUS status;

    if (!MakeSpn(spnParam))
    {
        return false;
    }

    if (!RegisterAuthInfo(authInfoParam))
    {
        return false;
    }

    if (!UseProtseqEp(protSeqParam))
    {
        return false;
    }

    if (!ifParam)
    {
        return false;
    }
    else
    {
        std::list<InterfaceParam> ifParams;
        ifParams.push_back(*ifParam);
        RegisterInterfaces(ifParams);
    }
    
    if (!Listen(listenParam))
    {
        return false;
    }

    return true;
}


void RPCServer::RegisterInterfaces(std::list<InterfaceParam> ifParamList)
{
    for (InterfaceParam ifParam : ifParamList)
    {
        if (!RpcServerRegisterIf(*ifParam.interfaceHandle,
            (UUID *)(ifParam.managerTypeUuid),
            ifParam.managerEpv))
        {
            return;
        }
    }
}

void **RPCServer::GetPrimaryHandle()
{
    return primaryHandle;
}

void **RPCServer::GetSecondaryHandle()
{
    return secondaryHandle;
}

bool RPCServer::MakeSpn(SpnParam *spnParam)
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

bool RPCServer::RegisterAuthInfo(AuthInfoParam *authInfoParam)
{
    bool result = false;
    if (authInfoParam)
    {
        if (!RpcServerRegisterAuthInfo(
            reinterpret_cast<unsigned char*>(authInfoParam->spn),
            authInfoParam->authService,
            RPC_AUTH_KEY_RETRIEVAL_FN(authInfoParam->getKeyCallback),
            authInfoParam->getKeyCallbackArg))
        {
            result = true;
        }
    }
    return result;
}

bool RPCServer::UseProtseqEp(ProtocalSeqParam *protSeqParam)
{
    bool result = false;

    if (protSeqParam)
    {
        if (!RpcServerUseProtseqEp(protSeqParam->protseq,
            protSeqParam->maxCalls,
            protSeqParam->endpoint,
            protSeqParam->securityDescriptor))
        {
            result = true;
        }
    }
    return result;
}

bool RPCServer::Listen(ListenParam *listenParam)
{
    bool result = false;

    if (listenParam)
    {
        if (!RpcServerListen(listenParam->minimumCallThreads,
            listenParam->maxCalls,
            listenParam->dontWait))
        {
            result = false;
        }
    }
    return result;
}
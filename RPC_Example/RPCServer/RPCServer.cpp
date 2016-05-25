#include "RPCServer.h"
#include "RPCServerImpl.h"

RPCServer::RPCServer()
{
    pszProtocolSequence = reinterpret_cast<unsigned char*>("ncacn_np");
    pszSecurity = NULL;
    pszEndpoint = reinterpret_cast<unsigned char*>("\\pipe\\hello");
    cMinCalls = 1;
    fDontWait = TRUE;
}

RPCServer::~RPCServer()
{
}

bool RPCServer::InitRPCServer()
{
    RPC_STATUS status;

    // there are typo error in website:
    // https://msdn.microsoft.com/en-us/library/windows/desktop/aa378869%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396
    // that the second parameter should be RPC_C_PROTSEQ_MAX_REQS_DEFAULT
    // NOT RPC_C_LISTEN_MAX_CALLS_DEFAULT which is used in "Listen" step.
    status = RpcServerUseProtseqEp(pszProtocolSequence,
        RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
        pszEndpoint,
        pszSecurity);

    if (status)
    {
        return false;
    }

    // hello_v1_0_s_ifspec is found from <interface-name>_s.c
    status = RpcServerRegisterIf(hello_v1_0_s_ifspec, NULL, NULL);

    if (status)
    {
        return false;
    }

    status = RpcServerListen(cMinCalls, RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        fDontWait);

    if (status)
    {
        return false;
    }

    return true;
}

void RPCServer::HelloProc(unsigned char * pszString)
{
    ::HelloProc(pszString);
}

void RPCServer::Shutdown(void)
{
    ::Shutdown();
}
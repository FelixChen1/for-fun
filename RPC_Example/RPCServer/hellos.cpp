#include "..\RPCInterface\hello.h"

void main()
{
    RPC_STATUS status;
    unsigned char * pszProtocolSequence = reinterpret_cast<unsigned char*>("ncacn_np");
    unsigned char * pszSecurity         = NULL;
    unsigned char * pszEndpoint         = reinterpret_cast<unsigned char*>("\\pipe\\hello");
    unsigned int    cMinCalls = 1;
    unsigned int    fDontWait = FALSE;

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
        exit(status);
    }
    
    // hello_v1_0_s_ifspec is found from <interface-name>_s.c
    status = RpcServerRegisterIf(hello_v1_0_s_ifspec, NULL, NULL); 

    if (status)
    {
        exit(status);
    }

    status = RpcServerListen(cMinCalls, RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        fDontWait);

    if (status)
    {
        exit(status);
    }
}

/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}
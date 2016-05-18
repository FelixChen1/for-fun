#include <iostream>
#include "..\RPCInterface\hello.h" 

void main()
{
    RPC_STATUS status;
    unsigned char * pszUuid             = NULL;
    unsigned char * pszProtocolSequence = reinterpret_cast<unsigned char*>("ncacn_np");
    unsigned char * pszNetworkAddress   = NULL;
    unsigned char * pszEndpoint         = reinterpret_cast<unsigned char*>("\\pipe\\hello");
    unsigned char * pszOptions          = NULL;
    unsigned char * pszStringBinding    = NULL;
    unsigned char * pszString           = reinterpret_cast<unsigned char*>("hello, world");
    unsigned long ulCode;

    status = RpcStringBindingCompose(pszUuid,
        pszProtocolSequence,
        pszNetworkAddress,
        pszEndpoint,
        pszOptions,
        &pszStringBinding);
    if (status)
    {
        exit(status);
    }
    
    // hello_IfHandle is found from <interface-name>_c.c
    status = RpcBindingFromStringBinding(pszStringBinding, &hello_IfHandle);

    if (status)
    {
        exit(status);
    }

    RpcTryExcept  
    {
        HelloProc(pszString);
        Shutdown();
    }
    RpcExcept(1) 
    {
        ulCode = RpcExceptionCode();
        std::cout<<"Runtime reported exception "<<ulCode<<std::endl;
    }
    RpcEndExcept

    status = RpcStringFree(&pszStringBinding); 

    if (status)
    {
        exit(status);
    }

    status = RpcBindingFree(&hello_IfHandle);

    if (status)
    {
        exit(status);
    }

    exit(0);
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


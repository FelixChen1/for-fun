#pragma once
#ifdef RPC_EXPORTS
#define RPC_API __declspec(dllexport)
#else
#define RPC_API __declspec(dllimport)
#endif

class RPC_API RPCServer
{
public:
    RPCServer();
    ~RPCServer();

    bool InitRPCServer();

    void HelloProc(unsigned char * pszString);
    void Shutdown(void);
private:
    unsigned char * pszProtocolSequence;
    unsigned char * pszSecurity;
    unsigned char * pszEndpoint;
    unsigned int    cMinCalls;
    unsigned int    fDontWait;
};


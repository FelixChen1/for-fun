#pragma once
#include <list>
#include "..\global.h"
#include "..\RPCInterface\hello.h"
#include "..\spn.h"

class RPC_API RPCServer
{
public:
    RPCServer();
    ~RPCServer();

    bool InitRPCServer(SpnParam *spnParam,
        AuthInfoParam *authInfoParam,
        ProtocalSeqParam *protSeqParam,
        InterfaceParam *ifParam,
        ListenParam *listenParam);

    void RegisterInterfaces(std::list<InterfaceParam> ifParamList);
    void **GetPrimaryHandle();
    void **GetSecondaryHandle();

private:
    bool MakeSpn(SpnParam *spnParam);
    bool RegisterAuthInfo(AuthInfoParam *authInfoParam);
    bool UseProtseqEp(ProtocalSeqParam *protSeqParam);
    bool Listen(ListenParam *listenParam);
    void **primaryHandle;
    void **secondaryHandle;
};


#pragma once
#ifdef RPC_EXPORTS
#define RPC_API __declspec(dllexport)
#else
#define RPC_API __declspec(dllimport)
#endif

typedef struct
{
    const char *serviceClass = nullptr;
    const char *serviceName = nullptr;
    const char *instanceName = nullptr;
    unsigned short instancePort = 0;
    const char *referrer = nullptr;
    unsigned long spnLength = 0;
    char *spn = nullptr;
}SpnParam;

typedef struct
{
    unsigned char *spn = nullptr;
    unsigned long authService = 0;
    void *getKeyCallback = nullptr;
    void *getKeyCallbackArg = nullptr;
}AuthInfoParam;

typedef struct
{
    unsigned char *protseq = nullptr;
    unsigned int maxCalls = 1;
    unsigned char *endpoint = nullptr;
    void *securityDescriptor = nullptr;
}ProtocalSeqParam;

typedef struct
{
    void **interfaceHandle = nullptr;
    void *managerTypeUuid = nullptr;
    void *managerEpv = nullptr;
}InterfaceParam;

typedef struct
{
    unsigned int minimumCallThreads = 0;
    unsigned int maxCalls = 0;
    unsigned int dontWait = 0;
}ListenParam;

typedef struct
{
    unsigned char *objUuid = nullptr;
    unsigned char *protSeq = nullptr;
    unsigned char *networkAddress = nullptr;
    unsigned char *endpoint = nullptr;
    unsigned char *options = nullptr;
    unsigned char *stringBinding = nullptr;
}ClientBindingParam;

typedef struct
{
    void **binding = nullptr;
    unsigned char *spn = nullptr;
    unsigned long authnLevel = 0;
    unsigned long authnService = 0;
    void *authIdentity = nullptr;
    unsigned long authzService = 0;
}ClientAuthInfoParam;
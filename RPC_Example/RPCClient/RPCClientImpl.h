#pragma once

#include "..\RPCInterface\hello.h"

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);
void DisplayString(unsigned char *p1);
void BaseValueTest();
void UnionParamProcTest();
void UnionStructProcTest();
void EncapsulatedUnionProcTest();
void EnumProcTest();
void VaryingArrayProcTest();
void ConformantArrayProcTest();
void PointerTypeProcTest();
void InPipeTest();
void __RPC_USER PipeAlloc(char* stateInfo, unsigned long requestedSize, long **allocatedBuffer, unsigned long *allocatedSize);
void __RPC_USER PipePull(char* stateInfo, long *inputBuffer, unsigned long maxBufSize, unsigned long *sizeToSend);
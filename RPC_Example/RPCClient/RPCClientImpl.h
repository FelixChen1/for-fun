#pragma once

#include "..\RPCInterface\hello.h"

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);
void DisplayString(unsigned char *p1);
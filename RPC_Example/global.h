#pragma once
#ifdef RPC_EXPORTS
#define RPC_API __declspec(dllexport)
#else
#define RPC_API __declspec(dllimport)
#endif
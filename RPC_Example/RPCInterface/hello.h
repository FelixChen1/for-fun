

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri May 27 15:30:47 2016
 */
/* Compiler settings for hello.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __hello_h__
#define __hello_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __hello_INTERFACE_DEFINED__
#define __hello_INTERFACE_DEFINED__

/* interface hello */
/* [implicit_handle][version][uuid] */ 

void HelloProc( 
    /* [string][in] */ unsigned char *pszString);

void Shutdown( void);

void BaseType( 
    /* [out][in] */ boolean *pBoolean,
    /* [out][in] */ byte *pByte,
    /* [out][in] */ unsigned char *pChar,
    /* [out][in] */ double *pDouble,
    /* [out][in] */ float *pFloat,
    /* [out][in] */ hyper *pHyper,
    /* [out][in] */ int *pInt,
    /* [out][in] */ __int3264 *pInt3264,
    /* [out][in] */ long *pLong,
    /* [out][in] */ short *pShort,
    /* [out][in] */ small *pSmall,
    /* [out][in] */ wchar_t *pWchar_t);

typedef /* [public][public][switch_type] */ union __MIDL_hello_0001
    {
    /* [case()] */ short sVal;
    /* [case()] */ float fVal;
    /* [case()] */ unsigned char chVal;
    /* [default] */  /* Empty union arm */ 
    } 	DISCRIM_UNION_PARAM_TYPE;

short UnionParamProc( 
    /* [switch_is][out][in] */ DISCRIM_UNION_PARAM_TYPE *Union,
    /* [in] */ short sUtype);

typedef /* [public][public] */ struct __MIDL_hello_0002
    {
    short utype;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ short sVal;
        /* [case()] */ float fVal;
        /* [case()] */ unsigned char chVal;
        /* [default] */  /* Empty union arm */ 
        } 	u;
    } 	DISCRIM_UNION_STRUCT_TYPE;

short UnionStructProc( 
    /* [out][in] */ DISCRIM_UNION_STRUCT_TYPE *u1);

typedef struct _UNION_ENCAPSULATED
    {
    long uType;
    /* [switch_is] */ /* [switch_type] */ union __MIDL_hello_0004
        {
        /* [case()] */ float f1;
        /* [case()] */ double d2;
        } 	uValue;
    } 	UNION_ENCAPSULATED;

long EncapsulatedUnionProc( 
    /* [out][in] */ UNION_ENCAPSULATED *encapsulatedUnion);

typedef 
enum _ENUM_WEEK
    {
        MONDAY	= 0,
        TUESDAY	= ( MONDAY + 1 ) ,
        WEDNESDAY	= ( TUESDAY + 1 ) ,
        THURSDAY	= ( WEDNESDAY + 1 ) ,
        FRIDAY	= ( THURSDAY + 1 ) ,
        SATURDAY	= ( FRIDAY + 1 ) ,
        SUNDAY	= ( SATURDAY + 1 ) 
    } 	ENUM_WEEK;

void EnumProc( 
    /* [out][in] */ ENUM_WEEK *pEnumWeek);

/* [callback] */ void DisplayString( 
    /* [string][in] */ unsigned char *p1);

#define	ARRAY_SIZE	( 1000 )

void VaryingArrayProc( 
    /* [in] */ long lFirstElement,
    /* [in] */ long lChunkSize,
    /* [length_is][first_is][out][in] */ unsigned char achArray[ 1000 ]);

void ConformantArrayProc( 
    long lArraySize,
    /* [size_is][out][in] */ unsigned char achArray[  ],
    long lMaxSize,
    /* [max_is][out][in] */ unsigned char achArray2[  ]);

void PointerTypeProc( 
    /* [ref][out][in] */ unsigned char *pReferenceChar,
    /* [unique][out][in] */ unsigned char *pUniqueChar,
    /* [string][full][out][in] */ unsigned char *pFullChar);

typedef struct pipe_LONG_PIPE
    {
    void (__RPC_USER * pull) (
        char * state,
        long * buf,
        unsigned long esize,
        unsigned long * ecount );
    void (__RPC_USER * push) (
        char * state,
        long * buf,
        unsigned long ecount );
    void (__RPC_USER * alloc) (
        char * state,
        unsigned long bsize,
        long * * buf,
        unsigned long * bcount );
    char * state;
    } 	LONG_PIPE;

void InPipe( 
    /* [in] */ LONG_PIPE pipe_data);

void OutPipe( 
    /* [out] */ LONG_PIPE *pipe_data);

typedef struct pipe_CHAR_PIPE
    {
    void (__RPC_USER * pull) (
        char * state,
        unsigned char * buf,
        unsigned long esize,
        unsigned long * ecount );
    void (__RPC_USER * push) (
        char * state,
        unsigned char * buf,
        unsigned long ecount );
    void (__RPC_USER * alloc) (
        char * state,
        unsigned long bsize,
        unsigned char * * buf,
        unsigned long * bcount );
    char * state;
    } 	CHAR_PIPE;

void InOutPipe( 
    /* [out][in] */ CHAR_PIPE *pipe_data);


extern handle_t hello_IfHandle;


extern RPC_IF_HANDLE hello_v1_0_c_ifspec;
extern RPC_IF_HANDLE hello_v1_0_s_ifspec;
#endif /* __hello_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



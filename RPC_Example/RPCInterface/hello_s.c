

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun May 29 13:54:03 2016
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

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>
#include "hello.h"

#define TYPE_FORMAT_STRING_SIZE   229                               
#define PROC_FORMAT_STRING_SIZE   521                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _hello_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } hello_MIDL_TYPE_FORMAT_STRING;

typedef struct _hello_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } hello_MIDL_PROC_FORMAT_STRING;

typedef struct _hello_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } hello_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

extern const hello_MIDL_TYPE_FORMAT_STRING hello__MIDL_TypeFormatString;
extern const hello_MIDL_PROC_FORMAT_STRING hello__MIDL_ProcFormatString;
extern const hello_MIDL_EXPR_FORMAT_STRING hello__MIDL_ExprFormatString;

/* Standard interface: hello, ver. 1.0,
   GUID={0x28b306b9,0x4f78,0x48d9,{0x94,0x44,0xa4,0xa1,0xdf,0x85,0x39,0xdf}} */


extern const MIDL_SERVER_INFO hello_ServerInfo;

extern const RPC_DISPATCH_TABLE hello_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE hello___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x28b306b9,0x4f78,0x48d9,{0x94,0x44,0xa4,0xa1,0xdf,0x85,0x39,0xdf}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&hello_v1_0_DispatchTable,
    0,
    0,
    0,
    &hello_ServerInfo,
    0x04000001
    };
RPC_IF_HANDLE hello_v1_0_s_ifspec = (RPC_IF_HANDLE)& hello___RpcServerInterface;

extern const MIDL_STUB_DESC hello_StubDesc;

 extern const MIDL_STUBLESS_PROXY_INFO hello_ProxyInfo;

/* [callback] */ void DisplayString( 
    /* [string][in] */ unsigned char *p1)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&hello_StubDesc,
                  (PFORMAT_STRING) &hello__MIDL_ProcFormatString.Format[294],
                  ( unsigned char * )&p1);
    
}


/* Standard interface: aux, ver. 1.0,
   GUID={0x23df7a88,0xf51b,0x43b2,{0xbe,0xd5,0x6c,0xdd,0xe3,0xf7,0xa8,0xbc}} */


extern const MIDL_SERVER_INFO aux_ServerInfo;

extern const RPC_DISPATCH_TABLE aux_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE aux___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x23df7a88,0xf51b,0x43b2,{0xbe,0xd5,0x6c,0xdd,0xe3,0xf7,0xa8,0xbc}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&aux_v1_0_DispatchTable,
    0,
    0,
    0,
    &aux_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE aux_v1_0_s_ifspec = (RPC_IF_HANDLE)& aux___RpcServerInterface;

extern const MIDL_STUB_DESC aux_StubDesc;

extern const EXPR_EVAL ExprEvalRoutines[];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const hello_MIDL_PROC_FORMAT_STRING hello__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure HelloProc */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszString */

/* 24 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 26 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 28 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Procedure Shutdown */

/* 30 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x1 ),	/* 1 */
/* 38 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Procedure BaseType */

/* 54 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 56 */	NdrFcLong( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x2 ),	/* 2 */
/* 62 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 64 */	NdrFcShort( 0x150 ),	/* 336 */
/* 66 */	NdrFcShort( 0x150 ),	/* 336 */
/* 68 */	0x40,		/* Oi2 Flags:  has ext, */
			0xc,		/* 12 */
/* 70 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBoolean */

/* 78 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 80 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 82 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter pByte */

/* 84 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 86 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 88 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pChar */

/* 90 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 92 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 94 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pDouble */

/* 96 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 98 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 100 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pFloat */

/* 102 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 104 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 106 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter pHyper */

/* 108 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 110 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 112 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pInt */

/* 114 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 116 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInt3264 */

/* 120 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 122 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLong */

/* 126 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 128 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pShort */

/* 132 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 134 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 136 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pSmall */

/* 138 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 140 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 142 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter pWchar_t */

/* 144 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 146 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 148 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Procedure UnionParamProc */

/* 150 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x3 ),	/* 3 */
/* 158 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 160 */	NdrFcShort( 0x6 ),	/* 6 */
/* 162 */	NdrFcShort( 0x6 ),	/* 6 */
/* 164 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 166 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Union */

/* 174 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 176 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 178 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Parameter sUtype */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Procedure UnionStructProc */

/* 192 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x4 ),	/* 4 */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x6 ),	/* 6 */
/* 206 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 210 */	NdrFcShort( 0x1 ),	/* 1 */
/* 212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter u1 */

/* 216 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 218 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 220 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 226 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Procedure EncapsulatedUnionProc */

/* 228 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x5 ),	/* 5 */
/* 236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 242 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 246 */	NdrFcShort( 0x1 ),	/* 1 */
/* 248 */	NdrFcShort( 0x1 ),	/* 1 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter encapsulatedUnion */

/* 252 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 254 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 256 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumProc */

/* 264 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x6 ),	/* 6 */
/* 272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 274 */	NdrFcShort( 0x1a ),	/* 26 */
/* 276 */	NdrFcShort( 0x1a ),	/* 26 */
/* 278 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEnumWeek */

/* 288 */	NdrFcShort( 0x2018 ),	/* Flags:  in, out, srv alloc size=8 */
/* 290 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 292 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Procedure DisplayString */

/* 294 */	0x34,		/* FC_CALLBACK_HANDLE */
			0x48,		/* Old Flags:  */
/* 296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x1,		/* 1 */
/* 310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p1 */

/* 318 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 320 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 322 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Procedure VaryingArrayProc */

/* 324 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x7 ),	/* 7 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x10 ),	/* 16 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	0x43,		/* Oi2 Flags:  srv must size, clt must size, has ext, */
			0x3,		/* 3 */
/* 340 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 342 */	NdrFcShort( 0x1 ),	/* 1 */
/* 344 */	NdrFcShort( 0x1 ),	/* 1 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lFirstElement */

/* 348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 350 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lChunkSize */

/* 354 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter achArray */

/* 360 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 364 */	NdrFcShort( 0xa2 ),	/* Type Offset=162 */

	/* Procedure ConformantArrayProc */

/* 366 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 376 */	NdrFcShort( 0x10 ),	/* 16 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	0x43,		/* Oi2 Flags:  srv must size, clt must size, has ext, */
			0x4,		/* 4 */
/* 382 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 384 */	NdrFcShort( 0x1 ),	/* 1 */
/* 386 */	NdrFcShort( 0x1 ),	/* 1 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lArraySize */

/* 390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 392 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter achArray */

/* 396 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter lMaxSize */

/* 402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter achArray2 */

/* 408 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 412 */	NdrFcShort( 0xbe ),	/* Type Offset=190 */

	/* Procedure PointerTypeProc */

/* 414 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x49,		/* Old Flags:  full ptr, */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x9 ),	/* 9 */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	NdrFcShort( 0x32 ),	/* 50 */
/* 426 */	NdrFcShort( 0x32 ),	/* 50 */
/* 428 */	0x43,		/* Oi2 Flags:  srv must size, clt must size, has ext, */
			0x3,		/* 3 */
/* 430 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReferenceChar */

/* 438 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 440 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 442 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pUniqueChar */

/* 444 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 448 */	NdrFcShort( 0xca ),	/* Type Offset=202 */

	/* Parameter pFullChar */

/* 450 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 452 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 454 */	NdrFcShort( 0xce ),	/* Type Offset=206 */

	/* Procedure InOutPipe */

/* 456 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0xa ),	/* 10 */
/* 464 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	0x48,		/* Oi2 Flags:  has pipes, has ext, */
			0x1,		/* 1 */
/* 472 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPipe */

/* 480 */	NdrFcShort( 0x11c ),	/* Flags:  pipe, in, out, simple ref, */
/* 482 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 484 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Procedure GetTime */

/* 486 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 496 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 498 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x24 ),	/* 36 */
/* 504 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 506 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 514 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 518 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

			0x0
        }
    };

static const hello_MIDL_TYPE_FORMAT_STRING hello__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  8 */	0x3,		/* FC_SMALL */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 12 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 16 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 20 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 22 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 24 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 26 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 28 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 30 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 32 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 34 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 36 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 38 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 40 */	0x5,		/* FC_WCHAR */
			0x5c,		/* FC_PAD */
/* 42 */	
			0x11, 0x0,	/* FC_RP */
/* 44 */	NdrFcShort( 0x2 ),	/* Offset= 2 (46) */
/* 46 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 48 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 50 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 52 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 54 */	NdrFcShort( 0x2 ),	/* Offset= 2 (56) */
/* 56 */	NdrFcShort( 0x4 ),	/* 4 */
/* 58 */	NdrFcShort( 0x3 ),	/* 3 */
/* 60 */	NdrFcLong( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 66 */	NdrFcLong( 0x1 ),	/* 1 */
/* 70 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 72 */	NdrFcLong( 0x2 ),	/* 2 */
/* 76 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 78 */	NdrFcShort( 0x0 ),	/* Offset= 0 (78) */
/* 80 */	
			0x11, 0x0,	/* FC_RP */
/* 82 */	NdrFcShort( 0x24 ),	/* Offset= 36 (118) */
/* 84 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 86 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 88 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 90 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 92 */	NdrFcShort( 0x2 ),	/* Offset= 2 (94) */
/* 94 */	NdrFcShort( 0x4 ),	/* 4 */
/* 96 */	NdrFcShort( 0x3 ),	/* 3 */
/* 98 */	NdrFcLong( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 104 */	NdrFcLong( 0x1 ),	/* 1 */
/* 108 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 110 */	NdrFcLong( 0x2 ),	/* 2 */
/* 114 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 116 */	NdrFcShort( 0x0 ),	/* Offset= 0 (116) */
/* 118 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* Offset= 0 (124) */
/* 126 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 128 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 130 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (84) */
/* 132 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 134 */	
			0x11, 0x0,	/* FC_RP */
/* 136 */	NdrFcShort( 0x2 ),	/* Offset= 2 (138) */
/* 138 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 142 */	NdrFcShort( 0x2 ),	/* 2 */
/* 144 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 148 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 150 */	NdrFcLong( 0x800 ),	/* 2048 */
/* 154 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 156 */	NdrFcShort( 0xffff ),	/* Offset= -1 (155) */
/* 158 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 160 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 162 */	
			0x1f,		/* FC_SMVARRAY */
			0x0,		/* 0 */
/* 164 */	NdrFcShort( 0x3e8 ),	/* 1000 */
/* 166 */	NdrFcShort( 0x3e8 ),	/* 1000 */
/* 168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 170 */	0x20,		/* Corr desc:  parameter,  */
			0x59,		/* FC_CALLBACK */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 176 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 178 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 180 */	NdrFcShort( 0x1 ),	/* 1 */
/* 182 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 184 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 186 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 188 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 190 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 192 */	NdrFcShort( 0x1 ),	/* 1 */
/* 194 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x57,		/* FC_ADD_1 */
/* 196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 198 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 200 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 202 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 204 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 206 */	
			0x14, 0x8,	/* FC_FP [simple_pointer] */
/* 208 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 210 */	
			0x11, 0x0,	/* FC_RP */
/* 212 */	NdrFcShort( 0x4 ),	/* Offset= 4 (216) */
/* 214 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 216 */	0xb5,		/* FC_PIPE */
			0x0,		/* 0 */
/* 218 */	NdrFcShort( 0xfffc ),	/* Offset= -4 (214) */
/* 220 */	NdrFcShort( 0x1 ),	/* 1 */
/* 222 */	NdrFcShort( 0x1 ),	/* 1 */
/* 224 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 226 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static void __RPC_USER hello_VaryingArrayProcExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        long lFirstElement;
        long lChunkSize;
        unsigned char ( *achArray )[ 1000 ];
        };
    #pragma pack( )
    struct _PARAM_STRUCT *pS	=	( struct _PARAM_STRUCT * )pStubMsg->StackTop;
    
    pStubMsg->Offset = pS->lFirstElement;
    pStubMsg->MaxCount = ( unsigned long ) ( pS->lChunkSize );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    hello_VaryingArrayProcExprEval_0000
    };


static const unsigned short hello_FormatStringOffsetTable[] =
    {
    0,
    30,
    54,
    150,
    192,
    228,
    264,
    324,
    366,
    414,
    456
    };


static const unsigned short _callbackhello_FormatStringOffsetTable[] =
    {
    294,
    };


static const MIDL_STUB_DESC hello_StubDesc = 
    {
    (void *)& hello___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    ExprEvalRoutines,
    0,
    hello__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

static const RPC_DISPATCH_FUNCTION hello_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE hello_v1_0_DispatchTable = 
    {
    11,
    (RPC_DISPATCH_FUNCTION*)hello_table
    };

static const SERVER_ROUTINE hello_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)HelloProc,
    (SERVER_ROUTINE)Shutdown,
    (SERVER_ROUTINE)BaseType,
    (SERVER_ROUTINE)UnionParamProc,
    (SERVER_ROUTINE)UnionStructProc,
    (SERVER_ROUTINE)EncapsulatedUnionProc,
    (SERVER_ROUTINE)EnumProc,
    (SERVER_ROUTINE)VaryingArrayProc,
    (SERVER_ROUTINE)ConformantArrayProc,
    (SERVER_ROUTINE)PointerTypeProc,
    (SERVER_ROUTINE)InOutPipe
    };

static const MIDL_SERVER_INFO hello_ServerInfo = 
    {
    &hello_StubDesc,
    hello_ServerRoutineTable,
    hello__MIDL_ProcFormatString.Format,
    hello_FormatStringOffsetTable,
    0,
    0,
    0,
    0};

static const unsigned short aux_FormatStringOffsetTable[] =
    {
    486
    };


static const MIDL_STUB_DESC aux_StubDesc = 
    {
    (void *)& aux___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    ExprEvalRoutines,
    0,
    hello__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

static const RPC_DISPATCH_FUNCTION aux_table[] =
    {
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE aux_v1_0_DispatchTable = 
    {
    1,
    (RPC_DISPATCH_FUNCTION*)aux_table
    };

static const SERVER_ROUTINE aux_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)GetTime
    };

static const MIDL_SERVER_INFO aux_ServerInfo = 
    {
    &aux_StubDesc,
    aux_ServerRoutineTable,
    hello__MIDL_ProcFormatString.Format,
    aux_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */


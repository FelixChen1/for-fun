#include <iostream>
#include <time.h>
#include "..\RPCInterface\hello.h"
#include "RPCServerImpl.h"

/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/
#define INCREMENT(X) if (X) { (*X)++; }

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}

void HelloProc(unsigned char * pszString)
{
	std::cout << pszString << std::endl;
}

void Shutdown(void)
{
    // callback first
    DisplayString(reinterpret_cast<unsigned char *>("Ther server is shutting down"));
	RPC_STATUS status;

	status = RpcMgmtStopServerListening(NULL);

	if (status)
	{
		exit(status);
	}

	status = RpcServerUnregisterIf(NULL, NULL, FALSE);

	if (status)
	{
		exit(status);
	}
}

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
    /* [out][in] */ wchar_t *pWchar_t)
{
    (*pBoolean) == TRUE ? (*pBoolean) = FALSE : (*pBoolean) = TRUE;
    INCREMENT(pByte)
    INCREMENT(pChar);
    INCREMENT(pDouble)
    INCREMENT(pFloat)
    INCREMENT(pHyper)
    INCREMENT(pInt)
    INCREMENT(pInt3264)
    INCREMENT(pLong)
    INCREMENT(pShort)
    INCREMENT(pSmall)
    INCREMENT(pWchar_t)
}

short UnionParamProc(
    /* [switch_is][out][in] */ DISCRIM_UNION_PARAM_TYPE *Union,
    /* [in] */ short sUtype)
{
    switch (sUtype)
    {
    case 0: { Union->sVal++;  break; }
    case 1: { Union->fVal++;  break; }
    case 2: { Union->chVal++; break; }
    }
    return sUtype;
}

short UnionStructProc(
    /* [out][in] */ DISCRIM_UNION_STRUCT_TYPE *u1)
{
    switch (u1->utype)
    {
    case 0: { u1->u.sVal++;  break; }
    case 1: { u1->u.fVal++;  break; }
    case 2: { u1->u.chVal++; break; }
    }
    return u1->utype;
}

long EncapsulatedUnionProc(
    /* [out][in] */ UNION_ENCAPSULATED *encapsulatedUnion)
{
    switch (encapsulatedUnion->uType)
    {
    case 1024: { encapsulatedUnion->uValue.f1++;  break; }
    case 2048: { encapsulatedUnion->uValue.d2++;  break; }
    }
    return encapsulatedUnion->uType;
}

void EnumProc(
    /* [out][in] */ ENUM_WEEK *pEnumWeek)
{
    (*pEnumWeek) = (ENUM_WEEK)((*pEnumWeek) + 1);
}

void VaryingArrayProc(
    /* [in] */ long lFirstElement,
    /* [in] */ long lChunkSize,
    /* [length_is][first_is][out][in] */ unsigned char achArray[1000])
{
    unsigned char tempChar;
    int first = lFirstElement;
    int last = lFirstElement + lChunkSize - 1;
    int count = lChunkSize;
    while(count > 1)
    {
        tempChar = achArray[first];
        achArray[first] = achArray[last];
        achArray[last] = tempChar;
        first++;
        last--;
        count -= 2;
    }
    achArray[lFirstElement + lChunkSize] = '0';
    lFirstElement--;
    lChunkSize--;
}

void ConformantArrayProc(
    long lArraySize,
    /* [size_is][out][in] */ unsigned char achArray[],
    long lMaxSize,
    /* [max_is][out][in] */ unsigned char achArray2[])
{
    unsigned char tempChar;
    int first = 0;
    int last = lArraySize - 1;
    int count = lArraySize;
    while (count > 1)
    {
        tempChar = achArray[first];
        achArray[first] = achArray[last];
        achArray[last] = tempChar;
        first++;
        last--;
        count -= 2;
    }

    first = 0;
    last = lMaxSize - 1;
    count = lMaxSize;
    while (count > 1)
    {
        tempChar = achArray2[first];
        achArray2[first] = achArray2[last];
        achArray2[last] = tempChar;
        first++;
        last--;
        count -= 2;
    }
}

void PointerTypeProc(
    /* [ref][out][in] */ unsigned char *pReferenceChar,
    /* [unique][out][in] */ unsigned char *pUniqueChar,
    /* [string][full][out][in] */ unsigned char *pFullChar)
{
    (*pReferenceChar)++;
    INCREMENT(pUniqueChar)
    INCREMENT(pFullChar)
}

void InOutPipe(CHAR_PIPE *pPipe)
{
    const int PIPE_TRANSFER_SIZE = 100; /* Transfer 100 pipe elements at one time */

    unsigned char local_pipe_buf[PIPE_TRANSFER_SIZE];

    for (int i = 0; i < PIPE_TRANSFER_SIZE; i++)
    {
        local_pipe_buf[i] = 99;
    }

    unsigned long actual_transfer_count = PIPE_TRANSFER_SIZE;

    // process InPipe
    while (actual_transfer_count > 0) /* Loop to get all the pipe data elements */
    {
        pPipe->pull(pPipe->state, local_pipe_buf, PIPE_TRANSFER_SIZE, &actual_transfer_count);
        /* process the elements */
        for (int i = 0; i < actual_transfer_count; i++)
        {
            local_pipe_buf[i]++;
        }
    }

    // process OutPipe
    int elementsToSend = PIPE_TRANSFER_SIZE;
    int index = 0;
    while (elementsToSend > 0) /* Loop to send pipe data elements */
    {
        elementsToSend = (index >= PIPE_TRANSFER_SIZE) ? 0 : PIPE_TRANSFER_SIZE;
        pPipe->push(pPipe->state, &(local_pipe_buf[index]), elementsToSend);
        index += elementsToSend;
    }
}

void GetTime(handle_t IDL_handle, long long *timeData)
{
    time(reinterpret_cast<time_t *>(timeData));
}

typedef struct
{
    FILE* hFile;
    char   achFile[256];
} FILE_CONTEXT_TYPE;

short RemoteOpen(PPCONTEXT_HANDLE_TYPE pphContext, unsigned char *pszFileName)
{
    FILE               *hFile;
    FILE_CONTEXT_TYPE  *pFileContext;
    const char *pcsFileName = reinterpret_cast<const char *>(pszFileName);

    if ((hFile = fopen(pcsFileName, "r")) == NULL)
    {
        *pphContext = (PCONTEXT_HANDLE_TYPE)NULL;
        return(-1);
    }
    else
    {
        pFileContext = (FILE_CONTEXT_TYPE *)MIDL_user_allocate(sizeof(FILE_CONTEXT_TYPE));
        pFileContext->hFile = hFile;
        // check if pszFileName is longer than 256 and if yes, return
        // an error
        size_t length = strlen(pcsFileName);
        strcpy_s(pFileContext->achFile, strlen(pcsFileName) + 1, pcsFileName);
        *pphContext = (PCONTEXT_HANDLE_TYPE)pFileContext;
        return(0);
    }
}

short RemoteRead(PCONTEXT_HANDLE_TYPE phContext, unsigned char achBuf[], short *pcbBuf)
{
    FILE_CONTEXT_TYPE *pFileContext;
    short bufSize = *pcbBuf;

    pFileContext = (FILE_CONTEXT_TYPE *)phContext;
    long pos = ftell(pFileContext->hFile);
    *pcbBuf = (short)fread(achBuf,
        sizeof(char),
        bufSize,
        pFileContext->hFile);
    pos = ftell(pFileContext->hFile);
    return *pcbBuf;
}

void RemoteClose(PPCONTEXT_HANDLE_TYPE pphContext)
{
    FILE_CONTEXT_TYPE *pFileContext;

    if (*pphContext == NULL)
    {
        //Log error, client tried to close a NULL handle.
        return;
    }
    pFileContext = (FILE_CONTEXT_TYPE *)*pphContext;

    fclose(pFileContext->hFile);
    MIDL_user_free(pFileContext);

    // This tells the run-time, when it is marshalling the out 
    // parameters, that the context handle has been closed normally.
    *pphContext = NULL;
}

void __RPC_USER PCONTEXT_HANDLE_TYPE_rundown(PCONTEXT_HANDLE_TYPE phContext)
{
    RemoteClose(&phContext);
}
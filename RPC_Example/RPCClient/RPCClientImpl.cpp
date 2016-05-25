#include <iostream>
#include"RPCClientImpl.h"

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

void DisplayString(unsigned char *p1)
{
    std::cout << p1 << std::endl;
}

#define BUF_SIZE 50
#define PIPE_SIZE 100
long *globalPipeData;
long globalBuffer[BUF_SIZE];

char pipeDataIndex; /* state variable */

void InPipeTest()
{
    std::cout << "========== InPipeTest ==========" << std::endl;
    LONG_PIPE inPipe;
    int i;
    globalPipeData = (long *)malloc(sizeof(long) * PIPE_SIZE);

    for (i = 0; i < PIPE_SIZE; i++)
    {
        globalPipeData[i] = 5;
    }

    pipeDataIndex = 0;
    inPipe.state = &pipeDataIndex;
    inPipe.pull = PipePull;
    inPipe.alloc = PipeAlloc;

    InPipe(inPipe); /* Make the rpc */

    free((void *)globalPipeData);
    std::cout << std::endl;

}//end SendLongs

void __RPC_USER PipeAlloc(char* stateInfo, unsigned long requestedSize, long **allocatedBuffer, unsigned long *allocatedSize)
{
    char *state = stateInfo;
    if (requestedSize > (BUF_SIZE*sizeof(long)))
    {
        *allocatedSize = BUF_SIZE * sizeof(long);
    }
    else
    {
        *allocatedSize = requestedSize;
    }
    *allocatedBuffer = globalBuffer;
} //end PipeAlloc

void __RPC_USER PipePull(char* stateInfo, long *inputBuffer, unsigned long maxBufSize, unsigned long *sizeToSend)
{
    small currentIndex;
    unsigned long i;
    small elementsToRead;
    char *state = stateInfo;

    currentIndex = *state;
    if (*state >= PIPE_SIZE)
    {
        *sizeToSend = 0; /* end of pipe data */
        *state = 0; /* Reset the state = global index */
    }
    else
    {
        if (currentIndex + maxBufSize > PIPE_SIZE)
            elementsToRead = PIPE_SIZE - currentIndex;
        else
            elementsToRead = maxBufSize;

        for (i = 0; i < elementsToRead; i++)
        {
            /*client sends data */
            inputBuffer[i] = globalPipeData[i + currentIndex];
        }

        *state += elementsToRead;
        *sizeToSend = elementsToRead;
    }
}//end PipePull

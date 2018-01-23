/* =============================================================================
 *	AUTHOR:SAIF ULLA BAIG
 *  Description: This is a C implementation for Thread m_thread1
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

/* Get access to any of the VDK features & datatypes used */
#include "m_thread1.h"
#include <stdio.h>

#pragma file_attr("OS_Component=Threads")
#pragma file_attr("Threads")

/*messege ques demonstration*/

VDK_ThreadID temp;
VDK_MessageID msg1;

void
m_thread1_RunFunction(void **inPtr)
{
    /* Put the thread's "main" Initialization HERE */


    
    temp=VDK_CreateThread(kmthread2);
        printf("thread ID=%x\n",temp);
        

    unsigned char str1[20];
    
    
    
    msg1=VDK_CreateMessage(1,sizeof(str1),&str1[0]);
	VDK_SetMessagePayload(msg1,1,sizeof(str1),"hello this is msg1 from thread2");           
        
    while (1)
    {
        /* Put the thread's "main" body HERE */
		/*****posting a message at every 1 second at channel 15*/		
		printf("HELLO RTOS\n");
		VDK_PostMessage(temp,msg1,VDK_kMsgChannel15);
		VDK_Sleep(1000);
        /* Use a "break" instruction to exit the "while (1)" loop */
    }

    /* Put the thread's exit from "main" HERE */
    /* A thread is automatically Destroyed when it exits its run function */
}

int
m_thread1_ErrorFunction(void **inPtr)
{
    /* TODO - Put this thread's error handling code HERE */

      /* The default ErrorHandler goes to KernelPanic */

	VDK_CThread_Error(VDK_GetThreadID());
	return 0;
}

void
m_thread1_InitFunction(void **inPtr, VDK_ThreadCreationBlock const *pTCB)
{
    /* Put code to be executed when this thread has just been created HERE */

    /* This routine does NOT run in new thread's context.  Any non-static thread
     *   initialization should be performed at the beginning of "Run()."
     */
}

void
m_thread1_DestroyFunction(void **inPtr)
{
    /* Put code to be executed when this thread is destroyed HERE */

    /* This routine does NOT run in the thread's context.  Any VDK API calls
     *   should be performed at the end of "Run()."
     */
}

/* ========================================================================== */


/*

    // This will work

    void myMalloc(void** ptr, int size) {

      *ptr = malloc(size);

      return;

    }

    int* ptr = NULL;

    myMalloc((void**) &ptr, size);

    ptr[0] = 0;
    */

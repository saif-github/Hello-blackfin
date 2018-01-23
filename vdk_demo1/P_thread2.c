/* =============================================================================
 *
 *  Description: This is a C implementation for Thread P_thread2
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

/* Get access to any of the VDK features & datatypes used */
#include "P_thread2.h"
#include <stdio.h>

#pragma file_attr("OS_Component=Threads")
#pragma file_attr("Threads")

void
P_thread2_RunFunction(void **inPtr)
{
    /* Put the thread's "main" Initialization HERE */

    while (1)
    {
        /* Put the thread's "main" body HERE */
      	VDK_Sleep(500);
        printf("HELLO BLACKFIN 1\n");
		VDK_PostSemaphore(kP_sem);
		VDK_Sleep(500);
        printf("HELLO BLACKFIN 2\n");
		VDK_PostSemaphore(kP_sem);
        /* Use a "break" instruction to exit the "while (1)" loop */
    }

    /* Put the thread's exit from "main" HERE */
    
    /* A thread is automatically Destroyed when it exits its run function */
}

int
P_thread2_ErrorFunction(void **inPtr)
{

    /* TODO - Put this thread's error handling code HERE */

      /* The default ErrorHandler goes to KernelPanic */

	VDK_CThread_Error(VDK_GetThreadID());
	return 0;
}

void
P_thread2_InitFunction(void **inPtr, VDK_ThreadCreationBlock const *pTCB)
{
		unsigned int t_id=0;
    /* Put code to be executed when this thread has just been created HERE */
        t_id=VDK_GetThreadID();
        printf("Entered thread 2\n");
		printf("thread ID=%x\n",t_id);
    /* This routine does NOT run in new thread's context.  Any non-static thread
     *   initialization should be performed at the beginning of "Run()."
     */
}

void
P_thread2_DestroyFunction(void **inPtr)
{
    /* Put code to be executed when this thread is destroyed HERE */

    /* This routine does NOT run in the thread's context.  Any VDK API calls
     *   should be performed at the end of "Run()."
     */
}

/* ========================================================================== */

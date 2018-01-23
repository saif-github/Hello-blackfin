/* =============================================================================
 *
 *  Description: This is a C implementation for Thread thread_test1
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

/* Get access to any of the VDK features & datatypes used */
#include "thread_test1.h"

#pragma file_attr("OS_Component=Threads")
#pragma file_attr("Threads")

void
thread_test1_RunFunction(void **inPtr)
{
    /* Put the thread's "main" Initialization HERE */

    while (1)
    {
        /* Put the thread's "main" body HERE */

        /* Use a "break" instruction to exit the "while (1)" loop */
    }

    /* Put the thread's exit from "main" HERE */
    /* A thread is automatically Destroyed when it exits its run function */
}

int
thread_test1_ErrorFunction(void **inPtr)
{

    /* TODO - Put this thread's error handling code HERE */

      /* The default ErrorHandler goes to KernelPanic */

	VDK_CThread_Error(VDK_GetThreadID());
	return 0;
}

void
thread_test1_InitFunction(void **inPtr, VDK_ThreadCreationBlock const *pTCB)
{
    /* Put code to be executed when this thread has just been created HERE */

    /* This routine does NOT run in new thread's context.  Any non-static thread
     *   initialization should be performed at the beginning of "Run()."
     */
}

void
thread_test1_DestroyFunction(void **inPtr)
{
    /* Put code to be executed when this thread is destroyed HERE */

    /* This routine does NOT run in the thread's context.  Any VDK API calls
     *   should be performed at the end of "Run()."
     */
}

/* ========================================================================== */

/* =============================================================================
 *
 *  Description: This is a C implementation for Thread mthread2
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

/* Get access to any of the VDK features & datatypes used */
#include "mthread2.h"
#include <stdio.h>

#pragma file_attr("OS_Component=Threads")
#pragma file_attr("Threads")

//extern VDK_ThreadID temp;
extern VDK_MessageID msg1;

void
mthread2_RunFunction(void **inPtr)
{
    /* Put the thread's "main" Initialization HERE */
    unsigned int temp2,temp4;
    int temp3=0;
    //VDK_MessageID msg1=1;
  printf("Entered thread 2 again\n");
	unsigned char *ptr = NULL;	

    while (1)
    {
        /* Put the thread's "main" body HERE */
			//VDK_Sleep(1);
			printf("HELLO RTOS2\n");
		
		temp4=VDK_PendMessage(VDK_kMsgChannel15,2000);
		
		printf("%x\n",temp4);
		
		VDK_GetMessagePayload(msg1,&temp3,&temp2,(void **)&ptr);
		printf("%s\n",&ptr[0]);
		        		
        /* Use a "break" instruction to exit the "while (1)" loop */
    }

    /* Put the thread's exit from "main" HERE */
    /* A thread is automatically Destroyed when it exits its run function */
}

int
mthread2_ErrorFunction(void **inPtr)
{

    /* TODO - Put this thread's error handling code HERE */

      /* The default ErrorHandler goes to KernelPanic */

	VDK_CThread_Error(VDK_GetThreadID());
	return 0;
}

void
mthread2_InitFunction(void **inPtr, VDK_ThreadCreationBlock const *pTCB)
{
    /* Put code to be executed when this thread has just been created HERE */

    /* This routine does NOT run in new thread's context.  Any non-static thread
     *   initialization should be performed at the beginning of "Run()."
     */
}

void
mthread2_DestroyFunction(void **inPtr)
{
    /* Put code to be executed when this thread is destroyed HERE */

    /* This routine does NOT run in the thread's context.  Any VDK API calls
     *   should be performed at the end of "Run()."
     */
}

/* ========================================================================== */

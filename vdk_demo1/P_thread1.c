/* =============================================================================
 *
 *  Description: This is a C implementation for Thread P_thread1
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

/* Get access to any of the VDK features & datatypes used */
#include "P_thread1.h"
#include  <stdio.h>

#pragma file_attr("OS_Component=Threads")
#pragma file_attr("Threads")

void
P_thread1_RunFunction(void **inPtr)
{
    /* Put the thread's "main" Initialization HERE */
	unsigned int temp=0;
	
    temp=VDK_CreateThread(kP_thread2);
    
    printf("thread ID=%x\n",temp);
    
    printf("Entered thread 1 again\n");
    
    while (1)
    {
        /* Put the thread's "main" body HERE */
        VDK_PendSemaphore(kP_sem,510);
        //VDK_Sleep(500);
		printf("HELLO RTOS\n");
        /* Use a "break" instruction to exit the "while (1)" loop */
    }

    /* Put the thread's exit from "main" HERE */
    /* A thread is automatically Destroyed when it exits its run function */
}

int
P_thread1_ErrorFunction(void **inPtr)
{

    /* TODO - Put this thread's error handling code HERE */

      /* The default ErrorHandler goes to KernelPanic */

	VDK_CThread_Error(VDK_GetThreadID());
	return 0;
}

void
P_thread1_InitFunction(void **inPtr, VDK_ThreadCreationBlock const *pTCB)
{
	
		unsigned int t_id=0;
		//unsigned int sem_stat=0;
	
    /* Put code to be executed when this thread has just been created HERE */
        printf("HELLO RTOS\n");
        printf("Entered thread 1\n");	
        t_id=VDK_GetThreadID();
        printf("thread ID=%x\n",t_id);

        
        /*create semaphore*/
	/*	sem_stat=VDK_CreateSemaphore(0,2,0,0);
		
		if(sem_stat==kP_sem){
			printf("semaphore created\n");
		}
		else{
			printf("semaphore init failed\n");
		}*/
		
	//	temp=VDK_GetPriority(t_id);
		
	//	printf("thread ID=%x\n,t_id");
    /* This routine does NOT run in new thread's context.  Any non-static thread
     *   initialization should be performed at the beginning of "Run()."
     */
}

void
P_thread1_DestroyFunction(void **inPtr)
{
    /* Put code to be executed when this thread is destroyed HERE */

    /* This routine does NOT run in the thread's context.  Any VDK API calls
     *   should be performed at the end of "Run()."
     */
}

/* ========================================================================== */

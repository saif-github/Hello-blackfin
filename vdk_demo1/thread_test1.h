/* =============================================================================
 *
 *  Description: This is a C++ to C Thread Header file for Thread thread_test1
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

#ifndef _thread_test1_H_
#define _thread_test1_H_

#ifndef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress: 177,401,451,826,831,1462)
#endif

#include "VDK.h"
#ifndef _MISRA_RULES
#pragma diag(pop)
#endif

#ifdef __ECC__	/* for C/C++ access */
#ifdef __cplusplus
extern "C" void thread_test1_InitFunction(void**, VDK::Thread::ThreadCreationBlock const *);
#else
extern "C" void thread_test1_InitFunction(void** inPtr, VDK_ThreadCreationBlock const * pTCB);
#endif
extern "C" void thread_test1_DestroyFunction(void** inPtr);
extern "C" int  thread_test1_ErrorFunction(void** inPtr);
extern "C" void thread_test1_RunFunction(void** inPtr);
#endif /* __ECC__ */

#ifdef __cplusplus
#include <new>

class thread_test1_Wrapper : public VDK::Thread
{
public:
    thread_test1_Wrapper(VDK::ThreadCreationBlock &t)
        : VDK::Thread(t)
    { thread_test1_InitFunction(&m_DataPtr, &t); }

    ~thread_test1_Wrapper()
    { thread_test1_DestroyFunction(&m_DataPtr); }

    int ErrorHandler()
    { 
      return thread_test1_ErrorFunction(&m_DataPtr);
     }

    void Run()
    { thread_test1_RunFunction(&m_DataPtr); }

    static VDK::Thread* Create(VDK::Thread::ThreadCreationBlock &t)
    { return new (t) thread_test1_Wrapper(t); }
};

#endif /* __cplusplus */
#endif /* _thread_test1_H_ */

/* ========================================================================== */

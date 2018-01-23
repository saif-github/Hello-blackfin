/* =============================================================================
 *
 *  Description: This is a C++ to C Thread Header file for Thread P_thread1
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

#ifndef _P_thread1_H_
#define _P_thread1_H_

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
extern "C" void P_thread1_InitFunction(void**, VDK::Thread::ThreadCreationBlock const *);
#else
extern "C" void P_thread1_InitFunction(void** inPtr, VDK_ThreadCreationBlock const * pTCB);
#endif
extern "C" void P_thread1_DestroyFunction(void** inPtr);
extern "C" int  P_thread1_ErrorFunction(void** inPtr);
extern "C" void P_thread1_RunFunction(void** inPtr);
#endif /* __ECC__ */

#ifdef __cplusplus
#include <new>

class P_thread1_Wrapper : public VDK::Thread
{
public:
    P_thread1_Wrapper(VDK::ThreadCreationBlock &t)
        : VDK::Thread(t)
    { P_thread1_InitFunction(&m_DataPtr, &t); }

    ~P_thread1_Wrapper()
    { P_thread1_DestroyFunction(&m_DataPtr); }

    int ErrorHandler()
    { 
      return P_thread1_ErrorFunction(&m_DataPtr);
     }

    void Run()
    { P_thread1_RunFunction(&m_DataPtr); }

    static VDK::Thread* Create(VDK::Thread::ThreadCreationBlock &t)
    { return new (t) P_thread1_Wrapper(t); }
};

#endif /* __cplusplus */
#endif /* _P_thread1_H_ */

/* ========================================================================== */

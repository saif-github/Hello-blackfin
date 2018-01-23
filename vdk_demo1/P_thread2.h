/* =============================================================================
 *
 *  Description: This is a C++ to C Thread Header file for Thread P_thread2
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

#ifndef _P_thread2_H_
#define _P_thread2_H_

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
extern "C" void P_thread2_InitFunction(void**, VDK::Thread::ThreadCreationBlock const *);
#else
extern "C" void P_thread2_InitFunction(void** inPtr, VDK_ThreadCreationBlock const * pTCB);
#endif
extern "C" void P_thread2_DestroyFunction(void** inPtr);
extern "C" int  P_thread2_ErrorFunction(void** inPtr);
extern "C" void P_thread2_RunFunction(void** inPtr);
#endif /* __ECC__ */

#ifdef __cplusplus
#include <new>

class P_thread2_Wrapper : public VDK::Thread
{
public:
    P_thread2_Wrapper(VDK::ThreadCreationBlock &t)
        : VDK::Thread(t)
    { P_thread2_InitFunction(&m_DataPtr, &t); }

    ~P_thread2_Wrapper()
    { P_thread2_DestroyFunction(&m_DataPtr); }

    int ErrorHandler()
    { 
      return P_thread2_ErrorFunction(&m_DataPtr);
     }

    void Run()
    { P_thread2_RunFunction(&m_DataPtr); }

    static VDK::Thread* Create(VDK::Thread::ThreadCreationBlock &t)
    { return new (t) P_thread2_Wrapper(t); }
};

#endif /* __cplusplus */
#endif /* _P_thread2_H_ */

/* ========================================================================== */

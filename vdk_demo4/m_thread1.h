/* =============================================================================
 *
 *  Description: This is a C++ to C Thread Header file for Thread m_thread1
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

#ifndef _m_thread1_H_
#define _m_thread1_H_

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
extern "C" void m_thread1_InitFunction(void**, VDK::Thread::ThreadCreationBlock const *);
#else
extern "C" void m_thread1_InitFunction(void** inPtr, VDK_ThreadCreationBlock const * pTCB);
#endif
extern "C" void m_thread1_DestroyFunction(void** inPtr);
extern "C" int  m_thread1_ErrorFunction(void** inPtr);
extern "C" void m_thread1_RunFunction(void** inPtr);
#endif /* __ECC__ */

#ifdef __cplusplus
#include <new>

class m_thread1_Wrapper : public VDK::Thread
{
public:
    m_thread1_Wrapper(VDK::ThreadCreationBlock &t)
        : VDK::Thread(t)
    { m_thread1_InitFunction(&m_DataPtr, &t); }

    ~m_thread1_Wrapper()
    { m_thread1_DestroyFunction(&m_DataPtr); }

    int ErrorHandler()
    { 
      return m_thread1_ErrorFunction(&m_DataPtr);
     }

    void Run()
    { m_thread1_RunFunction(&m_DataPtr); }

    static VDK::Thread* Create(VDK::Thread::ThreadCreationBlock &t)
    { return new (t) m_thread1_Wrapper(t); }
};

#endif /* __cplusplus */
#endif /* _m_thread1_H_ */

/* ========================================================================== */

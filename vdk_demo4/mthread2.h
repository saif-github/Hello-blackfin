/* =============================================================================
 *
 *  Description: This is a C++ to C Thread Header file for Thread mthread2
 *
 * -----------------------------------------------------------------------------
 *  Comments:
 *
 * ===========================================================================*/

#ifndef _mthread2_H_
#define _mthread2_H_

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
extern "C" void mthread2_InitFunction(void**, VDK::Thread::ThreadCreationBlock const *);
#else
extern "C" void mthread2_InitFunction(void** inPtr, VDK_ThreadCreationBlock const * pTCB);
#endif
extern "C" void mthread2_DestroyFunction(void** inPtr);
extern "C" int  mthread2_ErrorFunction(void** inPtr);
extern "C" void mthread2_RunFunction(void** inPtr);
#endif /* __ECC__ */

#ifdef __cplusplus
#include <new>

class mthread2_Wrapper : public VDK::Thread
{
public:
    mthread2_Wrapper(VDK::ThreadCreationBlock &t)
        : VDK::Thread(t)
    { mthread2_InitFunction(&m_DataPtr, &t); }

    ~mthread2_Wrapper()
    { mthread2_DestroyFunction(&m_DataPtr); }

    int ErrorHandler()
    { 
      return mthread2_ErrorFunction(&m_DataPtr);
     }

    void Run()
    { mthread2_RunFunction(&m_DataPtr); }

    static VDK::Thread* Create(VDK::Thread::ThreadCreationBlock &t)
    { return new (t) mthread2_Wrapper(t); }
};

#endif /* __cplusplus */
#endif /* _mthread2_H_ */

/* ========================================================================== */

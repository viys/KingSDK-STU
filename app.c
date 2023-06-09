#include "app.h"
#include "uart.h"

/* 定义必要全局变量 */
THREAD_ATTR_S threadAttr;
uint32 writeLen = 0;

/* 线程ID */
THREAD_HANDLE AppTaskStartThreadH = NULL;
THREAD_HANDLE TH1ThreadH = NULL;
THREAD_HANDLE TH2ThreadH = NULL;

/*
 * 线程简单配置函数
 * 在使用此函数时需要创建一个名为threadAttr，类型为THREAD_ATTR_S的全局变量
 */

THREAD_ATTR_S* KING_Thread_Config(THREAD_ENTRY_FUN fun,void* param,THREAD_PRIORIT_E priority,uint32 stackSize)
{
    /* 清空线程配置指针 */
    memset(&threadAttr, 0x00, sizeof(THREAD_ATTR_S));

    /* 线程配置 */
    threadAttr.fun = fun;
    threadAttr.param = param;
    threadAttr.priority = priority;
    threadAttr.stackSize = stackSize;
    

    /* 返回线程配置指针地址 */
    return &threadAttr;
}

/*
 * 线程高级配置函数
 */
THREAD_ATTR_S* KING_Thread_ConfigA(uint32 autoStart,THREAD_ENTRY_FUN fun,void* param,uint32 preemption,
                                  THREAD_PRIORIT_E priority,uint32 queueNum,uint32 stackSize)
{
    /* 清空线程配置指针 */
    memset(&threadAttr, 0x00, sizeof(THREAD_ATTR_S));

    /* 线程配置 */
    threadAttr.stackSize = stackSize;
    threadAttr.queueNum = queueNum;
    threadAttr.preemption = preemption;
    threadAttr.priority = priority;
    threadAttr.autoStart = autoStart;
    threadAttr.fun = fun;
    threadAttr.param = param;

    /* 返回线程配置指针地址 */
    return &threadAttr;
}


/* 任务1 */
void th1(void *param)
{

    while(1){
        DBG_U2_Send("th1 running...\r\n");
        KING_Sleep(1000);
    }
}

/* 任务2 */
void th2(void *param)
{

    while(1){
        DBG_U2_Send("th2 running...\r\n");
        KING_Sleep(1000);
    }
}

void AppTaskStart(void *param)
{
    int ret = 0;

    /* 创建任务1 */
    ret = KING_ThreadCreate("th1",KING_Thread_Config(th1,NULL,3,1024),&TH1ThreadH);
    if(ret != 0){
        LogPrintf("KING_ThreadCreate() AppTaskStart Fail!");
        DBG_U2_Send("KING_ThreadCreate() AppTaskStart Fail!\r\n");
    }

    /* 创建任务2 */
    ret = KING_ThreadCreate("th2",KING_Thread_Config(th2,NULL,3,1024),&TH2ThreadH);
    if(ret != 0){
        LogPrintf("KING_ThreadCreate() th1 Fail!");
        DBG_U2_Send("KING_ThreadCreate() th2 Fail!\r\n");
    }

    KING_ThreadExit();
}



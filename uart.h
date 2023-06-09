#ifndef __UART_H
#define __UART_H

/*******************************************************************************
 ** MACROS
 ******************************************************************************/
#define LogPrintf(fmt, args...)    do { KING_SysLog("uart: "fmt, ##args); } while(0)

#define UART_BUF_MAX_LEN 128

extern uint8 U2_TxBuff[1000];

void DBG_U2_Send(char *format,...);
int Uart2_Init(void);



#endif /* __UART_H */

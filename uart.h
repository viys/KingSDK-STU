#ifndef __UART_H
#define __UART_H


extern uint8 U2_TxBuff[1000];

void DBG_U2_Send(char *format,...);
int Uart2_Init(void);



#endif /* __UART_H */

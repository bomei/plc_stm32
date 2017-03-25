#include "led.h"
#include "delay.h"
#include "sys.h"
#include "bolib.h"
#include "string.h"
//ALIENTEK Mini STM32开发板范例代码3
//串口实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
 int main(void)
 {	
	u8 t;
	u8 len;	
	u16 times=0; 
	char h[5]={0xaa,0xaa,0xaa,0xaa,0xaa};
	delay_init();	    	 //延时函数初始化	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	uart1_init(9600);	 //串口初始化为9600
	//uart2_init(9600);
	LED_Init();		  	 //初始化与LED连接的硬件接口
	delay_ms(100);
	USART1_send_buf("uart1 hahah\r\n");
	//USART1_send_buf(h);
	//USART2_send_buf("uart2 hahah\r\n");
	//USART2_send_buf(h);
	USART1_send_buf("\r\n您发送的消息为:\r\n");
	while(1)
	{
		if(USART1_RX_STA&0x8000)
		{					   
			len=USART1_RX_STA&0x3fff;//得到此次接收到的数据长度
			USART1_send_buf("\r\n您发送的消息为:\r\n");
			USART1_send_buf((char *)USART1_RX_BUF);
			//USART2_send_buf((char *)USART1_RX_BUF);
			strcpy(USART1_RX_BUF,"\0");
			USART1_RX_STA=0;
		}
		else if(USART2_RX_STA&0x8000){
			len=USART2_RX_STA&0x3fff;//得到此次接收到的数据长度
			USART1_send_buf("\r\n您接接收的消息为:\r\n");
			USART1_send_buf((char *)USART2_RX_BUF);
			strcpy(USART2_RX_BUF,"\0");
			USART2_RX_STA=0;
		}
		else
		{

			delay_ms(10);   
		}
	}	 
}



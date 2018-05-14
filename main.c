#include "main.h"

int main(void)
{
#if UART_MODE == INTERRUPT	
	int counter = 0;
	
	put("\r\nHello World! UART Lab using Interrupt mode\r\n");
	
	EnableInterrupts;
	enable_irq(INT_UART0 -16);
	set_irq_priority((INT_UART0 -16), 2);
	
	while(TRUE)
	{
		counter++;
		if(counter >= DLY)
		{
			GREEN_TOGGLE;
			counter = 0;
		}
	}
#else
	char ch;
	
	put("\r\nHello World! UART Lab using Polling mode\r\n");
	
	while(TRUE)
	{
		ch = in_char();
		out_char(ch);
		BLUE_TOGGLE;
	}
#endif
	
	return 0;
}

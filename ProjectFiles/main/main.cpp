#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include <string>
#include <iostream>
#include <cstring>

#define LED_GPIO GPIO_NUM_2
#define UART_PORT_NUM UART_NUM_0
#define RX_BUFFER_SIZE (1024)
#define TX_BUFFER_SIZE (1024)
#define QUEUE_SIZE (0)
#define UART_QUEUE (NULL)
#define ALLO_INTERUPT (0)
#define ticks_to_wait (1000)




extern "C" void app_main() {



   uart_driver_install(UART_PORT_NUM , RX_BUFFER_SIZE , TX_BUFFER_SIZE, QUEUE_SIZE, UART_QUEUE, ALLO_INTERUPT );
   
  
   
   
   char rx_buf[RX_BUFFER_SIZE];
   void* Wsrc = rx_buf;
   uint32_t len = RX_BUFFER_SIZE;
   int cat = uart_read_bytes(UART_PORT_NUM, Wsrc, len, ticks_to_wait );
   
   
   if (cat > 0){
      std::cout << "ping recieved waiting for esp32 to send 'pong' " << std::endl;
    
      if ( cat >= 4 && memcmp(rx_buf, "ping", 4) == 0)
      {
         std::cout << "ping recieved waiting for esp32 to send 'pong' " << std::endl;
          const std::string pong = " pong ";
         uart_write_bytes(UART_PORT_NUM, pong.c_str() , pong.length() );

      }else{
         std::cout << " hmm ping was not sent so I will not send back pong " << std::endl;
      }

   }else if (cat == 0)
   {
      std::cout << "timeout" << std::endl;
   }else{
          std::cout << "error" << std::endl;

   }
   
    


}

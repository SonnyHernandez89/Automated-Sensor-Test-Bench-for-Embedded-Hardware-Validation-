#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include <string>
#include <iostream>
#include <cstring>
#include "TestDirectory.h"

#define LED_GPIO GPIO_NUM_2
#define UART_PORT_NUM UART_NUM_0
#define RX_BUFFER_SIZE (1024)
#define TX_BUFFER_SIZE (1024)
#define QUEUE_SIZE (0)
#define UART_QUEUE (NULL)
#define ALLO_INTERUPT (0)
#define ticks_to_wait pdMS_TO_TICKS(10000)

extern "C" void app_main(){

    uart_driver_install(UART_PORT_NUM , RX_BUFFER_SIZE , TX_BUFFER_SIZE, QUEUE_SIZE, UART_QUEUE, ALLO_INTERUPT );
    std::cout << " Welcome to Automated Sensor Test Bench for Embedded Hardware Validation " << std::endl;
    std::cout << "Please Select a test to run below (enter test number i.e 'T001')" << std::endl;
    std::cout << std::endl;
    std::cout << "T001 Ping-Pong (computer to esp-32 communication test)" <<std::endl;
    std::cout << "T002 I2C (ESP-32 can detect a sensor)" <<std::endl;



    char rx_buf[RX_BUFFER_SIZE];
   void* Wsrc = rx_buf;
   uint32_t len = RX_BUFFER_SIZE;
   int option = uart_read_bytes(UART_PORT_NUM, Wsrc, len, ticks_to_wait );



    
    std::string PingPong = "T001";
    std::string inter2Ciruit = "T002";
    
 if ( option >= 4 && memcmp(rx_buf, "T001", 4) == 0){
         std::cout << "Test T001 confirmed running test case..." << std::endl;
         Test1(); 
      }else if ( option >= 4 && memcmp(rx_buf, "T002", 4) == 0)
      {
        std::cout << "Test T002 confirmed running test case..." << std::endl;
         Test2();
      }
      
      else{

        std::cout << "Test Case not selected" << std::endl;

      }

   
   
   
  
    
    
    

}
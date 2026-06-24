#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include <string>
#include <iostream>
#include <cstring>
#include "TestDirectory.h"
#include "driver/i2c_master.h"


#define LED_GPIO GPIO_NUM_2
#define UART_PORT_NUM UART_NUM_0
#define RX_BUFFER_SIZE (1024)
#define TX_BUFFER_SIZE (1024)
#define QUEUE_SIZE (0)
#define UART_QUEUE (NULL)
#define ALLO_INTERUPT (0)
#define ticks_to_wait pdMS_TO_TICKS(10000)
#define SCL_GPIO_NUM gpio_num_t(22)
#define SDA_GPIO_NUM gpio_num_t(21)


void Test2(){



i2c_master_bus_config_t i2c_configuration = {};

i2c_configuration.i2c_port = -1;
i2c_configuration.sda_io_num = SDA_GPIO_NUM;
i2c_configuration.scl_io_num = SCL_GPIO_NUM;
i2c_configuration.clk_source = I2C_CLK_SRC_DEFAULT;
i2c_configuration.glitch_ignore_cnt = 7;

i2c_master_bus_handle_t bus_handle;
i2c_new_master_bus(&i2c_configuration, &bus_handle);

std::cout << "T002 has been selected please wait while the register is obtain" << std::endl;
int ms_timeout = 10000;

for (uint16_t address = 0; address < 127; address++)
{
    esp_err_t addy_check = i2c_master_probe(bus_handle, address, ms_timeout );
    if (addy_check == ESP_OK)
    {
        std::cout << "ADDRESS CAUGHT : "  << std::hex << address << std::endl;
        break;

    } else if (addy_check == ESP_ERR_NOT_FOUND && address == 126)
    {
        std::cout << " hmmm something isn't right register not found " << std::endl;

    }else if (addy_check == ESP_ERR_TIMEOUT && address == 126)
    {
        std::cout << " ERROR TIME RAN OUT REGISTER COULD NOTBE FOUND WITHIN THE ALLOCATED TIME CURRENT TIME SET :  " << ms_timeout << std::endl;
    }
    
    
    
}






}
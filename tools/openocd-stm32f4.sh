#!/bin/bash

openocd -f interface/stlink-v2.cfg -f target/stm32f4x_stlink.cfg
#openocd -f interface/stlink-v2.cfg -f target/stm32f4x_stlink.cfg -c "stm32f4x.cpu configure -rtos auto;"


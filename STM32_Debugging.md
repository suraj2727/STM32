**STM32 Debugging with OpenOCD and GDB**

Follow these steps to debug your STM32 microcontroller using OpenOCD and GDB:

### **Step 1: Start OpenOCD Server**
Open Command Prompt and run:
sh
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg

This will initialize OpenOCD and set up a GDB server.

### **Step 2: Open GDB and Connect to Target**
Open another Command Prompt and run:
sh
arm-none-eabi-gdb your.elf

Then, in GDB, connect to the OpenOCD server:
sh
target remote localhost:3333


### **Step 3: Reset and Halt the Target**
To reset and halt the microcontroller, enter:
sh
monitor reset halt


### **Step 4: Flash the Firmware (if needed)**
Erase flash memory:
sh
monitor flash erase_sector 0 0 last

Then load the firmware:
sh
load


### **Step 5: Start Debugging**
Set a breakpoint at the main function:
sh
break main

Run the program:
sh
continue


### **Additional Debugging Commands**
- Read memory at an address:
  
sh
  monitor mdw 0x08000000

- Modify registers:
  
sh
  set $pc = 0x08000000

- Reset and reinitialize:
  
sh
  monitor reset init


### **Step 6: Exiting Debugging**
To exit GDB:
sh
quit
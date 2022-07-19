# This is a makefile

OBJECTS=main.o
APPL = APPL
GCC_DIR = MSP-GCC/bin
INCLUDES = include/
LINKER_FILES = linker/

DEVICE = msp430g2553
CC = $(GCC_DIR)/msp430-elf-gcc
CFLAGS = -I $(INCLUDES) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(LINKER_FILES) -T $(LINKER_FILES)lnk_msp430g2553.cmd

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) src/Gpio_Driver.c main.c -o $(APPL).out -v

#--------------------------------------------------------------------------------
# Simple makefile for MSP build system
#
# Use: make [targets] [TBD]
#
# Targets:
#		TBD
#
#--------------------------------------------------------------------------------
include sources.mk

# PATHS
INCLUDES = include/
GCC_DIR = MSP-GCC/bin
LINKER_FILES = linker/

# Overrides
DEVICE = msp430g2553

# Compile definitions
CC = $(GCC_DIR)/msp430-elf-gcc
LD = lnk_msp430g2553.cmd
CSTD = c99
BASENAME = APPL
TARGET = $(BASENAME).out
LDFLAGS = -L $(LINKER_FILES) -T $(LINKER_FILES)$(LD)
CFLAGS = -I $(INCLUDES) -mmcu=$(DEVICE) -O2 -g -Wall -std=$(CSTD) -v

# Output to log
LOG = 2>> build/build.log

$(shell mkdir build)

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@ $(LOG)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o build/$@ $(LOG)

clean:
	rm -f $(OBJS)

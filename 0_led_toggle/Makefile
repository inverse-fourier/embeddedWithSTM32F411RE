# Toolchain definitions
CC = arm-none-eabi-gcc
PROJECT = 0_led_toggle
BUILD_DIR = build
SIZE = arm-none-eabi-size
OBJCOPY = arm-none-eabi-objcopy

# Script paths
LDSCRIPT = ../linkerScript/STM32F411RETX_FLASH.ld
STARTUP_SCRIPT = ../startupScript/startup_stm32f411retx.s

# CPU architecture settings for STM32F411RE
CPU = -mcpu=cortex-m4
# Note: FPU flags (-mfpu=fpv4-sp-d16 -mfloat-abi=hard) can be added here if floating point math is used
#FPU = -mfpu=fpv4-sp-d16
#FLOAT-ABI = -mfloat-abi=hard
#MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)
MCU = $(CPU) -mthumb


# Compiler flags
#===============================================
# -Wall		-	Show all compiler warnings to help catch potential issues
# -g 		-	Include debugging information in the output for GDB
# -O0		-	Optimization level 0 (no optimization, better for debugging)
# -std=gnu11	-	Use the GNU C11 standard for C code
#===============================================
CFLAGS = $(MCU) -Wall -g -O0 -std=gnu11

# Linker flags
#===============================================
# -T			- 	"Target Linker Script". Tells the linker where the .ld script is located.
#					Without this, the linker wouldn't know the memory map (e.g., Flash starts at 0x08000000).
# --specs=nosys.specs - "No System". Tells the standard C library that there is no OS handling system calls (like printf).
# -Wl,--gc-sections - Tells the linker to drop unreferenced functions/data to save space.
#===============================================
LDFLAGS = $(MCU) -T$(LDSCRIPT) --specs=nano.specs  -Wl,-Map=$(BUILD_DIR)/$(PROJECT).map -Wl,--gc-sections

# List of object files to be generated and linked
OBJECTS		=	$(BUILD_DIR)/main.o \
				$(BUILD_DIR)/startup_stm32f411retx.o \
				$(BUILD_DIR)/syscalls.o \
				$(BUILD_DIR)/sysmem.o

# ==============================================================================
# Build Targets and Rules
# ==============================================================================

# Default build target: generates the ELF, BIN, and HEX files, then prints the size
all: $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).bin $(BUILD_DIR)/$(PROJECT).hex

# Compilation Rule for main.c
# Compile main.c into an object file (main.o)
# The '| $(BUILD_DIR)' is an order-only prerequisite, ensuring the build directory exists without forcing a rebuild if its timestamp changes.
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

# Compilation Rule for the startup script
# Assemble the startup script into an object file
$(BUILD_DIR)/startup_stm32f411retx.o: $(STARTUP_SCRIPT) | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

# Linking Rule
# Link all object files together using the linker script to create the final ELF executable
$(BUILD_DIR)/$(PROJECT).elf: $(OBJECTS) $(LDSCRIPT)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SIZE) $@

# Format Conversion Rule: ELF to HEX
# Convert the ELF executable into an Intel HEX file (often used by some flashers)
$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf
	$(OBJCOPY) -O ihex $< $@

# Format Conversion Rule: ELF to BIN
# Convert the ELF executable into a raw binary file (used by st-link utilities)
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf
	$(OBJCOPY) -O binary $< $@

# Directory Creation Rule
# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $@

# ==============================================================================
# Flashing and Cleanup Utilities
# ==============================================================================

# Flash Target
# Flash the compiled ELF file to the STM32 microcontroller using OpenOCD
# Run OpenOCD using ST-LINK and STM32F4 config files. 
# 'program' flashes the ELF, 'verify' checks it, 'reset' restarts the chip, and 'exit' closes OpenOCD.
# The grep pipe filters out harmless 'unable to match requested speed' warnings that OpenOCD frequently prints.
flash: all
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program $(BUILD_DIR)/$(PROJECT).elf verify reset exit" 2>&1 | grep -i -v "unable to match requested speed"

# Cleanup Target
# Remove all generated build artifacts to start fresh
# Recursively forcefully remove the build directory and everything inside it
clean:
	rm -rf $(BUILD_DIR)

# Phony targets: declare targets that are not physical files
.PHONY: all clean flash
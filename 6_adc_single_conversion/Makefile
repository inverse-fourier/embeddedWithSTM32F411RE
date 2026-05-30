# Toolchain definitions
CC = arm-none-eabi-gcc
PROJECT = 6_adc_single_conversion
BUILD_DIR = build
SIZE = arm-none-eabi-size
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
READELF = arm-none-eabi-readelf

# Script paths
LDSCRIPT = STM32F411RETX_FLASH.ld
STARTUP_SCRIPT = startup/startup_stm32f411retx.s

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
# -I<path> 	-\tAdd directory to header search path for includes
#===============================================
INCLUDES = -I. -Iinc
CFLAGS = $(MCU) -Wall -g -O0 -std=gnu11 $(INCLUDES)

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
				$(BUILD_DIR)/sysmem.o \
				$(BUILD_DIR)/usart.o \
				$(BUILD_DIR)/adc.o

# ==============================================================================
# Build Targets and Rules
# ==============================================================================

# Default build target: generates the ELF, BIN, and HEX files, then prints the size
all: $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).bin $(BUILD_DIR)/$(PROJECT).hex

# Compilation Rule for source files in src
# Compile each C source file into an object file under build/
# The '| $(BUILD_DIR)' is an order-only prerequisite, ensuring the build directory exists without forcing a rebuild if its timestamp changes.
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
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

#Dissasembly Rule
# Generate a human-readable assembly listing from the ELF file for debugging and analysis
disasm: $(BUILD_DIR)/$(PROJECT).elf
	$(OBJDUMP) -d $< > $(BUILD_DIR)/$(PROJECT).asm

# Disassembly with source if debug info exists
# Generate a disassembly listing that includes source code lines (requires -g flag during compilation)
disasm-src: $(BUILD_DIR)/$(PROJECT).elf
	$(OBJDUMP) -d -S $< > $(BUILD_DIR)/$(PROJECT)_src.asm

# Memory layout targets
layout: $(BUILD_DIR)/$(PROJECT).elf
	$(READELF) -S $<

prog-header: $(BUILD_DIR)/$(PROJECT).elf
	$(READELF) -l $<

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

monitor:
	@PORT=$$(ls /dev/ttyACM* /dev/ttyUSB* 2>/dev/null | head -n 1); \
	if [ -z "$$PORT" ]; then \
		echo "No serial port found. Please connect your device and try again."; \
		exit 1; \
	fi; \
	echo "Monitoring serial output on $$PORT..."; \
	picocom -b 115200 --echo --imap lfcrlf "$$PORT"

burn:
	@echo -e "\n$(GREEN)🧹 Wiping old build files...$(NC)"
	$(MAKE) clean
	
	@echo -e "\n$(GREEN)🔨 Compiling new C code...$(NC)"
	$(MAKE) all
	
	@echo -e "\n$(GREEN)✅ Flashing to the microcontroller...$(NC)"
	$(MAKE) flash

	@echo -e "\n$(GREEN)📡 Starting serial monitor...$(NC)"
	$(MAKE) monitor

# Phony targets: declare targets that are not physical files
.PHONY: all clean flash monitor burn reset
# project name
PRJNAME         = Sumobot

# tool commands
CC              = arm-none-eabi-gcc
CPP             = arm-none-eabi-g++
AS              = arm-none-eabi-gcc
AR              = arm-none-eabi-ar
LD              = arm-none-eabi-gcc
RANLIB          = arm-none-eabi-ranlib
OBJCOPY         = arm-none-eabi-objcopy
OBJDUMP         = arm-none-eabi-objdump

# library paths
CHIBIOSDIR	= ../Libraries/ChibiOS
CHIBIOSLIBDIR	= $(CHIBIOSDIR)/os/ports/GCC/ARMCMx
FATFSDIR	= ../Libraries/FatFS

# working and output paths
OBJDIR          = ./.objs
DEPDIR          = ./.deps
OUTDIR          = ./Output

# final target files
ELFFILE         = $(OUTDIR)/$(PRJNAME).elf
BINFILE         = $(OUTDIR)/$(PRJNAME).bin
HEXFILE         = $(OUTDIR)/$(PRJNAME).hex
MAPFILE         = $(OUTDIR)/$(PRJNAME).map
LSTFILE         = $(OUTDIR)/$(PRJNAME).lst

# common tool flags and macro definitions
MCUFLAGS        = -mcpu=cortex-m4 -march=armv7e-m -mno-thumb-interwork -mthumb
MCUDEFINES	= -DTHUMB_NO_INTERWORKING -DTHUMB -DTHUMB_PRESENT
FPUFLAGS        = -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant
FPUDEFINES	= -DCORTEX_USE_FPU=TRUE
DEPFLAGS	= -MD -MP -MF $(DEPDIR)/$(@F).d
OPTFLAGS	= -Og -ggdb -fomit-frame-pointer -falign-functions=16 \
		  -ffunction-sections -fdata-sections -fno-common

# chibios defines - required for compatibility with GCC 4.9
CHIBIOSDEFINES	= -Dasm=__asm

# compilation/assembler flags
ASFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) $(MCUDEFINES) $(FPUDEFINES) \
		  $(ASMDEFINES) $(OPTFLAGS) $(CHIBIOSDEFINES) $(DEFINES) -x \
		  assembler-with-cpp
CCFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) $(MCUDEFINES) $(FPUDEFINES) \
		  $(ASMDEFINES) $(OPTFLAGS) $(CHIBIOSDEFINES) $(DEFINES) -Wall \
		  -Wextra -Wfatal-errors
CFLAGS          = $(CCFLAGS) --std=c99 -Wstrict-prototypes
CPPFLAGS        = $(CCFLAGS) --std=c++11 -fno-rtti -fno-exceptions

# linker flags
LDSCRIPT	= ./LinkerScripts/Sumobot_STM32F407xE.ld
LDFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(OPTFLAGS) -nostartfiles \
		  -Wl,-Map=$(MAPFILE) -Wl,--no-warn-mismatch -Wl,--gc-sections \
		  -Wl,--script=$(LDSCRIPT) -Wl,--cref -Wl,--fatal-warnings \
		  -Wl,--library-path=$(CHIBIOSLIBDIR)

# assembly and C/C++ source
ASRC            = $(shell grep '.s$$' Sumobot.files)
CSRC            = $(shell grep '.c$$' Sumobot.files)
CPPSRC          = $(shell grep '.cpp$$' Sumobot.files)
SRC		= $(ASRC) $(CSRC) $(CPPSRC)

# include folders
INCDIR          = $(addprefix -I,$(shell cat Sumobot.includes))

# intermediate file paths
AOBJS           = $(addprefix $(OBJDIR)/,$(notdir $(ASRC:.s=.o)))
COBJS           = $(addprefix $(OBJDIR)/,$(notdir $(CSRC:.c=.o)))
CPPOBJS         = $(addprefix $(OBJDIR)/,$(notdir $(CPPSRC:.cpp=.o)))
OBJS          	= $(AOBJS) $(COBJS) $(CPPOBJS)

# search paths for files
VPATH     	= $(dir $(SRC))

all: $(ELFFILE) $(BINFILE) $(HEXFILE) $(LSTFILE)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(DEPDIR)
	rm -rf $(OUTDIR)

$(DEPDIR):
	mkdir -p $(DEPDIR)

$(OBJDIR): $(DEPDIR)
	mkdir -p $(OBJDIR)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(AOBJS): $(OBJDIR)/%.o : %.s $(OBJDIR)
	$(AS) -c $(ASFLAGS) $(INCDIR) $< -o $@

$(COBJS): $(OBJDIR)/%.o : %.c $(OBJDIR)
	$(CC) -c $(CFLAGS) $(INCDIR) $< -o $@

$(CPPOBJS): $(OBJDIR)/%.o : %.cpp $(OBJDIR)
	$(CPP) -c $(CPPFLAGS) $(INCDIR) $< -o $@

$(ELFFILE): $(OBJS) $(OUTDIR) $(LDSCRIPT) $(CHIBIOSLIBDIR)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

$(BINFILE): $(ELFFILE) $(OUTDIR)
	$(OBJCOPY) -O binary $< $@

$(HEXFILE): $(ELFFILE) $(OUTDIR)
	$(OBJCOPY) -O ihex $< $@

$(LSTFILE): $(ELFFILE) $(OUTDIR)
	$(OBJDUMP) -x -D -M force-thumb $< > $@

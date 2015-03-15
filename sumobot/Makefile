# project name
PRJNAME         = sumobot

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
CHIBIOSDIR	= ../lib/chibios
CHIBIOSLIBDIR	= $(CHIBIOSDIR)/os/ports/GCC/ARMCMx

# working and output paths
OBJDIR          = ./.objs
DEPDIR          = ./.deps
OUTDIR          = ./output

# final target files
ELFFILE         = $(OUTDIR)/$(PRJNAME).elf
BINFILE         = $(OUTDIR)/$(PRJNAME).bin
HEXFILE         = $(OUTDIR)/$(PRJNAME).hex
MAPFILE         = $(OUTDIR)/$(PRJNAME).map

# common tool flags and macro definitions
MCUFLAGS        = -mcpu=cortex-m4 -march=armv7e-m -mno-thumb-interwork -mthumb
MCUDEFINES	= -DTHUMB_NO_INTERWORKING -DTHUMB -DTHUMB_PRESENT
FPUFLAGS        = -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant
FPUDEFINES	= -DCORTEX_USE_FPU=TRUE
DEPFLAGS	= -MD -MP -MF $(DEPDIR)/$(@F).d
ASMDEFINES	= -Dasm=__asm
OPTFLAGS	= -O2 -ggdb -fomit-frame-pointer -falign-functions=16 \
		  -ffunction-sections -fdata-sections -fno-common

# compilation/assembler flags
ASFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) $(MCUDEFINES) $(FPUDEFINES) \
		  $(ASMDEFINES) $(OPTFLAGS) $(DEFINES) -x assembler-with-cpp
CCFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) $(MCUDEFINES) $(FPUDEFINES) \
		  $(ASMDEFINES) $(OPTFLAGS) $(DEFINES) -Wall -Wextra
CFLAGS          = $(CCFLAGS) --std=c99 -Wstrict-prototypes
CPPFLAGS        = $(CCFLAGS) --std=c++11 -fno-rtti -fno-exceptions

# linker flags
LDSCRIPT	= ./sumobot_stm32f407zg.ld
LDFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(OPTFLAGS) -nostartfiles \
		  -Wl,-Map=$(MAPFILE) -Wl,--no-warn-mismatch -Wl,--gc-sections \
		  -Wl,--script=$(LDSCRIPT) -Wl,--cref \
		  -Wl,--library-path=$(CHIBIOSLIBDIR)
# assembly and C/C++ source
ASRC            = $(shell grep '.s$$' sumobot.files)
CSRC            = $(shell grep '.c$$' sumobot.files)
CPPSRC          = $(shell grep '.cpp$$' sumobot.files)
SRC		= $(ASRC) $(CSRC) $(CPPSRC)

# include folders
INCDIR          = $(addprefix -I,$(shell cat sumobot.includes))

# intermediate file paths
AOBJS           = $(addprefix $(OBJDIR)/,$(notdir $(ASRC:.s=.o)))
COBJS           = $(addprefix $(OBJDIR)/,$(notdir $(CSRC:.c=.o)))
CPPOBJS         = $(addprefix $(OBJDIR)/,$(notdir $(CPPSRC:.cpp=.o)))
OBJS          	= $(AOBJS) $(COBJS) $(CPPOBJS)

# search paths for files
VPATH     	= $(dir $(SRC))

all: $(ELFFILE)

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


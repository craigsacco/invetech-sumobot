# project name
PRJNAME         = sumobot

# tool commands
CC              = arm-none-eabi-gcc
CXX             = arm-none-eabi-g++
AS              = arm-none-eabi-as
AR              = arm-none-eabi-ar
LD              = arm-none-eabi-ld
RANLIB          = arm-none-eabi-ranlib
OBJCOPY         = arm-none-eabi-objcopy
OBJDUMP         = arm-none-eabi-objdump

# working folders
OBJDIR          = ./.objs
DEPDIR          = ./.deps
OUTDIR          = ./output

# common definitions
DEFINES         = -DCORTEX_USE_FPU=TRUE -DTHUMB_NO_INTERWORKING

# common tool flags
MCUFLAGS        = -march=armv7e-m -mno-thumb-interwork -mthumb
FPUFLAGS        = -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant
DEPFLAGS	= -MD -MP -MF .dep/$(@F).d

# compilation/assembler flags
ASFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) -mno-thumb-interwork
CCFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) -ffunction-sections \
		  -fdata-sections -fno-common
CFLAGS          = $(CCFLAGS) --std=c99
CPPFLAGS        = $(CCFLAGS) --std=c++11

# linker flags
LDFLAGS         = $(MCUFLAGS) $(FPUFLAGS) $(DEPFLAGS) --gc-sections -nostartfiles \
		  -Wl,-Map=$(OUTDIR)/$(PRJNAME).map,--cref,--no-warn-mismatch

# assembly and C/C++ source
ASRC            = $(shell grep '.s$$' sumobot.files)
CSRC            = $(shell grep '.c$$' sumobot.files)
CPPSRC          = $(shell grep '.cpp$$' sumobot.files)

# include folders
INCDIR          = $(addprefix -I,$(shell cat sumobot.includes))

# intermediate file paths
AOBJS           = $(addprefix $(OBJDIR)/,$(notdir $(ASRC:.s=.o)))
COBJS           = $(addprefix $(OBJDIR)/,$(notdir $(CSRC:.c=.o)))
CPPOBJS         = $(addprefix $(OBJDIR)/,$(notdir $(CPPSRC:.cpp=.o)))
OBJS          	= $(AOBJS) $(COBJS) $(CPPOBJS)

# final target files
ELFFILE         = $(OUTDIR)/$(PRJNAME).elf
BINFILE         = $(OUTDIR)/$(PRJNAME).bin
HEXFILE         = $(OUTDIR)/$(PRJNAME).hex

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

$(AOBJS): $(OBJDIR)/%.o : $(ASRC) $(OBJDIR)
	$(AS) -c $(ASFLAGS) $(INCDIR) $< -o $@

$(COBJS): $(OBJDIR)/%.o : $(CSRC) $(OBJDIR)
	$(CC) -c $(CFLAGS) $(INCDIR) $< -o $@

$(CPPOBJS): $(OBJDIR)/%.o : $(CPPSRC) $(OBJDIR)
	$(CPP) -c $(CPPFLAGS) $(INCDIR) $< -o $@

$(ELFFILE): $(OBJS) $(OUTDIR)
	$(LD) $(LDFLAGS) $(OBJS) -o $@


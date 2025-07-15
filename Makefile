CC = aarch64-elf-gcc
QEMU = qemu-system-aarch64

OUT = netkern
CFLAGS = \
	-std=gnu99 \
	-Wall \
	-Wextra \
	-Wstrict-prototypes \
	-Werror \
	-MMD \
	-ffreestanding \
	-nostdlib \
	-mgeneral-regs-only \
	-mcpu=cortex-a53

LDFLAGS = \
	-Wl,-Tsrc/kernel.ld

QEMUFLAGS = \
	-machine virt \
	-cpu cortex-a53 \
	-nographic \
	-serial mon:stdio

OBJ = \
	src/cc.o \
	src/entry.o \
	src/handle.o \
	src/l.o \
	src/print.o \
	src/vec.o

DEPS := $(OBJ:.o=.d)

.PHONY: all
all: $(OUT)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: run
run: $(OUT)
	$(QEMU) $(QEMUFLAGS) -kernel $(OUT)

.PHONY: clean
clean:
	rm -f $(OBJ) $(DEPS) $(OUT)

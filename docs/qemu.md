# QEMU

This document describes features that are specific to the QEMU AArch64 virt board and may not be obvious.

## Booting

The kernel is built as an ELF file, which QEMU then loads and jumps to the ELF entry point specified in the linker script. If the file were not an ELF file, QEMU would use the Linux kernel protocol instead, which has its own quirks.

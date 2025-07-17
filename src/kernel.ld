ENTRY(_boot_stub)

PHDRS
{
  text PT_LOAD;
  rodata PT_LOAD;
  data PT_LOAD;
}

__higher_half = 0xffff000000000000;

SECTIONS
{
  . = 0x40000000;

  __boot_pt_l0 = .;
  . += 4096;
  __boot_pt_l1 = .;
  . += 4096;

  . += __higher_half;

  .text : AT(ADDR(.text) - __higher_half) {
    *(.text)
  } :text

  .rodata : AT(ADDR(.rodata) - __higher_half) {
    *(.rodata)
  } :rodata

  .data : AT(ADDR(.data) - __higher_half) {
    *(.data)
  } :data

  .bss : AT(ADDR(.bss) - __higher_half) {
    . = ALIGN(8);
    __bss_start = .;
    *(.bss COMMON)
    . = ALIGN(8);
    __bss_end = .;
  } :data

  .stack : AT(ADDR(.stack) - __higher_half) {
    . = ALIGN(16);
    . += 4096;
    __stack_top = .;
  } :data

  . = ALIGN(4096);
  __end = .;
}

__bss_size = __bss_end - __bss_start;

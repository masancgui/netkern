ENTRY(_kernel_entry)

PHDRS
{
  text PT_LOAD;
  rodata PT_LOAD;
  data PT_LOAD;
}

SECTIONS
{
  . = 0x40100000;

  .text : {
    *(.text.entry)
    *(.text)
  } :text

  .rodata : {
    *(.rodata)
  } :rodata

  .data : {
    *(.data)
  } :data

  .bss : {
    . = ALIGN(8);
    __bss_start = .;
    *(.bss COMMON)
    . = ALIGN(8);
    __bss_end = .;
  } :data

  . += 0x1000;
  . = ALIGN(16);
  __stack_top = .;
}

__bss_size = (__bss_end - __bss_start) >> 3;

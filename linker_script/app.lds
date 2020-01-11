ENTRY(_start)

SECTIONS
{
  /* SIZEOF_HEADERS = (elf header) + (program header) */
  . = 0x08048000 + SIZEOF_HEADERS;
  .text : {
    *(.text)
  }
  .rodata : {
    *(.rodata)
  }
  .data : {
    *(.data)
  }
  .bss : {
    *(.bss)
  }
}

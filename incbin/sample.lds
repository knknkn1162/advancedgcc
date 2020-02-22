OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
  /* SIZEOF_HEADERS = (elf header) + (program header) */
  /* 0x08048000 in 32 bit machine and 0x00400000 in 64 bit machine) */
  . = 0x400000 + SIZEOF_HEADERS;
  .text : {
    *(.text.init)
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

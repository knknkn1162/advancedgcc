OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
  /* SIZEOF_HEADERS = (elf header) + (program header) */
  /* 0x08048000 in 32 bit machine and 0x00400000 in 64 bit machine) */
  . = 0x400000 + SIZEOF_HEADERS;
  .text : {
    *(.text)
  }
  .rodata : {
    *(.rodata)
  }
  . = ALIGN(8);
  .init_array : {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array ))
    PROVIDE_HIDDEN (__init_array_end = .);
  }
  .fini_array : {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array ))
    PROVIDE_HIDDEN (__fini_array_end = .);
  }
  .data : {
    *(.data)
  }
  .bss : {
    *(.bss)
  }
}

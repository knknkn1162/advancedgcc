.intel_syntax noprefix
.section .text
.globl syscall

syscall:
  mov rax, rdi
  mov rdi, rsi
  mov rsi, rdx
  mov rdx, rcx
  mov r10, r8
  mov r8, r9
  mov r9, 8[rsp]
  syscall
  ret

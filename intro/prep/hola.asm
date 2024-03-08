.section .data
msg:
  .ascii "Andrew228\n\0"

.section .text
.globl _start
_start:
  # print message
  movl $4,   %eax
  movl $1,   %ebx
  movl $msg, %ecx
  movl $11,  %edx
  int  $0x80

  # exit a program
  movl $1,   %eax
  movl $0,   %ebx
  int  $0x80

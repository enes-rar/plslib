.intel_syntax noprefix
.globl A__main

.text

A__main:
sub rsp, 40
call main
add rsp, 40
ret
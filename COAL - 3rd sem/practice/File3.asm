INCLUDE Irvine32.inc

.data
a DWORD 5
b DWORD 5
msg1 BYTE "a < b",0
msg2 BYTE "a = b",0
msg3 BYTE "a > b",0

.code
main PROC
    mov eax, a
    mov ebx, b
    cmp eax, ebx
    call DumpRegs

    mov eax, 3
    mov ebx, 7
    cmp eax, ebx
    call DumpRegs

    mov eax, 9
    mov ebx, 2
    cmp eax, ebx
    call DumpRegs

    exit
main ENDP
END main

INCLUDE Irvine32.inc

.data
msg byte "enter a number:", 0
num dword 0
equals byte " = ", 0
multiply byte " * ", 0

.code
one PROC
    mov edx, offset msg
    call writestring
    call readint
    mov num, eax
    mov ecx, 10
    mov esi, 1

table:
    mov eax, num
    call writedec
    mov edx, offset multiply
    call writestring
    mov eax, esi
    call writedec
    mov edx, offset equals
    call writestring
    mov eax, num
    mul esi
    inc esi
    call writedec
    call crlf
    loop table
    
one ENDP
END one

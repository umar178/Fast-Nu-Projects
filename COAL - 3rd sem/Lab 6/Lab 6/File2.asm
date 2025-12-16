INCLUDE Irvine32.inc

.data
msgIn   BYTE "Enter a number: ",0
msgOut  BYTE "Factorial = ",0
n       DWORD 0
result  DWORD 1

.code
two PROC
    mov edx, OFFSET msgIn
    call WriteString
    call ReadInt
    mov n, eax

    mov ecx, eax
    mov eax, 1

fact_loop:
    mul ecx
    loop fact_loop

mov edx, OFFSET msgOut
call WriteString
call WriteDec
call Crlf
call ReadChar

exit

two ENDP
END two

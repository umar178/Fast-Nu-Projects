INCLUDE Irvine32.inc

.data
sum DWORD 0
count DWORD 0
prompt BYTE "Enter a number: ", 0
output BYTE "Total sum is: ", 0

.code
one PROC
    mov ecx, 10

read_loop:
    mov edx, OFFSET prompt
    call WriteString
    call ReadInt
    cmp eax, 0
    je done
    add sum, eax
    inc count
    dec ecx
    jnz read_loop

done:
    mov edx, offset output
    call writestring
    mov eax, sum
    call WriteDec
    call Crlf
    exit
one ENDP

END one

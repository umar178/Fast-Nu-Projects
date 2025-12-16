INCLUDE Irvine32.inc

.data
num DWORD ?
n BYTE ?
mulRes DWORD ?
divRes DWORD ?
msg1 BYTE "Enter a number: ",0
msg2 BYTE "Enter n: ",0
m1 BYTE "Result after multiplying by 2^n: ",0
m2 BYTE "Result after dividing by 2^n: ",0

.code
main PROC
    mov edx, OFFSET msg1
    call WriteString
    call ReadInt
    mov num, eax

    mov edx, OFFSET msg2
    call WriteString
    call ReadInt
    mov n, al

    mov eax, num
    mov cl, n
    shl eax, cl
    mov mulRes, eax

    mov eax, num
    mov cl, n
    shr eax, cl
    mov divRes, eax

    mov edx, OFFSET m1
    call WriteString
    mov eax, mulRes
    call WriteInt
    call CrLf

    mov edx, OFFSET m2
    call WriteString
    mov eax, divRes
    call WriteInt
    call CrLf

    exit
main ENDP
END main

INCLUDE Irvine32.inc

.data
    promptK      BYTE "Enter temperature in Kelvin: ", 0
    msgK         BYTE "Kelvin: ", 0
    msgC         BYTE "Celsius: ", 0
    msgF         BYTE "Fahrenheit: ", 0
    msgFlags1    BYTE "Flags before pop: ", 0
    msgFlags2    BYTE "Flags after pop: ", 0
    kelvin       SDWORD ?
    celsius      SDWORD ?
    fahrenheit   SDWORD ?
    flagsStored  DWORD ?

.code
main PROC
    mov edx, OFFSET promptK
    call WriteString
    call ReadInt
    mov kelvin, eax

    mov eax, kelvin
    sub eax, 273
    mov celsius, eax

    pushfd
    pop eax
    push eax
    mov flagsStored, eax

    mov eax, celsius
    imul eax, 9
    cdq
    mov ebx, 5
    idiv ebx
    add eax, 32
    mov fahrenheit, eax

    mov edx, OFFSET msgK
    call WriteString
    mov eax, kelvin
    call WriteInt
    call Crlf

    mov edx, OFFSET msgC
    call WriteString
    mov eax, celsius
    call WriteInt
    call Crlf

    mov edx, OFFSET msgF
    call WriteString
    mov eax, fahrenheit
    call WriteInt
    call Crlf

    mov edx, OFFSET msgFlags1
    call WriteString
    mov eax, flagsStored
    call WriteHex
    call Crlf

    pop eax
    mov edx, OFFSET msgFlags2
    call WriteString
    call WriteHex
    call Crlf

    exit
main ENDP
END main

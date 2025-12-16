INCLUDE Irvine32.inc

.data
salaries DWORD 5 DUP(?)
msgInput  BYTE "Enter salary: ",0
msgAvg    BYTE "Average salary = ",0
msgSum    BYTE "Sum of salaries = ",0
msgType   BYTE "Size of one element (TYPE) = ",0
msgLength BYTE "Number of elements (LENGTHOF) = ",0
msgSize   BYTE "Total size in bytes (SIZEOF) = ",0
msgOF     BYTE "Overflow detected!",0

.code
main PROC
    mov eax, TYPE salaries
    mov edx, OFFSET msgType
    call WriteString
    call WriteDec
    call Crlf

    mov eax, LENGTHOF salaries
    mov edx, OFFSET msgLength
    call WriteString
    call WriteDec
    call Crlf

    mov eax, SIZEOF salaries
    mov edx, OFFSET msgSize
    call WriteString
    call WriteDec
    call Crlf

    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    mov salaries[0], eax

    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    mov salaries[4], eax

    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    mov salaries[8], eax

    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    mov salaries[12], eax

    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    mov salaries[16], eax

    xor eax, eax
    add eax, salaries[0]
    jc overflow_flag
    add eax, salaries[4]
    jc overflow_flag
    add eax, salaries[8]
    jc overflow_flag
    add eax, salaries[12]
    jc overflow_flag
    add eax, salaries[16]
    jc overflow_flag

    mov ebx, eax
    mov edx, OFFSET msgSum
    call WriteString
    mov eax, ebx
    call WriteDec
    call Crlf

    mov eax, ebx
    mov ecx, LENGTHOF salaries
    cdq
    div ecx
    mov edx, OFFSET msgAvg
    call WriteString
    call WriteDec
    call Crlf
    jmp exit_program

overflow_flag:
    mov edx, OFFSET msgOF
    call WriteString
    call Crlf

exit_program:
    call dumpregs
    exit
main ENDP
END main

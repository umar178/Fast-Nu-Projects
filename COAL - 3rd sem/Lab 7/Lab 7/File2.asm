INCLUDE Irvine32.inc

.data
prompt      BYTE "Enter 8-bit binary status code: ", 0
msgCode     BYTE "Status code (binary): ", 0
msgAbnormal BYTE "Abnormal vitals: ", 0
urgentMsg   BYTE "Patient Status: URGENT", 0
interMsg    BYTE "Patient Status: INTERMEDIATE", 0
trivialMsg  BYTE "Patient Status: TRIVIAL", 0
newline     BYTE 0Dh,0Ah,0
inputBuffer BYTE 9 DUP(0)

v1 BYTE "Blood Sugar", 0
v2 BYTE "Systolic BP", 0
v3 BYTE "Diastolic BP", 0
v4 BYTE "Pulse", 0
v5 BYTE "Hemoglobin", 0
v6 BYTE "Body Temperature", 0
v7 BYTE "Respiration Rate", 0
v8 BYTE "Pain Level", 0

vitalPtrs DWORD OFFSET v1, OFFSET v2, OFFSET v3, OFFSET v4, OFFSET v5, OFFSET v6, OFFSET v7, OFFSET v8

.code
main PROC
    mov edx, OFFSET prompt
    call WriteString
    mov edx, OFFSET inputBuffer
    mov ecx, SIZEOF inputBuffer
    call ReadString

    xor ebx, ebx
    mov esi, OFFSET inputBuffer
    mov ecx, 8

convert_loop:
    mov al, [esi]
    cmp al, 0
    je done_convert
    shl bl, 1
    cmp al, '1'
    jne skip_set
    or bl, 1
skip_set:
    inc esi
    loop convert_loop

done_convert:
    mov edx, OFFSET msgCode
    call WriteString
    movzx eax, bl
    call WriteBin
    mov edx, OFFSET newline
    call WriteString

    mov ecx, 8
    mov esi, OFFSET vitalPtrs
    xor eax, eax
    mov dl, bl
    mov edx, OFFSET msgAbnormal
    call WriteString
    mov edx, OFFSET newline
    call WriteString

check_bits:
    test bl, 1
    jz skip_vital
    add eax, 1
    mov edi, [esi]
    mov edx, edi
    call WriteString
    mov edx, OFFSET newline
    call WriteString
skip_vital:
    add esi, 4
    shr bl, 1
    loop check_bits

    mov edx, OFFSET newline
    call WriteString
    cmp eax, 6
    jge urgent_status
    cmp eax, 3
    jge inter_status
    jmp trivial_status

urgent_status:
    mov edx, OFFSET urgentMsg
    call WriteString
    jmp done

inter_status:
    mov edx, OFFSET interMsg
    call WriteString
    jmp done

trivial_status:
    mov edx, OFFSET trivialMsg
    call WriteString

done:
    call Crlf
    exit
main ENDP

END main

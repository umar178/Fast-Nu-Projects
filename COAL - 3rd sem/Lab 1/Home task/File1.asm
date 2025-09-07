INCLUDE Irvine32.inc

.data
    msg1 BYTE "Experiment: Dumping registers after loading values", 0

.code
main PROC

mov edx, OFFSET msg1
call WriteString
call Crlf

mov eax, 12345678h   
mov ebx, 87654321h   
mov ecx, 11111111h   
mov edx, 22222222h  

mov esi, 33333333h   
mov edi, 44444444h   
mov ebp, 55555555h   

call DumpRegs

mov eax, 0AAAAAAAh
mov ebx, 0BBBBBBBh
mov ecx, 0CCCCCCCh
mov edx, 0DDDDDDDh
mov esi, 0EEEEEEEh
mov edi, 0FFFFFFFh
mov ebp, 1234ABCDh

call DumpRegs

exit
main ENDP

END main

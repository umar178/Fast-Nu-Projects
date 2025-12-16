INCLUDE Irvine32.inc

base   EQU 25000
days   EQU 30
rate   EQU 600

.data
msg1 BYTE "Total salary is: ", 0
msg2 BYTE "Input leaves: ", 0
msg3 BYTE "Input hours: ", 0
leaves DWORD ?
hours  DWORD ?
salary DWORD ?

.code 
main PROC

mov edx, OFFSET msg2
call WriteString
call ReadInt
mov leaves, eax
call Crlf

mov edx, OFFSET msg3
call WriteString
call ReadInt
mov hours, eax
call Crlf

mov eax, base
cdq
mov ecx, days
idiv ecx
imul eax, leaves
mov edx, eax

mov eax, hours
imul eax, rate
mov ecx, eax

mov eax, base
sub eax, edx
add eax, ecx
mov salary, eax

mov edx, OFFSET msg1
call WriteString
mov eax, salary
call WriteInt
call Crlf

exit
main ENDP
END main

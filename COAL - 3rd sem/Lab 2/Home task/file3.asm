INCLUDE Irvine32.inc

.data
num1 dword 24
num2 dword 12
num3 dword 3
p1 dword ?
msg byte "Final answer for ((num1%4)/num3)*(num2 + num3*3) is: "

.code
three PROC

; num1%4
mov eax, num1
xor edx, edx
mov ebx, 4
div ebx
mov eax, edx
mov p1, eax
call writeint

call crlf

;(num1%4)/num3
mov ebx, num3
xor edx, edx
div num3
mov p1, eax
call writeint

call crlf

;num3*3
mov eax, num3
mov ebx,3
mul ebx
call writeint

call crlf

;num2 + num3*3
add eax, num2
call writeint

call crlf
call crlf

mov edx, offset msg
call writestring

;((num1%4)/num3)*(num2 + num3*3)
mov ebx, p1
mul ebx
call writeint
call crlf

exit
three ENDP
END three

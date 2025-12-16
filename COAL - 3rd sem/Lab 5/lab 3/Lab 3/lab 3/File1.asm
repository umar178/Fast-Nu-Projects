include irvine32.inc
.data
num1 DWORD 0
num2 DWORD 0
Rem2 DWORD 0
Rem1 DWORD 0

msg1 BYTE "Input an integer: ",0
msg2 BYTE "Input another integer: " ,0
msg3 BYTE "a+b=",0
msg4 BYTE "a-b=",0
msg5 BYTE "b-a=",0
msg6 BYTE "a*b=",0
msg7 BYTE "Q of a/b=",0
msg8 BYTE "R of a/b=",0
msg9 BYTE "Q of b/a=",0
msg10 BYTE "R of b/a=",0

.code 
main PROC

mov edx, offset msg1
call WriteString
call ReadInt
mov num1,eax

mov edx, offset msg2
call WriteString
call ReadInt
mov num2, eax

mov eax,num1
add eax,num2
mov edx, offset msg3
call WriteString
call WriteInt
call CrLf

mov eax, num1
sub eax, num2
mov edx, offset msg4
call WriteString
call WriteInt
call CrLf

mov eax, num2
sub eax, num1

mov edx, offset msg5
call WriteString
call WriteInt
call CrLf

mov eax,num1
imul num2

mov edx, offset msg6
call WriteString
call WriteInt
call CrLf

mov edx,0
mov eax,num1
idiv num2

mov esi, edx
mov edx, offset msg7
call WriteString
call WriteInt
call CrLf

mov edx, offset msg8
call WriteString
mov eax, esi
call WriteInt
call CrLf

mov edx,0
mov eax,num2
idiv num1

mov esi, edx
mov edx, offset msg9
call WriteString
call WriteInt
call CrLf

mov edx, offset msg10
call WriteString
mov eax, esi
call WriteInt
call CrLf

main endP
end main
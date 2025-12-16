include irvine32.inc

.data
msg1 BYTE "Input A: ",0
msg2 BYTE "Input B: " ,0
msg3 BYTE "Input c: " ,0
num_a dword 0
num_b dword 0
num_c dword 0

.code 
one PROC

mov edx, offset msg1
call writestring
call readint
mov num_a, eax

mov edx, offset msg2
call writestring
call readint
mov num_b, eax

mov edx, offset msg3
call writestring
call readint
mov num_c, eax

mov eax, 2
mul num_c
mov ebx, eax

mov eax, num_a
add eax, num_b

sub eax, ebx
call writeint

one endP
end one
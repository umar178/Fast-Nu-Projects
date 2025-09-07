include irvine32.inc

.data ; portion to initialize all the variable
p1 dword 63
p2 dword 63


.code ; portion for all the process

main PROC
mov eax, 63
xor edx, edx
mov ecx, 10
div ecx

mov p1, edx

mov eax, 50
xor edx, edx
mov ecx, 5
div ecx

mov p2, eax

call dumpregs

exit
main endP

end main
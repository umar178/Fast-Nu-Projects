include irvine32.inc

.data ; portion to initialize all the variable
text BYTE "Hello World!"

.code ; portion for all the process

main PROC
mov eax , 20
mov ebx , eax
call dumpReg
main endP


end main
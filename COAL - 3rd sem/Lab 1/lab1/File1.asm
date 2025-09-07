include irvine32.inc

.data ; portion to initialize all the variable

.code ; portion for all the process

main PROC
;mov destination , source
mov eax , 20
mov ebx , eax
call dumpRegs
main endP


end main
include irvine32.inc

.data ; portion to initialize all the variable
text BYTE "Hello world!"

.code ; portion for all the process

main PROC

mov edx, offset text
call WriteString

main endP


end main
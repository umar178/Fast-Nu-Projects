INCLUDE Irvine32.inc

.data
num1 dword 24
num2 dword 12
num3 dword 3  

.code
two PROC  
mov eax, num1
call writedec
call crlf
call writehex
call crlf
call writebin

;call DumpRegs           

exit
two ENDP
END two

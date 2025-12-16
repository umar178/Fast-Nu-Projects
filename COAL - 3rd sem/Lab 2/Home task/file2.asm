INCLUDE Irvine32.inc

.data
num1 dword 520

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

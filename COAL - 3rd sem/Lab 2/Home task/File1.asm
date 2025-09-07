INCLUDE Irvine32.inc

.data
myByte   BYTE  25h        
myWord   WORD  1234h       
myDword  DWORD 98765432h    
myChar   BYTE  'A'          
myStr    BYTE  "Hello!",0   

.code
one PROC
mov al, myByte          
mov ax, myWord           
mov eax, myDword       
mov bl, myChar          
mov edx, OFFSET myStr    

call DumpRegs           

exit
one ENDP
END one

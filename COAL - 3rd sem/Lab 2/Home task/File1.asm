INCLUDE Irvine32.inc

.data
myByte   BYTE  6h        
myWord   WORD  5641h       
myDword  DWORD 90545332h    
myChar   BYTE  'K'          
myStr    BYTE  "Umar!",0   

.code
main PROC
mov al, myByte          
mov ax, myWord           
mov eax, myDword       
mov bl, myChar          
mov edx, OFFSET myStr    

call DumpRegs           

exit
main ENDP
END main
INCLUDE Irvine32.inc

.data
A dword 10
B dword 5
C dword 8
D dword 2
X dword ?

.code
main PROC
	push D
	push C
	push B
	push A

	invoke solve, A,B,C,D
	mov X, eax
	ret

main ENDP

solve proc, 
	A:dword, B:dword, C:dword, D:dword 
	push ebp

solve endp

END main

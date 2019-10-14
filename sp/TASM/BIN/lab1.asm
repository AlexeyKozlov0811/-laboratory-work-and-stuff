.model tiny
.code
ORG 100h

start:

	mov ah, 09h
    mov dx, offset message
    int 21h
	
	mov dx, offset entered
	mov ah, 0ah
	int 21h

	mov cl, entered+1
	shr cx, 1
	
	mov ah, 09h
    mov dx, offset shift
    int 21h	
	
    mov ah, 09h
    mov dx, offset string
    int 21h
	
	mov dx, offset entered
	add dx, 2h
	mov ah, 09h
	int 21h
	
	mov ah, 09h
    mov dx, offset shift
    int 21h	
	
	mov ah, 02h
	lea si, entered
	add si, 3h
print:
		mov dl, [si]
		int 21h
		add si, 02h
	loop print
	
    ret
	
entered db 255,255,255 dup("$"),0dh, 0ah,'$',0
string db 'Entered string ',0dh, 0ah,'$',0
message db 'Enter a string ',0dh, 0ah,'$',0
shift db 0dh, 0ah,'$',0
;len equ $
end start
    
model tiny 
	.code
	.startup

	mov dx, offset message1
	mov ah, 09h
	int 21h

	mov si,0             
    jmp enter_text
enter_text:
    mov ah,01h
    int 21h
    mov mas[si],al
    inc si
	cmp si,15
    jle enter_text
	
	mov dl,13 
	mov ah,02h
	int 21h
	mov dl,10
	mov ah,02h
	int 21h
	
	mov dl,13 
	mov ah,02h
	int 21h
	mov dl,10
	mov ah,02h
	int 21h
	

	
	mov dx, offset message2
	mov ah, 09h
	int 21h

    mov si,0
    mov cx,16
	mov bl,4	
output_array:
	mov ah,02h
	mov dl,mas[si]
	int 21h	
	mov dl,' '
	int 21h	
	inc si
	
	mov ax,si
	div bl
	cmp ah,0	
	jne next1
		mov dl,13
		mov ah,02h
		int 21h
		mov dl,10
		mov ah,02h
		int 21h
	next1:
	loop output_array
	

	
	mov dl,13 
	mov ah,02h
	int 21h
	mov dl,10
	mov ah,02h
	int 21h
	
	mov dx, offset message3
	mov ah, 09h
	int 21h
	
	mov si,0
    mov cx,16
side_diag_out:
	mov dl,' '
	
	mov ax,si
	mov bl,3
	div bl
	
	cmp ah,0
	jne next2
	mov dl,mas[si]
next2:

	cmp si, 0
	jne next3
	mov dl,' '
next3:

	cmp si, 15
	jne next4
	mov dl,' '
next4:

	mov ah,02h
	int 21h
	mov dl,' '
	int 21h	
	
	inc si
	mov ax,si
	mov bl,4
	div bl
	cmp ah,0
	jne next5
		mov dl,13
		mov ah,02h
		int 21h
		mov dl,10
		mov ah,02h
		int 21h
next5:
	loop side_diag_out

	ret

message1 db "Input 16 symbols",0dh, 0ah,'$',0
message2 db "Your matrix",0dh, 0ah,'$',0
message3 db "Side diagonal",0dh, 0ah,'$',0
mas db 16 dup(?)
	end
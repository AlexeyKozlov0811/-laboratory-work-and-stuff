model tiny 
	.code
	.startup

		mov dl,20h
		mov cx,16         
		mov bl,4
		
	metka:
	
		mov ah,02h
		int 21h          
		inc dl  		
		
		mov ax,dx
		div bl
		cmp ah,0
		
		jne next
			push dx
			mov ah, 09h
			lea dx, shift
			int 21h
			pop dx
	next:
		loop metka
		
	        ret
			
shift db 0dh, 0ah,'$',0
	end

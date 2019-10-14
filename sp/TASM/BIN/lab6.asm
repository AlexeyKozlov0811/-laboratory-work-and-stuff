model tiny 
	.code
	.startup
	
	mov ah,3dh
	mov al,0 
	lea dx,file
	int 21h   
	
	mov bx,ax
	mov handle_one,bx 
	
	mov ah,3ch  
	lea dx,sec_file
	mov cx,0  
	int 21h

	mov bx,ax
	mov handle_two,bx 

	next_char:
	mov ah,3fh
	mov cx,1   
	lea dx,bufer
	mov bx,handle_one
	int 21h
	
	cmp cx,ax  
	je  is_char  
	mov end_file,1 

	mov cx,ax  
	
	
is_char:
	mov cx, 1
	mov ah,bufer 
	
	cmp ah, '×'
	jne  g1
	inc cx 
	jmp gg
	
g1:
	cmp ah, 'Ø'
	jne  g2
	inc cx 
	jmp gg
	
g2:
	cmp ah, 'Æ'
	jne  g3
	inc cx
	jmp gg 
	
g3:
	cmp ah, 'Ù'
	jne  g4
	inc cx 
	inc cx
	jmp gg 

g4:
	cmp ah, 'ø'
	jne  g5
	inc cx 
	jmp gg
	
g5:
	cmp ah, 'æ'
	jne  g6
	inc cx
	jmp gg 
	
g6:
	cmp ah, 'ù'
	jne  g7
	inc cx 
	inc cx
	jmp gg 

g7:	
	cmp ah, '÷'
	jne  gg
	inc cx 
	
gg: 
	lea bx,my_table  
	sub ah,2
	mov al,ah
	xlat
	
	mov bufer,al
	
	mov ah,40h
	mov bx,handle_two
	lea dx,bufer
	int 21h
	
	cmp end_file,1 
	je close_file
	 
	jmp next_char
	

close_file:
	mov ah,3eh
	mov bx,handle_two
	int 21h
	
	mov ah,3eh
	mov bx,handle_one
	int 21h
	
	ret
	
	file db 'first.txt',0
	sec_file db 'second.txt',0
	handle_one dw ?
	handle_two dw ?
	bufer db ?, 'HA'
	end_file db 0
	my_table db '______________________________ !"#$%& ()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_ abcdefghijklmnopqrstuvwxyz{|}  _____________________________________G__E_E____I__Iig___e_e____iABVGDEZZIJKLMNOPRSTUFHCCSSÚIÜEJJabvgdezzijklmnoprstufhccssúiüejj$'

end
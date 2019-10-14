model tiny 
	.code
	.startup
	
	mov ah,09h
	lea dx, message1
	int 21h
	
	mov ah,2ah      	
	int 21h						

	
	mov al,dh					
	sub al,1						
	mov ah,10					
	mul ah						
	
	lea dx,Mis					 
	add dx,ax					
	
	push ax
	
	mov ah,09h
	int 21h
	
	mov dl,13 
	mov ah,02h
	int 21h
	mov dl,10
	mov ah,02h
	int 21h
	
	lea dx, massage2
	mov ah,09h
	int 21h
	
	pop ax
	
	lea dx,Mis
	add dx,ax
	add dx,60
	mov ah,09h
	int 21h
	
	
	
	
	
	ret
message1 db 'Current month: $'
massage2 db 'In half a year it will be: $'
Mis db ' Sichen  $Lyutuy   $ Berezen $ Kviten  $ Traven  $	Cherven$ Lupen   $ Serpen  $ Veresen $ Ghovten $ Lustopad$ Gruden  $'
	
	
	
	end
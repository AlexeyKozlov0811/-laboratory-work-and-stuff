model tiny
.code
.startup

	lea dx,DTA
	mov ah,1ah
	int 21h
	
	lea dx,Path	
	mov cx,0
	mov ah,4eh
	int 21h

	lea dx,DTA+1eh				
	mov ah,9h			
    int 21h

	lea dx,sozdan				
	mov ah,09h
	int 21h

	mov cx,2              		
	mov bx,18h				
	
	lea bx,DTA + bx				
	mov ax,[bx] 
	mov di,ax	

	mov ax,di  
    and ax,01e0h				
	shr ax,5			

	sub al,1					
	mov ah,11					
	mul ah					
	
	lea dx,Mis
	add dx,ax					

	mov ah,9h					
	int 21h
	
	ret
	
DTA db 50 dup("$")           
Path db "D:\*.*",0		
Mis db ' Sichen  $ Lyutogo  $ Bereznya $ Kvitnya  $ Travnya  $ Chervnya $ Lupnya   $ Serpnya  $ Veresnya $ Ghovtnya $ Lustopada$ Grudnya  $'
Sozdan db '   sozdan: $'  ;рядок в пам’яті із словом sozdan:

end
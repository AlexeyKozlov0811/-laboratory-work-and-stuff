	model tiny
	.code
	.startup
	
		mov dx,offset tm
		mov ah,0ah
		int 21h
		mov dx,offset testm
		mov ah,09h
		int 21h
		mov dx,offset tm
		add dx,2h
		mov ah,09h
		int 21h
		ret
	
	tm	db 255,255,255 dup("$")
	testm	db "Entered string: $"
	
	End

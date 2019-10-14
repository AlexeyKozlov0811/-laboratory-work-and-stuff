model small
.stack 100h
.data
	
	v1 db "|"
	v2 db "|"
	g1 db "-"
	g2 db "-"
	opx2 db ? ;��������� ������� �� ��� �
	opy2 db ? ;��������� ������� �� ��� � 
	x db 0
	y db 0
	op db 0
	fName  db  "EXAMPLEE.txt",0
	buff   dw  2100 DUP(' ')
	
	massagemin db 'Nomer minimalnogo: $'
	massagemax db 10,13,'Nomer maxsymalnogo: $' 
	Nmn db 1 
	Nmx db 1
	array db 1,9,3,-4,5,6,-7,8,2,-8 
	message1 db 0dh, 0ah,"Choose task",0dh, 0ah,"Press 1 to Task-1 ",0dh, 0ah,"Press 2 to Task-2 ",0dh, 0ah,"Press 3 to exit from program ",0dh, 0ah,'$',0
.code
main:
	assume cs:@code,ds:@data,es:@data ;������� ������ � ��� ����� ��� ��� �����
	mov ax,@data
	mov es,ax 
	mov ds,ax
	
	;����			
start:
	mov ax,03h ;3� ��������� ����� 
    int 10h
	lea dx, message1
	mov ah,09h
	int 21h
re_entry:	
	mov ah,01h ;����� ��������
	int 21h 
	
	push ax ;������� ������
	mov dl,13
	mov ah,02h
	int 21h
	mov dl,10
	mov ah,02h
	int 21h	
	pop ax
	
	cmp al,"1"
	jne next1
	call task1
	jmp start
next1:
	cmp al,"2"
	jne next2
	call task2
	jmp start
next2:
	cmp al,"3"
	jne next3
	call exitp
next3:
	jmp re_entry
	
task2 proc   
    mov ax,03h ;3� ��������� ����� 
    int 10h
    mov ax,0;������������� ���� ;��� 33� ���������� ��������� � ������� ���������� � ����� �.�. ����� ��������
    int 33h

new1:
    mov op,0 ;����������-����, �� �������� ���� ����� ���
new:
;��������� ��������� ���� � � � �
    mov ax,3
    int 33h
    shr cx,3;�������� ������ (����� �� 8) ���� �������� ���������� ����������
    shr dx,3  
    mov x,cl ;��������� ���������� � ���������� 
    mov y,dl
    
    cmp bx, 0 ;���� �� ������ �� ���� ������ ������ 
    je  write 
    cmp bx, 1 ;���� ������ ��� ������� � ��������� ����� � ���� 
    je sv
    cmp bx, 2 ;���� ������ ��� �� ������
    je new1
    cmp op,1
    je write
    jmp new 
sv:
	call saveb
	jmp exit
write:
    mov op,1
    
    cmp cl,opx2;��������� �������� ������� �� �
    mov [opx2],cl;��������� ��������� ������� �
    
    ja mit1 ;���� ������ �������� �� ��� � � ����� �� ��������� ��  mit1
    jb mit2;���� ����� ��  mit2
    
    cmp dl,opy2;��������� �������� ������� �� �
    mov [opy2],dl;��������� ��������� ������� �
    
    jb mit3;���� �� ��� � ����� �� mit3
    ja  mit4; ���� �� mit4
    jmp new
	
	
mit1:
    mov ah,13h ; ������� ������
    mov al,0; ����� ������
    mov bl,7; ����,
    mov cx,1; ����� ������
    mov bp, offset g2  ;������� ������ "-"
    mov dh,y; ������
    mov dl,x; �������
    int 10h
    jmp new
    
mit2:
    mov ah,13h
    mov al,0
    mov bl,7
    mov cx,1
    mov bp, offset g1 ;������� ������ "-"
    mov dh,y
    mov dl,x
    int 10h
    jmp new
    
mit3:
    mov ah,13h
    mov al,0
    mov bl,7
    mov cx,1
    mov bp, offset v2 ;������� ������ "|"
    mov dh,y
    mov dl,x
    int 10h
    jmp new
    
mit4:
    mov ah,13h
    mov al,0
    mov bl,7
    mov cx,1
    mov bp, offset v1 ;������� ������ "|"
    mov dh,y
    mov dl,x
    int 10h
    jmp new
	
exit:
	ret
task2 endp    
 
 
saveb proc
;������ � �����
	mov   di,buff  ; DI ��� STOSB
	xor   bx,bx  ; ��������(0)
	xor   dx,dx ; ������� ������� � ����(0:0)
save:                    
	mov   cx,80  ; ��������� ����� ��-�������
line_out:                       
	mov   ah,2  ; ������������� ������
	int   10h              
	mov   ah,8 ; ������ ������ � �������
	int   10h            
	stosb  ; ���������� ��� � �����
	inc   dl ; ��.������� � ����..
	loop  line_out ; ��������� ���� ������
 
	mov   ax,0A0Dh ; ������� ������ � ������
	STOSW                  
	xor   dl,dl  
	inc dh  ; ..� � ����
	cmp   dh,25  ; ��������� ������?
	JNZ   save             
 
; ���������� � ����
	mov   ah,3Ch  ; �������..
	lea   dx,fName        
	mov   cx,20h          
	int   21h             
	xchg  bx,ax           
	mov   ah,40h ; ������..
	mov   DX,buff         
	mov   CX,2050         
	int   21h              
	mov   ah,3Eh; ������� ����
	int   21h              
	ret   
saveb endp

exitp proc	;����� �� ���������			
	mov ah,4ch				
	int 21h
	ret
exitp endp	

task1 proc	
xor cx,cx 
mov si, offset array
mov cl, 10               
mov bl, 32 
mov bh, -31

flag1: 
     lodsb     
     cmp al, 0
     jge comp 
     cmp al, bh
     jg max
     jmp flag2
     
comp:    
     cmp al, bl
     jl min
     jmp flag2
min: 
     mov bl, al
     mov dl, Nmn
     jmp flag2
max:
    mov bh, al 
    mov dh, Nmx
flag2:
    
    add Nmn, 1  
    add Nmx, 1
    loop flag1 
    
    mov Nmn, dl
    mov Nmx, dh  
    
    mov dx, offset massagemin
    mov ah, 09h
    int 21h     
    
    mov al, Nmn 
    xor cx,cx 
    xor ah,ah 
trans1: 
        xor dx,dx           
        mov bx, 10
        div bx
        push dx
        inc cx
        cmp ax, 0       
    jne trans1
out1:           
        mov ah, 02h    
        xor dx, dx
        pop dx
        add dx, '0'
        int 21h
        loop out1    
    mov dx, offset massagemax
    mov ah, 09h
    int 21h   
    
    mov al,Nmx 
    xor cx,cx 
    xor ah,ah 
trans2: 
        xor dx,dx           
        mov bx, 10
        div bx
        push dx
        inc cx
        cmp ax, 0       
        jne trans2
out2:          
        mov ah, 02h    
        xor dx, dx
        pop dx
        add dx, '0'
        int 21h
        loop out2  
	
	ret 
task1 endp	

end main

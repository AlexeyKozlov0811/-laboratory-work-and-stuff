model small
.stack 100h
.data
	
	v1 db "|"
	v2 db "|"
	g1 db "-"
	g2 db "-"
	opx2 db ? ;положение курсора по оси х
	opy2 db ? ;положение курсора по оси у 
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
	assume cs:@code,ds:@data,es:@data ;сегмент данных и все такое для ехе файла
	mov ax,@data
	mov es,ax 
	mov ds,ax
	
	;меню			
start:
	mov ax,03h ;3й текстовый режим 
    int 10h
	lea dx, message1
	mov ah,09h
	int 21h
re_entry:	
	mov ah,01h ;выбор действия
	int 21h 
	
	push ax ;перенос строки
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
    mov ax,03h ;3й текстовый режим 
    int 10h
    mov ax,0;инициализация мыши ;про 33е прерывание почитаешь и функции посмотришь в гугле т.к. может спросить
    int 33h

new1:
    mov op,0 ;переменная-флаг, не рисовать пока зажат пкм
new:
;сохраняем положение мыши в х и у
    mov ax,3
    int 33h
    shr cx,3;сдвигаем вправо (делим на 8) чтоб получить правильные координаты
    shr dx,3  
    mov x,cl ;сохраняем координаты в переменные 
    mov y,dl
    
    cmp bx, 0 ;если не нажата ни одна кнопка рисуем 
    je  write 
    cmp bx, 1 ;если нажать лкм выходим и сохраняем экран в файл 
    je sv
    cmp bx, 2 ;если нажата пкм не рисуем
    je new1
    cmp op,1
    je write
    jmp new 
sv:
	call saveb
	jmp exit
write:
    mov op,1
    
    cmp cl,opx2;проверяем движение курсора по х
    mov [opx2],cl;сохраняем положение курсора х
    
    ja mit1 ;если курсор движется по оси х в право то переходим на  mit1
    jb mit2;если влево то  mit2
    
    cmp dl,opy2;проверяем движение курсора по у
    mov [opy2],dl;сохраняем положение курсора у
    
    jb mit3;если по оси у вверх то mit3
    ja  mit4; вниз то mit4
    jmp new
	
	
mit1:
    mov ah,13h ; функция вывода
    mov al,0; режим вывода
    mov bl,7; цвет,
    mov cx,1; длина строки
    mov bp, offset g2  ;выводим символ "-"
    mov dh,y; строка
    mov dl,x; столбец
    int 10h
    jmp new
    
mit2:
    mov ah,13h
    mov al,0
    mov bl,7
    mov cx,1
    mov bp, offset g1 ;выводим символ "-"
    mov dh,y
    mov dl,x
    int 10h
    jmp new
    
mit3:
    mov ah,13h
    mov al,0
    mov bl,7
    mov cx,1
    mov bp, offset v2 ;выводим символ "|"
    mov dh,y
    mov dl,x
    int 10h
    jmp new
    
mit4:
    mov ah,13h
    mov al,0
    mov bl,7
    mov cx,1
    mov bp, offset v1 ;выводим символ "|"
    mov dh,y
    mov dl,x
    int 10h
    jmp new
	
exit:
	ret
task2 endp    
 
 
saveb proc
;запись в буфер
	mov   di,buff  ; DI для STOSB
	xor   bx,bx  ; страница(0)
	xor   dx,dx ; позиция курсора в окне(0:0)
save:                    
	mov   cx,80  ; сохранять будем по-строчно
line_out:                       
	mov   ah,2  ; позиционируем курсор
	int   10h              
	mov   ah,8 ; читаем символ с позиции
	int   10h            
	stosb  ; записываем его в буфер
	inc   dl ; сл.позиция в окне..
	loop  line_out ; сохраняем одну строку
 
	mov   ax,0A0Dh ; перевод строки в буфере
	STOSW                  
	xor   dl,dl  
	inc dh  ; ..и в окне
	cmp   dh,25  ; последняя строка?
	JNZ   save             
 
; сохранение в файл
	mov   ah,3Ch  ; создать..
	lea   dx,fName        
	mov   cx,20h          
	int   21h             
	xchg  bx,ax           
	mov   ah,40h ; читать..
	mov   DX,buff         
	mov   CX,2050         
	int   21h              
	mov   ah,3Eh; закрыть файл
	int   21h              
	ret   
saveb endp

exitp proc	;выход из программы			
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

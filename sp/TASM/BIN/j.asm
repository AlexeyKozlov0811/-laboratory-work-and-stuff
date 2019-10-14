.model tiny
.code
org 100h
.186
start:
	mov ax,12h ;X 12h+80h X ;включение видеорежима
	int 10h
	lea dx, message1
	mov ah,09h
	int 21h
re_entry:	
	mov ah,01h ;выбор действия
	int 21h 

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
	call exit
next3:
	jmp re_entry

;--------------------------------------
exit proc	;выход из программы			
	mov ah,4ch				
	int 21h
	ret
exit endp	
;--------------------------------------
task1 proc	;первая задача			
	call next_str
	call next_str		
	
	call input_A
	
	call next_str
	
	call out_array_A
	
	call next_str
	
	call check
	
	call next_str
	
	lea dx,message2
	mov ah,09h
	int 21h
	
	call out_buf
	
	lea dx,message3
	mov ah,09h
	int 21h
	
    mov ah,0 ;ввод с клавиатуры
    int 16h
	
	ret
task1 endp
;--------------------------------------
shift proc
	push cx
	push ax
	push si
	
	mov shift_n,cx
	mov ax,4
	sub ax,cx
	mov cx,ax
next10:	
	xor ax,ax
	dec si
	xchg al,A[si]
	add si,shift_n
	mov A[si],al
	sub si,shift_n
	loop next10
	
	pop si
	pop ax
	pop cx
	ret
shift endp
;--------------------------------------
input_A proc
	mov si,0 
enter_A:
	mov cx,4
enter_dg:
    mov ah,01h
    int 21h
	cmp al,0dh
	je next7
	sub al,30h
    mov A[si],al
    inc si
	loop enter_dg
	call next_str
	jmp next9
next7:
	call shift
next9:
	add si,cx
	cmp si,39
    jle enter_A
	
	ret
input_A endp
;--------------------------------------
digit proc
	push bx
	push si
	push cx

	xor dx,dx 

	mov ax,si
	mov bl,4
	mul bl
	mov si,ax	
	mov cx,4
	mov bx,10
	mov ax,1000
	
to_dec:
	push ax
	mov dl,A[si]
	mul dx 
	inc si
	add A_current,ax
	pop ax
	div bx
	loop to_dec
	
	pop cx
	pop si
	pop bx

	ret
digit endp
;--------------------------------------
check proc
	
	mov si,0
	call digit
	mov ax,A_current
	mov A_first,ax
	mov A_current,0
	
	mov si,9
	call digit
	mov ax,A_current
	mov A_last,ax
	mov A_current,0
	
	mov si,1
    mov cx,8
	mov bx,0
check_array:	;проверка массива по условию
	call digit
	mov ax,A_current
	cmp ax,A_first
	jg next4
	jmp pass
next4:
	cmp ax,A_last
	jl next5
	jmp pass
next5:
	mov ax,si	;заносим в массив ответ
	inc al
	cmp buf[0],0
	jne next6
	mov buf[0],al
next6:
	mov buf[1],al	
pass:
	inc si
	mov A_current,bx
	loop check_array
	ret
check endp
;--------------------------------------
out_array_A proc
	mov si,0
    mov cx,40
	mov bl,4
output_array: ;вывод массива
	mov ah,02h
	mov dl,A[si]
	add dl,30h
	int 21h	
	inc si
	
	mov ax,si
	div bl
	cmp ah,0
	jne next8
	mov ah,02h
	mov dl,' '
	int 21h
next8:
	
	loop output_array
	ret
out_array_A endp
;--------------------------------------
out_buf proc
	mov si,0
    mov cx,2
output_array2: ;вывод массива-ответа
	mov ah,02h
	mov dl,buf[si]
	add dl,30h
	int 21h	
	mov dl,' '
	int 21h	
	inc si
	loop output_array2
	ret
out_buf endp
;--------------------------------------
task2 proc
	mov ax,12h ;X 12h+80h X ;включение видеорежима
	int 10h
	mov ax,0 ; проверка драйверов мыши
	int 33h
	mov ax,1 ;вывод курсора
	int 33h

	mov ax,000Ch ; создание обработчика события
	mov cx,0002h ; нажатие на левую кнопку мыши
	mov dx,offset handler
	int 33h

	mov ah,0
	int 16h
	mov ax,000Ch ;удаляем 
	mov cx,0000h ;обработчик
	int 33h       ; событий
	mov ax,12h ;X 12h+80h X ;включение видеорежима
	int 10h
	ret
; Обработчик событий от мыши
handler:
	push 0A000h
	pop es
	push cs
	pop ds
	push cx
	push dx
 
	mov ax,2
	int 33h

	cmp word ptr previous_X,-1
	je first_point
 
	call line_bresenham
exit_handler:
	pop dx
	pop cx
	mov previous_X,cx
	mov previous_Y,dx

	mov ax,1
	int 33h
 
	retf
 
first_point:
	call putpixel1b
	jmp short exit_handler
 
;Процедура рисования прямой линии
line_bresenham:
	mov ax,cx
	sub ax,previous_X
	jns dx_pos
	neg ax
	mov word ptr X_increment,1
	jmp short dx_neg
dx_pos:
	mov word ptr X_increment,-1
 
dx_neg:
	mov bx,dx
	sub bx,previous_Y
	jns dy_pos
	neg bx
	mov word ptr Y_increment,1
	jmp short dy_neg
dy_pos:
	mov word ptr Y_increment,-1
dy_neg:
	shl ax,1
	shl bx,1
 
	call putpixel1b
 
	cmp ax,bx
	jna dx_le_dy
	mov di,ax
	shr di,1
	neg di
	add di,bx
cycle:
	cmp cx, word ptr previous_X
	je exit_bres
	cmp di,0
	jl fractlt0
	add dx,word ptr Y_increment
	sub di,ax
fractlt0:
	add cx,word ptr X_increment
	add di,bx
	call putpixel1b
	jmp short cycle
 
dx_le_dy:
	mov di,bx
	shr di,1
	neg di
	add di,ax
cycle2:
	cmp dx,word ptr previous_Y
	je exit_bres
	cmp di,0
	jl fractlt02
	add cx,word ptr X_increment
	sub di,bx
fractlt02:
	add dx,word ptr Y_increment
	add di,ax
	call putpixel1b
	jmp short cycle2
exit_bres:
	ret
; Процедура вывода точки на экран
putpixel1b:
	pusha
	xor bx,bx
	mov ax,dx
	imul ax,ax,80
	push cx
	shr cx,3
	add ax,cx
	mov di,ax
	mov si,di
 
	pop cx
	mov bx,0080h
	and cx,07h

	shr bx,cl
	lods es:byte ptr some_label
	or ax,bx
	stosb
	popa
	ret
task2 endp

next_str proc	;на следующую строку
	push dx
	push ax
	
	mov dl,13
	mov ah,02h
	int 21h
	mov dl,10
	mov ah,02h
	int 21h
	
	pop ax
	pop dx
	ret
next_str endp

previous_X dw -1
previous_Y dw -1
Y_increment dw-1
X_increment dw -1

message1 db 0dh, 0ah,"Choose task",0dh, 0ah,"Press 1 to Task-1 ",0dh, 0ah,"Press 2 to Task-2 ",0dh, 0ah,"Press 3 to exit from program ",0dh, 0ah,'$',0
message2 db "Indexes of elements that fit the condition(A[1] < A[i] < A[10]): $"
message3 db 0dh, 0ah,"Press any key",0dh, 0ah,"$",0

A db 40 dup(0)
A_first dw 0000
A_last dw 0000
A_current dw 0
buf db 0,0
shift_n dw 0

 
some_label:
 
end  start
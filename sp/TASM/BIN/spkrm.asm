model tiny
.386
.code
.startup

call task2
ret

task2 proc	;втора€ задача
	lea dx,message3
	mov ah,09h
	int 21h
	lea dx,message4
	int 21h
	mov ah,0 ;ввод с клавиатуры
    int 16h
	
	mov ax,12h; устанавливаем режим 320х240
    int 10h  
	
	mov	ax,0	;инициализаци§ мыши
	int	33h
	mov	ax,1	; показать курсор
	int	33h
	
	mov ax,0ch ;вызов обработчика
	mov	cx,0002h ;условие вызова
	mov dx,offset handle1
	int	33h
	
    mov ah,0 ;ввод с клавиатуры
    int 16h
	
	mov ax,000Ch ;закрытие обработчка
	mov cx,0000h
	int 33h
	
	mov ax,3 ;назад в текстовый режим
	int 10h
	
	ret
task2 endp	
;--------------------------------------	

;--------------------------------------	
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
;--------------------------------------	
draw_vert proc	;нарисовать вертикальную линию		 	
	push ax
	mov al,0Fh; цвет линий
a1: stosb
    add di,319
    loop a1	
	pop ax
	ret
draw_vert endp
;--------------------------------------	
draw_hor proc	;нарисовать горизонтальную линию			
	push ax
	mov al,0Fh; цвет линий
    rep stosb
	pop ax
	ret
draw_hor endp		
;--------------------------------------	
handle1 proc far ;обработчик мыши
	push cx
	push dx
    push 0A000h; начало видеопам§ти в графических режимах
    pop es
	
	cmp x1_pos,-1 ;проверка первого вызова обработчика
	jne draw
	mov y1_pos,dl
	mov x1_pos,cl
	;shr x1_pos,1
	jmp end_hand
draw:	;если не первый - рисуем пр€моугольник
	call line
end_hand:	
	pop dx
	pop cx
	
	ret 
handle1 endp	
;--------------------------------------	
line proc
	mov ah,2
	mov dh,1; <-Ёто строка =’
	mov dl,1; <-Ёто колонка =Y
	xor bh,bh
	int 10h
	
	
	mov ah,02h
	mov dl,196
	int 21h
	
	mov x1_pos,-1 ;возврат начального значени€ дл€ повторного рисовани€
	ret
line endp
;--------------------------------------	
; rectangle proc
	; mov ax,2 ;убрать курсор пока рисуем
	; int 33h
	
	; shr cx,1	
	; cmp cx,x1_pos	;выбор первой  точки с наименьшими координатами
	; jg pas1
	; xchg cx,x1_pos
; pas1:
	; cmp dx,y1_pos
	; jg pas2
	; xchg dx,y1_pos
; pas2:	
	; mov y2_pos,dx
	; mov x2_pos,cx	
	
	; shr cx,1
	; mov ax,320
	; mul y1_pos	;начальна€ точка
	; add ax,x1_pos	
	
	; mov di,ax	;лева€ сторона
    ; mov cx,y2_pos
	; sub cx,y1_pos
	; call draw_vert
		
	; mov di,ax	;верхн€€ сторона
	; mov cx,x2_pos
	; sub cx,x1_pos
	; call draw_hor
	
	; add ax,x2_pos	;права€ сторона
	; sub ax,x1_pos
	; mov di,ax
    ; mov cx,y2_pos
	; sub cx,y1_pos
	; call draw_vert
	; sub ax,x2_pos
	; add ax,x1_pos
	
	; mov ax,320	; нижн€€ сторона
	; mul y2_pos
	; add ax,x1_pos
	; mov di,ax
	; mov cx,x2_pos
	; sub cx,x1_pos
	; inc cx
	; call draw_hor
	
	; mov x1_pos,-1 ;возврат начального значени€ дл€ повторного рисовани€
	; ret
; rectangle endp
;--------------------------------------	
	ret ;конец программы

message1 db 0dh, 0ah,"Choose task",0dh, 0ah,"Press 1 to Task-1 ",0dh, 0ah,"Press 2 to Task-2 ",0dh, 0ah,"Press 3 to exit from program ",0dh, 0ah,'$',0
message2 db "Indexes of elements that fit the condition(A[1] < A[i] < A[10]): $"
message3 db 0dh, 0ah,"Select two points to build a rectangle $"
message4 db 0dh, 0ah,"Press any key",0dh, 0ah,"$",0

A db 40 dup(0)
A_first dw 0000
A_last dw 0000
A_current dw 0
buf db 0,0
shift_n dw 0


x1_pos db -1
y1_pos db 0
x2_pos db 0
y2_pos db 0

end

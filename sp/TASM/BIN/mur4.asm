model small
.stack 100h
	.data
msg1 db "Input array of 16 subols",0dh, 0ah,'$',0
msg2 db "Your matrix",0dh, 0ah,'$',0
msg3 db "Side diagonal of matrix",0dh, 0ah,'$',0
arr db 16 dup("$")
	.code

next_line proc;перенос строки
	push dx;знаносим данные используемых регистов в стек чтоб не потерять 
	push ax
	
	mov ah,02h
	mov dl,13
	int 21h
	mov dl,10
	int 21h
	
	pop ax;забираем данные обратно
	pop dx
	
	ret
next_line endp
	
	
input_array proc;ввод массива с клавиатуры 
	xor si,si;обнуляем регистр (ксор самый быстрый способ)             
enter_text:
    mov ah,01h;функция ввода
    int 21h
    mov arr[si],al;заносим введенный символ в массив
    inc si;инкремент индекса
	cmp si,15;сравнииваем индекс с максимальным его значением
    jle enter_text;если меньше повторяем цикл
	ret
input_array endp
	
output_array proc;вывод массива
	xor si,si;начальный индекс
    mov cx,16;количество символов
	mov bl,4;длина строки 
output:
	mov ah,02h;функция вывода 
	mov dl,arr[si];заносим значение массива в дл
	int 21h	
	inc si;инкремент индекса
	mov ax,si; индекс в ах
	div bl; деление ах на 4
	cmp ah,0	;если без остатка то на след строку
	jne cont ;если не равно не делаем перенос
		call next_line; перенос строки
	cont:
	loop output;цикл вывода
	ret
output_array endp
	
side_output proc;вывод боковой диагонали
	xor si,si;обнуляем индекс
    mov cx,16;кол-во символов
side_diag_out:
	mov dl,' ';вывод по умолчанию
	mov ax,si;проверяем кратность индекса 3м 
	mov bl,3
	div bl
	cmp ah,0
	jne next1
	mov dl,arr[si];если кратно ставим на вывод символ из массива
next1:
	cmp si, 0;проверяем что элемент не первый 
	jne next2
	mov dl,' ';если первый возвращаем пробел
next2:
	cmp si, 15;проверяем что элемент не последний 
	jne next3
	mov dl,' ';если последний возвращаем пробел
next3:
	mov ah,02h;функция вывода
	int 21h	
	inc si;инкремент индекса
	mov ax,si;проверяем конец строки кратностью 4м
	mov bl,4
	div bl
	cmp ah,0
	jne next4
		call next_line;если кратно перенос строки
next4:
	loop side_diag_out; пока не выведем 16 элементов повторяем цикл
	ret
side_output endp
	
	main proc
	mov ax,@data;сегмент данных или шото такое я хз 
	mov ds,ax;это туда же
	
	mov ah, 09h
	lea dx, msg1
	int 21h

	call input_array
	call next_line
	
	mov dx, offset msg2
	mov ah, 09h
	int 21h
	
	call output_array
	call next_line
	
	mov dx, offset msg3
	mov ah, 09h
	int 21h
	
	call side_output
	
	mov ax,4c00h;функция завершения программы 
	int 21h

	main endp
	end main
	code ends
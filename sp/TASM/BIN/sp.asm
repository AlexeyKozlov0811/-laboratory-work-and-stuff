model tiny 
.386
.code
.startup
	;code
	call menu
	
	
	
	
	

	
	
menu proc 
start:
	mov ah, 09h
	mov dx, offset message1
	int 21h
	
	mov ah, 01h
	int 21h
	
	cmp al, "1"
	jne next1
	call task1
	jmp start
next1:
	cmp al, "2"
	jne next2
	call task2
	jmp start
next2:
	cmp al, "0"
	jne start
	call exit
	jmp start

	ret
menu endp

exit proc
	mov ax,4c00h
	int 21h
	ret
exit endp

next_line proc
	mov ah, 02h
	mov dl, 0dh
	int 21h
	mov dl, 0ah
	int 21h
	ret
next_line endp

task1 proc
	call next_line

	call input_array ;разкоментить для ручного ввода
	
	call next_line
	call next_line
	
	call output_array
	
	call next_line
	
	call sum_array
	
	call next_line
	
	call sum_k
	
	ret
task1 endp

input_array proc
	mov ah, 09h
	mov dx, offset message2
	int 21h
	
	xor si,si
input_arr:
	mov cx,3;разрядность цифры 
input_digit:
	mov ah,01h
	int 21h
	cmp al,0dh
	je next3
	sub al,30h;чтоб преобразовать символ в число
	mov array[si], al
	inc si
	loop input_digit
	call next_line
	jmp next4
next3:
	call shift
next4:
	add si,cx
	cmp si,119 ;всего символов -1 -- максимальный индекс 
	jl input_arr
	ret
input_array endp

shift proc
	push cx
	push ax
	push si
	
	mov shift_n,cx
	mov ax,3 ;разрядность цифры 
	sub ax,cx
	mov cx,ax
next5:	
	xor ax,ax
	dec si
	xchg al,array[si]
	add si,shift_n
	mov array[si],al
	sub si,shift_n
	loop next5
	
	pop si
	pop ax
	pop cx
	ret
shift endp

output_array proc
	mov si,0
    mov cx,120 ;всего символов
	
output: ;вывод массива
	mov bl,3 ;разрядность цифры 
	mov ah,02h
	mov dl,array[si]
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
	
	mov bl,30 ;длина строки умноженая на разрядность цифры  
	mov ax,si
	div bl
	cmp ah,0
	jne next9
	call next_line
	
next9:
	loop output
	ret
	ret
output_array endp

digitize proc
	push si
	push cx
	xor dx,dx 

	mov ax,si
	mov bl,3 ;разрядность цифры  
	mul bl
	mov si,ax	
	mov cx,3 ;разрядность цифры  
	mov bx,10
	mov ax,100 ;максимальный вес числа, 10 в степени разрядность цифры  
	
to_dec:
	push ax
	xor eax,eax
	pop ax
	push ax
	
	mov dl,array[si]
	mul dx 
	inc si
	add digit,eax
	pop ax
	div bx
	loop to_dec
	
	pop cx
	pop si

	ret
digitize endp

sum_array proc
	mov si,0 
	mov cx,40 ;количество цифер в массиве 
sum:
	call digitize
	mov eax,digit
	add summ,eax
	xor eax,eax
	mov digit,eax
	inc si
	loop sum
	
	mov ah,09h
	lea dx,message3
	int 21h
	
	call ans_out
	
	xor eax,eax
	mov summ,eax
	
	ret
sum_array endp

ans_out proc
	std
	lea di,ansEnd-1
	mov eax,summ
	mov ecx,10
repea:
	xor edx,edx
	div ecx
	
	xchg eax,edx
	add eax,'0'
	stosb
	xchg eax,edx
	or eax,eax
	jne repea
	
	mov ah,09h
	lea dx,[di+1]
	int 21h
	ret
ans_out endp

sum_k proc
	mov ah,09h
	lea dx,message4
	int 21h	
	
	mov ah,01h
	int 21h
	sub al,31h
	xor dx,dx
	mov dl,al
	mov si,dx
	push dx
	mov cx,4 ;чисел в колонке 
sum2:
	call digitize
	mov eax,digit
	add summ,eax
	xor eax,eax
	mov digit,eax
	add si,10 ;длина рядка 
	loop sum2
	
	call next_line
	
	mov ah,09h
	lea dx,message5
	int 21h	
	
	call ans_out
	
	mov eax,1
	mov summ,eax
	
	call next_line

	mov ah,09h
	lea dx,message6
	int 21h
	
	mov cx,4 ;чисел в колонке 
	pop dx
	mov si,dx
	xor ebx,ebx
mul1:
	call digitize
	mov eax,digit
	mov ebx,summ
	mul ebx
	mov summ,eax
	xor eax,eax
	mov digit,eax
	add si,10 ;длина рядка 
	loop mul1
	
	call ans_out
	call next_line
	
	ret
sum_k endp


task2 proc
	call next_line
start1:
	mov ah, 09h
	mov dx, offset message7
	int 21h
	
	mov ah, 01h
	int 21h
	
	cmp al, "1"
	jne next21
	call next_line
	call look
	jmp start1
next21:
	cmp al, "2"
	jne next22
	call next_line
	call change
	jmp start1
next22:
	cmp al, "3"
	jne next23
	call next_line
	call move
	jmp start1
	
next23:
	cmp al, "0"
	jne start1
	call next_line
	ret
task2 endp
;---------------------------------------------
look proc
	lea dx,DTA				;встановлення адресу зміщення для							
	mov ah,1ah				;локального буфера
	int 21h

	call Find_First				;пошук першого файла
	jc exit1					;якщо нема файлів перейти до exit1  
	call Out_Info				;виведення даних про файл

cukl:
	call Find_Next				;пошук наступного файла      
	jc exit2					;якщо нема файлів перейти до exit2 
	call Out_Info				;виведення даних про файл
	loop cukl					;перейти до cukl

exit1: 
	lea dx,info				;виведення даних info
	mov ah,09h
	int 21h

exit2:
	call next_line
	ret
look endp

change proc
	mov ah,09h
	lea dx,message8
	int 21h
	; Входные данные: смещение строки в AX
	; Выходные данные: строка ASCIIZ, прочитанная с клавиатуры. Регистры не сохраняются.
	lea dx,Path
	mov cx,255 ;максимальное количество читаемых символов
	mov bx,0   ;файловый хэндл клавиатуры
	mov ah,3Fh ;читаем из файла (фактически - с клавиатуры)
	int 21h
	jc Input$_error ;если ошибка
	dec AX     ;убираем символ RETURN
	mov si,AX  ;смещение байта, расположенного в конце строки
	Input$_error:
	mov Path[si-1],00h ;завершаем строку, записывая 0 в конец строки
	mov Path[si],0Ah ;завершаем строку, записывая 0 в конец строки

	call next_line
	ret
change endp

move proc
	mov ah,09h
	lea dx,message9
	int 21h
	
	lea dx,FileF
	mov cx,255 ;максимальное количество читаемых символов
	mov bx,0   ;файловый хэндл клавиатуры
	mov ah,3Fh ;читаем из файла (фактически - с клавиатуры)
	int 21h
	jc Input$_error1 ;если ошибка
	dec AX     ;убираем символ RETURN
	mov si,AX  ;смещение байта, расположенного в конце строки
	Input$_error1:
	mov FileF[si-1],00h ;завершаем строку, записывая 0 в конец строки
	mov FileF[si],0Ah ;завершаем строку, записывая 0 в конец строки

	mov ah,09h
	lea dx,message10
	int 21h
	
	lea dx,FileS
	mov cx,255 ;максимальное количество читаемых символов
	mov bx,0   ;файловый хэндл клавиатуры
	mov ah,3Fh ;читаем из файла (фактически - с клавиатуры)
	int 21h
	jc Input$_error2 ;если ошибка
	dec AX     ;убираем символ RETURN
	mov si,AX  ;смещение байта, расположенного в конце строки
	Input$_error2:
	mov FileS[si-1],00h ;завершаем строку, записывая 0 в конец строки
	mov FileS[si],0Ah ;завершаем строку, записывая 0 в конец строки
	
	mov ah,56h
	lea dx,FileF
	lea di,FileS
	int 21h
	
	jc absent
	jmp ex
absent:
	lea dx,info				;виведення даних info
	mov ah,09h
	int 21h
ex:	
	call next_line
	ret
move endp
;----------------------------------------------------------------
Find_First proc					;пошук першого файла
        lea dx,Path				;загрузка в dx адреса строки Path
        mov cx,00					;встановлення атрибутів
        mov ah,4eh				;виклик функції для пошуку
        int 21h
        ret
Find_First endp

Find_Next proc					;пошук наступного файла      
        lea dx,Path				;загрузка в dx адреса строки Path
        mov cx,00					;встановлення атрибутів
        mov ah,4fh				;виклик функції для пошуку
        int 21h
        ret
Find_Next endp

Out_Info proc					;виведення даних про файл
;------------------------------------------------------------------
        						;вивід імені файла
  lea dx,strk				;загрузка в dx адреса строки strk
        mov ah,9h       			;для переведення курсора на 
        int 21h					;наступний рядок

        mov cx,0dh				;запис в cx 0dh – кілкість байтів, 
        						;які буде виводити ф-я 40h
  mov bx,1eh				; імені
        						;імені файла відносно DTA	
  lea dx,DTA + bx				; загрузка в dx адреса зміщення 
        						;імені файла
  mov bx,1					;запис в bx=1, див. використання 	
        						;функції 40h 
  mov ah,40h				;виклик функції 40h
        int 21h

Out_Info endp


	ret
	;data
DTA db 50 dup(?),'$'        ;локальний буфер інформації про файл
FileF db 0
FileS db 0
Path db "D:\1\*.*",0			;шлях і маска пошуку файлів 
strk db 0ah,0dh,'$'			;перев. курсора на поч. наступного рядка
Info db 'Files are absent!!!$'  
newPath dw "",0
	
	
ans db 100 dup(0),'$'
ansEnd = $-1
summ dd 0
digit dd 0
message1 db "Choose an action ", 0dh, 0ah, "1 - First program" , 0dh, 0ah, "2 - Second program", 0dh, 0ah, "0 - Exit" , 0dh, 0ah, "$"
message2 db "Input 40 numbers", 0dh, 0ah, "$"
message3 db "Summation of all elements = $";, 0dh, 0ah,"$"
message4 db "Input number of column: $"
message5 db "Summation of elements of culumn = $"
message6 db "Multiplication of elements of culumn = $"
message7 db "Choose an action ", 0dh, 0ah, "1 - View the catalog" , 0dh, 0ah, "2 - Change catalog", 0dh, 0ah, "3 - Move catalog", 0dh, 0ah,"0 - Exit" , 0dh, 0ah, "$"
message8 db "Input new path and *.*", 0dh, 0ah, "$"
message9 db "Input old path and file name", 0dh, 0ah, "$"
message10 db "Input new path and file name", 0dh, 0ah, "$"
array db 120 dup(0) ; тут можно поменять количество символов в одной ячейке надо чтоб было кратно 40, в дуп поставишь на ноль если будет ввод с клавиатуры
shift_n dw 0


	end
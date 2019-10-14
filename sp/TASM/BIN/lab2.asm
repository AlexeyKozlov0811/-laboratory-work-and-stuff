model tiny 
.code
.startup

	mov ah, 09h
	mov dx, offset message
	int 21h

	mov dx, offset Sos ; встановлюємо вказівник на строку
	mov ah,0Ah 
	int 21h ; введення строки

	mov cl,[Sos + 1] ; встановлюємо лічильник

lst: ; початок циклу   
	mov di,cx
	cmp Sos[di+1],60h ; перевірка, чи літера маленька
	jg next ; якщо літера велика – йдемо далі
	add Sos[di+1],20h ; якщо маленька – змінюємо її
next:
	loop lst ; перехід на початок циклу
	mov dx, offset Sos + 2 ; кінець циклу, встановити вказівник на рядок
	mov ah,9
	int 21h ; виведення строки
	
	ret
	
Sos     db 20 dup("$") ; змінна-рядок
message db "Input string",0dh, 0ah,'$',0

	end

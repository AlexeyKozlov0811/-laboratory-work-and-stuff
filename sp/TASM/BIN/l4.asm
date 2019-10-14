data segment para public 'data'
        countItems      equ     15
        array db 16 dup(?)
        enter_mas       db      'vvedi massiv,$'
        output_mas      db      'massiv: $'
data ends
 
stacks segment stack
        db      32      dup     (?)
stacks ends
 
code segment para public 'code'
        main    proc
                assume cs:code, ds:data, ss:stacks
                
                mov     ax,data
                mov     ds,ax
                
                ;для вывода строки
                mov ah,9
                mov     dx,offset enter_mas
                int 21h
 
                ;вот он переход
                mov dl,13 ; перехід на наступну строку, і встановлення курсора на початок строки, коли 1 рядок масива буде виведено
				mov ah,02h
				int 21h
				mov dl,10
				mov ah,02h
				int 21h
                
                xor ax,ax       ;чистим ax
                
                mov cx,16
                mov si,0
                
                jmp enter_text
                
        enter_text:
                mov ah,1h
                int     21h
                
                sub al,30h
                mov array[si],al
                inc si
                
                cmp si,countItems
                jle     enter_text
 
				mov dl,13 ; перехід на наступну строку, і встановлення курсора на початок строки, коли 1 рядок масива буде виведено
				mov ah,02h
				int 21h
				mov dl,10
				mov ah,02h
				int 21h
				
                mov cx,16
                mov si,0
                mov ah,09h
                lea dx,output_mas
                int 21h
 
                mov si,0
                mov cx,16
        
        output_array:
                mov ah,02h
                mov dl,array[si]
                add dl,30h
                int 21h
                inc si
                loop output_array
        
                
                ;завершение программы
                mov     ax,4c00h
                int     21h
        main endp
code ends
end     main
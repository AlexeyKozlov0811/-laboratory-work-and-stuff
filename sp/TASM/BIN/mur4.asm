model small
.stack 100h
	.data
msg1 db "Input array of 16 subols",0dh, 0ah,'$',0
msg2 db "Your matrix",0dh, 0ah,'$',0
msg3 db "Side diagonal of matrix",0dh, 0ah,'$',0
arr db 16 dup("$")
	.code

next_line proc;������� ������
	push dx;�������� ������ ������������ �������� � ���� ���� �� �������� 
	push ax
	
	mov ah,02h
	mov dl,13
	int 21h
	mov dl,10
	int 21h
	
	pop ax;�������� ������ �������
	pop dx
	
	ret
next_line endp
	
	
input_array proc;���� ������� � ���������� 
	xor si,si;�������� ������� (���� ����� ������� ������)             
enter_text:
    mov ah,01h;������� �����
    int 21h
    mov arr[si],al;������� ��������� ������ � ������
    inc si;��������� �������
	cmp si,15;����������� ������ � ������������ ��� ���������
    jle enter_text;���� ������ ��������� ����
	ret
input_array endp
	
output_array proc;����� �������
	xor si,si;��������� ������
    mov cx,16;���������� ��������
	mov bl,4;����� ������ 
output:
	mov ah,02h;������� ������ 
	mov dl,arr[si];������� �������� ������� � ��
	int 21h	
	inc si;��������� �������
	mov ax,si; ������ � ��
	div bl; ������� �� �� 4
	cmp ah,0	;���� ��� ������� �� �� ���� ������
	jne cont ;���� �� ����� �� ������ �������
		call next_line; ������� ������
	cont:
	loop output;���� ������
	ret
output_array endp
	
side_output proc;����� ������� ���������
	xor si,si;�������� ������
    mov cx,16;���-�� ��������
side_diag_out:
	mov dl,' ';����� �� ���������
	mov ax,si;��������� ��������� ������� 3� 
	mov bl,3
	div bl
	cmp ah,0
	jne next1
	mov dl,arr[si];���� ������ ������ �� ����� ������ �� �������
next1:
	cmp si, 0;��������� ��� ������� �� ������ 
	jne next2
	mov dl,' ';���� ������ ���������� ������
next2:
	cmp si, 15;��������� ��� ������� �� ��������� 
	jne next3
	mov dl,' ';���� ��������� ���������� ������
next3:
	mov ah,02h;������� ������
	int 21h	
	inc si;��������� �������
	mov ax,si;��������� ����� ������ ���������� 4�
	mov bl,4
	div bl
	cmp ah,0
	jne next4
		call next_line;���� ������ ������� ������
next4:
	loop side_diag_out; ���� �� ������� 16 ��������� ��������� ����
	ret
side_output endp
	
	main proc
	mov ax,@data;������� ������ ��� ���� ����� � �� 
	mov ds,ax;��� ���� ��
	
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
	
	mov ax,4c00h;������� ���������� ��������� 
	int 21h

	main endp
	end main
	code ends
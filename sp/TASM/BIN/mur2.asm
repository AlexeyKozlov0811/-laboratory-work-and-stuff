model small
.stack 100h
	.data
message db "Input string",0dh, 0ah,'$',0
Sos db 20 dup("$") ; �����-�����

	.code
	main proc
	mov ax,@data
	mov ds,ax
	
	mov ah, 09h
	mov dx, offset message
	int 21h
	
    mov dx, offset Sos ; ������������ �������� �� ������
    mov ah,0Ah 
    int 21h ; �������� ������

    mov cl,[Sos + 1] ; ������������ ��������
	
lst: ; ������� �����   
    mov di,cx
    cmp Sos[di+1],60h ; ��������, �� ����� ������
    jg next ; ���� ����� ���� � ����� ���
    add Sos[di+1],20h ; ���� ������ � ������� ��
next:
    loop lst ; ������� �� ������� �����
    mov dx, offset Sos + 2 ; ����� �����, ���������� �������� �� �����
    mov ah,9
    int 21h ; ��������� ������
	  
	mov ax,4c00h
	int 21h
	
	main endp
	end main
	code ends
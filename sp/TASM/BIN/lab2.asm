model tiny 
.code
.startup

	mov ah, 09h
	mov dx, offset message
	int 21h

	mov dx, offset Sos ; ������������ �������� �� ������
	mov ah,0Ah 
	int 21h ; �������� ������

	mov cl,[Sos + 1] ; ������������ ��������

lst: ; ������� �����   
	mov di,cx
	cmp Sos[di+1],60h ; ��������, �� ����� ��������
	jg next ; ���� ����� ������ � ����� ���
	add Sos[di+1],20h ; ���� �������� � ������� ��
next:
	loop lst ; ������� �� ������� �����
	mov dx, offset Sos + 2 ; ����� �����, ���������� �������� �� �����
	mov ah,9
	int 21h ; ��������� ������
	
	ret
	
Sos     db 20 dup("$") ; �����-�����
message db "Input string",0dh, 0ah,'$',0

	end

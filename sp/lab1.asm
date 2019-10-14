.model tiny
.code
ORG 100h

start:
    mov AH, 09h
    mov DX, offset string
    int 21h
    ret
    
string DB 'Hello, World!!!$'
end start
    
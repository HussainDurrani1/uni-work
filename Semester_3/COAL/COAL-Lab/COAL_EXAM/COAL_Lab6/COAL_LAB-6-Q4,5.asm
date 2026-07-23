.model small
.stack 100h

.data
M1 db 1,2,3,4,
      5,6,7,8,
      9,3,5,1
              
     ;1 5 9
     ;2 6 3 
     ;3 7 8 
     ;4 8 1        
              
M2 db 12 dup(?)

row_count dw ?
msg_done db "Transpose complete!$"

.code
main proc far
    mov ax, @data
    mov ds, ax

    mov bx, offset M1
    mov di, offset M2

    mov cx, 3
    row_loop:
        push cx
    
        mov cx, 4
    col_loop:
        mov al, [BX]
        mov [di], al
    
        inc BX
        add di, 3
        loop col_loop
    
        pop cx
        add bx, 1
        sub di, 11
        loop row_loop

    mov dx, offset msg_done
    mov ah, 09h
    int 21h

    mov ah, 4Ch
    int 21h
main endp
end main

; ----------------------------------------------------------------


.model small
.stack 100h

.data
M1 db 1,2,3,4,
    5,6,7,8,
    9,3,5,1

M2 db 2,4,6,8,
    1,3,5,7,
    9,8,7,6

M3 db 12 dup(?)

row_count dw ?
msg_done db "Matrix addition complete!$"

.code
main proc far
    mov ax, @data
    mov ds, ax

    mov bx, offset M1
    mov si, offset M2
    mov di, offset M3


    mov cx, 12
    col_loop:
        mov al, [bx]
        add al, [si]
        mov [di], al
    
        inc bx
        inc si
        inc di
        loop col_loop
    

    mov dx, offset msg_done
    mov ah, 09h
    int 21h

    mov ah, 4Ch
    int 21h
main endp
end main

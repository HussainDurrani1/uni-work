.model small
.stack 100h

.data
ARR     dw 1, 2, 3, 4, 9, 7, 8, 5, 3, 6
NUM     dw 5
INDEX   dw 0

.code
MAIN PROC NEAR
    mov ax, @data
    mov ds, ax
    
    push offset ARR     
    push NUM            

    call FIND_INDEX     
    
    mov ah, 4Ch
    int 21h
MAIN ENDP

;------------------------------------------------

FIND_INDEX PROC
    push bp
    mov bp, sp

    mov ax, [bp+4]     
    mov bx, [bp+6]     

    mov si, 0
    mov cx, 10
    mov INDEX, 0

LOOP_ARR:
    cmp ax, [bx+si]
    je FOUND
    inc INDEX
    add si, 2
    loop LOOP_ARR
    jmp NOT_FOUND

FOUND:
    mov dx, INDEX
    jmp EXIT_SUB

NOT_FOUND:
    mov dx, 0FFFFh

EXIT_SUB:
    pop bp
    ret 4
FIND_INDEX ENDP

END MAIN
.exit

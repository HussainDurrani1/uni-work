; Q1
;PART A
.model small
.stack 100h
.data
    NUM       db 13
    BIT_COUNT db ?

.code
main proc
    mov ax, @data
    mov ds, ax

    mov al, NUM
    mov bl, al
    and bl, 1
    cmp bl, 0
    jne COUNT_ONES

COUNT_ZEROS:
    mov bl, al
    mov cl, 8
    mov dl, 0
CZ_LOOP:
    shr bl, 1
    jc CZ_SKIP
    inc dl
CZ_SKIP:
    loop CZ_LOOP
    mov BIT_COUNT, dl
    jmp END

COUNT_ONES:
    mov bl, al
    mov cl, 8
    mov dl, 0
CO_LOOP:
    shr bl, 1
    jnc CO_SKIP
    inc dl
CO_SKIP:
    loop CO_LOOP
    mov BIT_COUNT, dl

END:
    mov ah, 4Ch
    int 21h
main endp
end main


; PART B
.model small
.stack 100h
.data
    ARR dw 5, 7, 3, 4

.code
main proc
    mov ax, @data
    mov ds, ax

    lea si, ARR
    mov ax, [si]
    add ax, [si+2]
    sub ax, [si+4]
    add ax, [si+6]

    mov bx, ax
    and bx, 1
    cmp bx, 0
    jne ODD

EVEN:
    mov es, 2222h
    mov di, 000Ah
    mov [es:di], ax
    jmp EXIT

ODD:
    mov es, 3333h
    mov di, 000Ah
    mov [es:di], ax

EXIT:
    mov ah, 4Ch
    int 21h
main endp
end main



; Q 2
.model small
.stack 100h
.data
    ARR dw 9, 4, 1, 7, 3, 8, 2, 6, 5, 0

.code
main proc
    mov ax, @data
    mov ds, ax

    lea si, ARR
    mov cx, 10

OUTER:
    mov bx, cx
    dec bx
    lea si, ARR

INNER:
    mov ax, [si]
    cmp ax, [si+2]
    jbe SKIP
    xchg ax, [si+2]
    mov [si], ax

SKIP:
    add si, 2
    dec bx
    jnz INNER

    dec cx
    jnz OUTER

    mov ah, 4Ch
    int 21h
main endp
end main

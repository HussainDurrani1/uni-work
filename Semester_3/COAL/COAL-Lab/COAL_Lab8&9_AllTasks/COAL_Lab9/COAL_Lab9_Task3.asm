.model small
.stack 100h
.data
    msg1    db 0Dh, 0Ah, "Enter First Num: $"
    msg2    db 0Dh, 0Ah, "Enter Second Num: $"
    msgSum  db 0Dh, 0Ah, "Sum: $"
    NUM1    dw ?
    NUM2    dw ?
    TOTAL   dw ?

.code
MAIN PROC
    MOV AX, @data
    MOV DS, AX

    ; --- INPUT 1 ---
    MOV AH, 09h
    LEA DX, msg1
    INT 21h
    CALL INPUT_HEX    ; Returns value in BX
    MOV NUM1, BX

    ; --- INPUT 2 ---
    MOV AH, 09h
    LEA DX, msg2
    INT 21h
    CALL INPUT_HEX    ; Returns value in BX
    MOV NUM2, BX

    ; --- ADDITION ---
    MOV AX, NUM1
    ADD AX, NUM2
    MOV TOTAL, AX

    ; --- OUTPUT ---
    MOV AH, 09h
    LEA DX, msgSum
    INT 21h
    
    MOV BX, TOTAL
    CALL PRINT_HEX

    MOV AH, 4Ch
    INT 21h
MAIN ENDP

; Procedure to Input 16-bit Hex (Result in BX)
INPUT_HEX PROC
    XOR BX, BX
    MOV CX, 4
NEXT_IN:
    SHL BX, 4
    MOV AH, 01h
    INT 21h
    CMP AL, '9'
    JBE DIGIT_IN
    SUB AL, 7
DIGIT_IN:
    SUB AL, 30h
    MOV AH, 0
    ADD BX, AX
    LOOP NEXT_IN
    RET
INPUT_HEX ENDP

; Procedure to Print 16-bit Hex (Value in BX)
PRINT_HEX PROC
    MOV CX, 4
NEXT_OUT:
    ROL BX, 4
    MOV DL, BL
    AND DL, 0Fh
    CMP DL, 9
    JBE DIGIT_OUT
    ADD DL, 7
DIGIT_OUT:
    ADD DL, 30h
    MOV AH, 02h
    INT 21h
    LOOP NEXT_OUT
    RET
PRINT_HEX ENDP
END MAIN
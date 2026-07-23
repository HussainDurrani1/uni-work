.model small
.stack 100h
.data
    msgPrompt db "Enter 4-digit Hex Number: $"
    NUM dw 0          ; Variable to store the 16-bit result

.code
MAIN PROC
    MOV AX, @data
    MOV DS, AX

    ; Print Prompt
    MOV AH, 09h
    LEA DX, msgPrompt
    INT 21h

    ; Initialize BX to 0 (This will hold our number)
    XOR BX, BX
    MOV CX, 4         ; Loop 4 times for 4 hex digits

INPUT_LOOP:
    ; Shift BX left by 4 bits to make room for new digit
    SHL BX, 4

    ; Read Single Character
    MOV AH, 01h
    INT 21h

    ; Convert ASCII to Hex Value
    CMP AL, '9'
    JBE IS_DIGIT      ; If '0'-'9', jump
    SUB AL, 7         ; If 'A'-'F', subtract extra 7 (ASCII Gap)
IS_DIGIT:
    SUB AL, 30h       ; Convert ASCII to Integer
    
    ; Add new digit to BX
    MOV AH, 0
    ADD BX, AX        ; Accumulate result in BX
    
    LOOP INPUT_LOOP

    ; Store result in variable
    MOV NUM, BX

    ; Terminate
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
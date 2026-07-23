.model small
.stack 100h
.data
    NUM dw 0ABCDh     ; The 16-bit number to print
    msgOut db 0Dh, 0Ah, "Value in Hex: $"

.code
MAIN PROC
    MOV AX, @data
    MOV DS, AX

    ; Print Label
    MOV AH, 09h
    LEA DX, msgOut
    INT 21h

    MOV BX, NUM       ; Load the number into BX
    MOV CX, 4         ; We need to print 4 nibbles (4 hex digits)

PRINT_LOOP:
    ; Rotate BX left by 4 so MSB nibble moves to LSB
    ROL BX, 4
    
    MOV DL, BL        ; Move lower byte to DL
    AND DL, 0Fh       ; Mask out everything except the last nibble

    ; Convert Value to ASCII
    CMP DL, 9
    JBE PRINT_DIGIT
    ADD DL, 7         ; Adjust for A-F
PRINT_DIGIT:
    ADD DL, 30h       ; ASCII conversion

    ; Print Character
    MOV AH, 02h
    INT 21h
    
    LOOP PRINT_LOOP

    ; Terminate
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
; Task 1:
.model small
.stack 100h
.data
    ROW db 0
    COL db 0
    msg db "Hello, this is Task 1!", 0

.code
MAIN PROC
    MOV AX, @data
    MOV DS, AX
    
    ; Initialize Video Segment
    MOV AX, 0B800h
    MOV ES, AX
    
    ; Point SI to our message
    LEA SI, msg
    CALL PRINT_STR
    
    MOV AH, 4Ch
    INT 21h
MAIN ENDP

;---------------------------------------------------------
; Procedure: PRINT_STR
;---------------------------------------------------------
PRINT_STR PROC
    PUSH AX
    PUSH BX
    PUSH DX
    PUSH DI

NEXT_CHAR:
    LODSB               ; Load byte at DS:SI into AL, increment SI
    CMP AL, 0           ; Check for null terminator
    JE EXIT_PRINT
    
    ;Linear Address: 2 * (Row * 80 + Col)
    MOV AH, 0
    MOV AL, ROW
    MOV BL, 80
    MUL BL              ; AX = Row * 80
    MOV BL, COL
    MOV BH, 0
    ADD AX, BX          ; AX = (Row * 80) + Col
    SHL AX, 1           ; AX = AX * 2
    MOV DI, AX          ; Move result to DI for addressing
    
    ; Write Character and Attribute to Video Memory
    MOV AL, [SI-1]      ; Reload the character
    MOV ES:[DI], AL     ; Store ASCII code
    MOV ES:[DI+1], 07h  ; Store Attribute (White on Black)
    
    ; Update Cursor
    INC COL     ; COL++
    CMP COL, 80         ; Check if end of row
    JNE NEXT_CHAR
    
    ; Wrap to next line if COL >= 80
    MOV COL, 0
    INC ROW
    JMP NEXT_CHAR

EXIT_PRINT:
    POP DI
    POP DX
    POP BX
    POP AX
    RET
PRINT_STR ENDP
END MAIN
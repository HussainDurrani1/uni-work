; Task 2: 
.model small
.stack 100h
.data
    ROW db 0
    COL db 0

    msg db "Name:", 9, "Hussain Durrani", 13, 10, "Age:", 9, "19", 13, 10, "Roll No:", 9, "L1F24BSCS0937", 0

.code
MAIN PROC
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0B800h
    MOV ES, AX
    
    LEA SI, msg
    CALL PRINT_STR
    
    MOV AH, 4Ch
    INT 21h
MAIN ENDP

PRINT_STR PROC
    PUSH AX
    PUSH BX
    PUSH DX
    PUSH DI

PROCESS_CHAR:
    LODSB               
    CMP AL, 0           
    JE DONE_PRINTING
    
    
    CMP AL, 0Dh    
    JE HANDLE_CR
    
    CMP AL, 0Ah     
    JE HANDLE_NL
    
    CMP AL, 09h   
    JE HANDLE_TAB
    
  
    
    ; Calculate Offset
    PUSH AX             ; Save Char
    MOV AL, ROW
    MOV BL, 80
    MUL BL
    MOV BL, COL
    MOV BH, 0
    ADD AX, BX
    SHL AX, 1
    MOV DI, AX
    POP AX              ; Restore Char
    
    MOV ES:[DI], AL     
    MOV ES:[DI+1], 07h  
    
    INC COL
    CMP COL, 80
    JL PROCESS_CHAR     ; If COL < 80, continue
    
    
    ; Fall through to Newline logic if Col >= 80
    MOV COL, 0
    INC ROW
    JMP PROCESS_CHAR

HANDLE_CR:
    MOV COL, 0 
    JMP PROCESS_CHAR

HANDLE_NL:
    INC ROW
    JMP PROCESS_CHAR

HANDLE_TAB:
    ADD COL, 8
    CMP COL, 80
    JL PROCESS_CHAR
    MOV COL, 0   
    INC ROW
    JMP PROCESS_CHAR

DONE_PRINTING:
    POP DI
    POP DX
    POP BX
    POP AX
    RET
PRINT_STR ENDP
END MAIN
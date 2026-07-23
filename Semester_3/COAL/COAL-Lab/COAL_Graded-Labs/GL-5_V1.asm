.model small
.stack 100h

.data
msg1 dB ' is: $'
msg2 dB 'SQAURE OF $'
msgE dB 'EVEN. $'
msgO dB 'ODD. $'
msgNL dB 0Dh, 0Ah, '$'

NUM dB 9
SQUARE dW ?
IsOdd dB ?

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0
    MOV ES, AX
    
    MOV WORD PTR ES:[7Fh*4+0], OFFSET ISR7F
    MOV WORD PTR ES:[7Fh*4+2], CS
    
    ; SERVICE 1:
    SUB BX, BX
    MOV BL, NUM
    PUSH BX
    MOV AH, 01
    INT 7Fh
    ADD SP, 2          ; Clean stack
    MOV SQUARE, AX
    
    ; SERVICE 2:
    MOV BX, SQUARE 
    PUSH BX
    MOV AH, 02h
    INT 7Fh
    ADD SP, 2          ; Clean stack
    MOV IsOdd, AL
    
    JMP ENDCODE
    
MAIN ENDP

ISR7F PROC FAR
    CMP AH, 01h
    JE SERVICE_SQUARE
    
    CMP AH, 02h
    JE SERVICE_CHECK_EvenOdd
    
    IRET
    
    SERVICE_SQUARE:
        PUSH BP
        MOV BP, SP
        PUSH BX
        PUSH DX
        PUSH CX
        
        MOV BX, [BP+8]
        MOV AL, BL
        MOV AH, 0h
        MUL BL
        MOV CX, AX
        
        MOV AH, 09h
        LEA DX, msg2
        INT 21h
        
        MOV AX, 0
        MOV AL, [BP+8]
        CALL PRINT_NUM_AX
        
        MOV AH, 09h
        LEA DX, msg1
        INT 21h
        
        MOV AX, CX
        CALL PRINT_NUM_AX
        
        LEA DX, msgNL
        MOV AH, 09h
        INT 21h
        
        MOV AX, CX
        
        POP CX
        POP DX
        POP BX
        POP BP
        IRET
    
    
    SERVICE_CHECK_EvenOdd:
        PUSH BP
        MOV BP, SP
        PUSH BX
        PUSH DX
        
        MOV BX, [BP+8]
        MOV AX, BX
        CALL PRINT_NUM_AX
        
        MOV AH, 09h
        LEA DX, msg1
        INT 21h
        
        ROR BX, 1
        JC ODD
        JMP EVEN
        
        EVEN:
            MOV AH, 09h
            LEA DX, msgE
            INT 21h
            MOV AX, 0
            JMP EXIT_SRV2
            
        ODD:
            MOV AH, 09h
            LEA DX, msgO
            INT 21h
            MOV AX, 1
            
        EXIT_SRV2:
            LEA DX, msgNL
            MOV AH, 09h
            INT 21h
            
            POP DX
            POP BX
            POP BP
            IRET
    
ISR7F ENDP    

PRINT_NUM_AX PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    CMP AX, 0
    JNE START_PRINT

    MOV DL, '0'
    MOV AH, 02h
    INT 21h
    JMP END_PRINT

START_PRINT:
    MOV BX, 10
    MOV CX, 0

PUSH_DIGITS:
    MOV DX, 0
    DIV BX
    PUSH DX
    INC CX
    CMP AX, 0
    JNE PUSH_DIGITS

PRINT_LOOP:
    POP DX
    ADD DL, 30h
    MOV AH, 02h
    INT 21h
    LOOP PRINT_LOOP

END_PRINT:
    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUM_AX ENDP

ENDCODE:
    MOV AH, 4Ch
    INT 21h
    END MAIN
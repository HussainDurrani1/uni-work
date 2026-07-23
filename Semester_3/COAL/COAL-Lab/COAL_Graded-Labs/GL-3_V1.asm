; PART C:
.model small
.stack 100h

.data
ARR dB 1, 2, 3, 4, 5, 6, 7, 8, 9
SIZE dW 9

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    PUSH OFFSET ARR
    PUSH SIZE
    ;CALL SUM_ODD_NUMS
    
    JMP END_CODE
        
MAIN ENDP

SUM_ODD_NUMS PROC
    PUSH BP
    MOV BP, SP
    MOV CX, [BP+4]
    MOV BX, [BP+6]   
    
    ;DO IT FURTHER
    
    POP BP
    RET 4 
SUM_ODD_NUMS ENDP    

END_CODE:
    MOV AH, 4ch
    INT 21h
    END MAIN



;==============================================







; PART B:
.model small
.stack 100h

.data
RESULT dW ?

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    PUSH 5000h
    PUSH 8000h
    CALL SUBTRACT_NUM
    MOV RESULT, AX
    
    JMP END_CODE
        
MAIN ENDP

SUBTRACT_NUM PROC
    PUSH BP
    MOV BP, SP
    MOV AX, [BP+4]
    MOV BX, [BP+6]
    SUB AX, BX    
    
    POP BP
    RET 4 
SUBTRACT_NUM ENDP    

END_CODE:
    MOV AH, 4ch
    INT 21h
    END MAIN



;==============================================


; PART A:
.model small
.stack 100h

.data


.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 4444h
    MOV BX, 1111h
    MOV CX, 2222h
    MOV DX, 3333h
    
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    
    ; DX
    ; CX
    ; BX
    ; AX
        
    POP AX
    POP DX
    POP CX
    POP BX

    END_CODE:
        MOV AH, 4ch
        INT 21h
        
MAIN ENDP
END MAIN
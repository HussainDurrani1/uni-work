; Problem Statement #1
; Calculator
.model small 
.stack 100h 
.data 
    SUM_NUM1  db ? 
    SUM_NUM2  db ?
    
    DIFF_NUM1 db ? 
    DIFF_NUM2 db ?
    
    PROD_NUM1 db ? 
    PROD_NUM2 db ?
    
    DIV_NUM1  db ? 
    DIV_NUM2  db ?

    ;--- RESULT VARIABLES ---
    SUM  db ? 
    DIFF db ? 
    PROD db ? 
    QUOT db ? 
    REM  db ?

    ;--- STRINGS ---
    msgNum1 db 'Enter NUM1: $'
    msgNum2 db 'Enter NUM2: $'
    NEWLINE db 0Ah, 0Dh, '$'
    
    msgSUM  db '--- For Addition ---$'
    msgDIFF db '--- For Subtraction ---$'
    msgPROD db '--- For Multiplication ---$'
    msgDIV  db '--- For Division ---$'

    msgResult    db 0Ah, 0Dh, 'Result: $'
    msgRemainder db '  Remainder: $'       

.code 
MAIN PROC FAR 
    MOV AX, @data 
    MOV DS, AX  
    
    ;================================================
    ; 1. ADDITION 
    ;================================================
    MOV DX, OFFSET msgSUM
    PUSH DX
    LEA AX, SUM_NUM1     
    PUSH AX
    LEA AX, SUM_NUM2     
    PUSH AX
    CALL INPUT_PROC
    
    XOR AX, AX 
    XOR DX, DX 
    MOV AL, SUM_NUM1     
    MOV DL, SUM_NUM2     
    PUSH AX 
    PUSH DX 
    CALL ADD_Proc 
    
    LEA DX, msgResult
    MOV AH, 09h
    INT 21h

    XOR AX, AX
    MOV AL, SUM
    PUSH AX
    CALL PRINT_PROC
                          
                          
                          
    ;================================================
    ; 2. SUBTRACTION 
    ;================================================
    MOV DX, OFFSET msgDIFF
    PUSH DX
    LEA AX, DIFF_NUM1    
    PUSH AX
    LEA AX, DIFF_NUM2    
    PUSH AX
    CALL INPUT_PROC
    
    XOR AX, AX 
    XOR DX, DX 
    MOV AL, DIFF_NUM1    
    MOV DL, DIFF_NUM2    
    PUSH AX 
    PUSH DX 
    CALL SUB_Proc 

    LEA DX, msgResult
    MOV AH, 09h
    INT 21h

    XOR AX, AX
    MOV AL, DIFF
    PUSH AX
    CALL PRINT_PROC
                        
                        
                        
    ;================================================
    ; 3. MULTIPLICATION 
    ;================================================
    MOV DX, OFFSET msgPROD
    PUSH DX
    LEA AX, PROD_NUM1    
    PUSH AX
    LEA AX, PROD_NUM2    
    PUSH AX
    CALL INPUT_PROC
    
    XOR AX, AX 
    XOR DX, DX 
    MOV AL, PROD_NUM1    
    MOV DL, PROD_NUM2    
    PUSH AX 
    PUSH DX 
    CALL MUL_Proc 

    LEA DX, msgResult
    MOV AH, 09h
    INT 21h

    XOR AX, AX
    MOV AL, PROD
    PUSH AX
    CALL PRINT_PROC
                    
                    
                    
    ;================================================
    ; 4. DIVISION 
    ;================================================
    MOV DX, OFFSET msgDIV
    PUSH DX
    LEA AX, DIV_NUM1     
    PUSH AX
    LEA AX, DIV_NUM2     
    PUSH AX
    CALL INPUT_PROC
    
    XOR AX, AX 
    XOR DX, DX 
    MOV AL, DIV_NUM1     
    MOV DL, DIV_NUM2     
    PUSH AX 
    PUSH DX 
    CALL DIV_Proc 
    
    LEA DX, msgResult   
    MOV AH, 09h
    INT 21h
    
    XOR AX, AX
    MOV AL, QUOT
    PUSH AX
    CALL PRINT_PROC     

    LEA DX, msgRemainder 
    MOV AH, 09h
    INT 21h

    XOR AX, AX
    MOV AL, REM
    PUSH AX
    CALL PRINT_PROC      
    
    LEA DX, NEWLINE
    MOV AH, 09h
    INT 21h

    JMP endCode
MAIN ENDP 

;====================================================
; INPUT PROCEDURE
;====================================================
INPUT_PROC PROC
    PUSH BP
    MOV BP, SP

    LEA DX, NEWLINE
    MOV AH, 09h
    INT 21h

    MOV DX, [BP+8]   
    MOV AH, 09h
    INT 21h
    
    LEA DX, NEWLINE
    MOV AH, 09h
    INT 21h

    ; --- INPUT 1 ---
    LEA DX, msgNum1          
    MOV AH, 09h 
    INT 21h 
    
    CALL SCAN_NUM        ; To take multiple digit Number as input
    
    MOV BX, [BP+6]       ; Load address of Var1
    MOV [BX], AL         ; Save result (AL) into Var1
    
    LEA DX, NEWLINE
    MOV AH, 09h
    INT 21h

    ; --- INPUT 2 ---
    LEA DX, msgNum2          
    MOV AH, 09h 
    INT 21h 
    
    CALL SCAN_NUM        ; To take multiple digit Number as input

    MOV BX, [BP+4]       ; Load address of Var2
    MOV [BX], AL         ; Save result (AL) into Var2

    LEA DX, NEWLINE
    MOV AH, 09h
    INT 21h

    POP BP
    RET 6
INPUT_PROC ENDP
                                                         
                                                         
;========================================================
; HELPER PROCEDURE TO TAKW MULTIPLE DIGIT NUMBER AS IMPUT
;========================================================
SCAN_NUM PROC
    PUSH BX
    PUSH CX
    PUSH DX

    XOR BX, BX           ; BX holds the running total (Initialize to 0)

NEXT_DIGIT:
    MOV AH, 01h          ; To take 1 digit in Input
    INT 21h
    
    CMP AL, 0Dh          ; Check if Enter key (Carriage Return) is pressed
    JE END_SCAN          ; If Enter, stop reading

    SUB AL, 30h          ; Convert ASCII to Integer
    MOV AH, 0            ; Clear AH, so AX is just the digit
    MOV CX, AX           ; Save the digit in CX temporarily

    MOV AX, 10           ; Prepare to multiply by 10
    MUL BX               ; AX = Total * 10
    ADD AX, CX           ; AX = (Total * 10) + New Digit
    MOV BX, AX           ; Update the Total in BX
    
    JMP NEXT_DIGIT       ; Go back for next char

END_SCAN:
    MOV AX, BX           ; Move final result to AX (Output is in AL)
    
    POP DX
    POP CX
    POP BX
    RET
SCAN_NUM ENDP
                  
                  
                  
;====================================================
; PRINT PROCEDURE 
;====================================================
PRINT_PROC PROC
    PUSH BP
    MOV BP, SP
    
    MOV AX, [BP+4]       
    MOV CX, 0            
    MOV BX, 10           

    CMP AX, 0
    JNE DIGIT_LOOP
    MOV DL, '0'
    MOV AH, 02h
    INT 21h
    JMP PRINT_EXIT

DIGIT_LOOP:
    XOR DX, DX           
    DIV BX               
    PUSH DX              
    INC CX               
    CMP AX, 0            
    JNE DIGIT_LOOP       

PRINT_LOOP:
    POP DX               
    ADD DL, 30h          
    MOV AH, 02h             
    INT 21h
    LOOP PRINT_LOOP         

PRINT_EXIT:
    POP BP
    RET 2                    
PRINT_PROC ENDP
                  
                  
                  
;====================================================
; MATH PROCEDURES
;====================================================
ADD_Proc PROC 
    PUSH BP 
    MOV BP, SP 
    MOV AX, [BP+6] 
    MOV DX, [BP+4] 
    XOR BX, BX 
    ADD BX, DX 
    ADD BX, AX 
    MOV SUM, BL
    POP BP 
    RET 4 
ADD_Proc ENDP 

SUB_Proc PROC 
    PUSH BP 
    MOV BP, SP 
    MOV AX, [BP+6] 
    MOV DX, [BP+4] 
    XOR BX, BX 
    MOV BX, AX 
    SUB BX, DX 
    MOV DIFF, BL
    POP BP 
    RET 4 
SUB_Proc ENDP 

MUL_Proc PROC 
    PUSH BP 
    MOV BP, SP 
    MOV AX, [BP+6] 
    MOV DX, [BP+4] 
    MOV CX, AX 
    MUL DX 
    MOV BX, AX 
    MOV AX, CX 
    MOV PROD, BL
    POP BP 
    RET 4 
MUL_Proc ENDP 

DIV_Proc PROC 
    PUSH BP 
    MOV BP, SP 
    MOV AX, [BP+6] 
    MOV DX, [BP+4] 
    XOR AH, AH 
    DIV DL 
    MOV QUOT, AL        
    MOV REM, AH    
    POP BP 
    RET 4 
DIV_Proc ENDP 

endCode:
    MOV AH, 4Ch 
    INT 21h
    END MAIN
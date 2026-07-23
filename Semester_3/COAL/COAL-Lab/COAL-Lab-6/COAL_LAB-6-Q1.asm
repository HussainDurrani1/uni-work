; Question 1:

;Write a program that declares and initializes an array of 20 elements 
;and then calculates the number of occurrences of a specific number in the array.

.model small
.stack 64 

.data
NUM dB 25  
COUNT dW ?
ARRAY dB 1, 25, 3, 4, 25, 25, 7, 8, 25, 25, 25, 12, 25, 14, 25, 16, 17, 18, 19, 25 

.code 
    MAIN PROC FAR 
        MOV AX, @DATA 
        MOV DS, AX
        
        MOV CX, 20
        
        MOV AL, NUM
        MOV SI, 0
        
        MOV DX, 0    ; For COUNTING the occurence of '25'
        
        MOV BX, offset ARRAY
        
        LOOP_START:
            MOV AH, [BX+SI]
            INC SI
            
            CMP AL, AH
            JE INCREMENT
            
            LOOP LOOP_START
            
            
        INCREMENT:
            INC DX
            DEC CX 
            JZ SAVE          
            JMP LOOP_START
            
        
        SAVE:
            MOV COUNT, DX
        
            
    MAIN ENDP 
.exit
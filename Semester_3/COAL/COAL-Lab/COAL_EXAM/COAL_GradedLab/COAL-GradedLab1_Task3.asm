 .model small
.stack 64
.data  

.code

    MAIN PROC FAR
        
        
        MOV AX, 0X1234
        MOV BX, 0X5678
        MOV CX, 0X9ABC
        MOV DX, 0XDEF0
        
        MOV CH, 0
        MOV DH, 0
        
        ADD CX, DX     ; CL + DL
                 
        ; FOR (AH + BH)                                                                        
        MOV DH, AH
        MOV AH, 0
        MOV DL, BH
        MOV BH, 0
        
        ADD DH, DL
        
        
        ADD CX, AX
        ADD CX, BX
        
        
        MOV DL, DH
        MOV DH, 0
        
        SUB CX, DX
              
        
        
        MOV AH, 4CH
        INT 21H
        
    MAIN ENDP

.exit
.model small
.stack 64
.data  

.code

    MAIN PROC FAR
              
        MOV AX, 0      
        MOV DS, AX
                
        MOV SI, 0X2000   ; Initial Address
                                           
        
        ;Initializing Values at the addresses                                   
        MOV BYTE PTR [SI], 0X45
        ADD SI, 2
        
        MOV BYTE PTR [SI], 0X67
        ADD SI, 2
        
        MOV BYTE PTR [SI], 0X89
        ADD SI, 2
        
        MOV BYTE PTR [SI], 0XAB
        ADD SI, 2
        
        MOV BYTE PTR [SI], 0XCD
        ADD SI, 2
        
        MOV BYTE PTR [SI], 0XEF
        ADD SI, 2
        
        
        ; Resetting  address
        MOV SI, 0X2000
                    
        ; Adding 1st THREE BYTES in AL            
        ADD AX, [SI]
        ADD SI, 2
        
        ADD AX, [SI]
        ADD SI, 2
        
        ADD AX, [SI]
        ADD SI, 2
        
        
        ; Adding LAST THREE BYTES in AL       
        ADD BX, [SI]
        ADD SI, 2
        
        ADD BX, [SI]
        ADD SI, 2
        
        ADD BX, [SI]
        ADD SI, 2
        
        
        ; ADDING AL & BL
        ADD AX, BX
        MOV CX, AX
                         
                     
        MOV AX, 0008H                 
        MOV DS, AX
        MOV BX, 0X3F5A
                         
        MOV [BX], CX
        
        
        
        MOV AH, 4CH
        INT 21H
        
    MAIN ENDP

.exit
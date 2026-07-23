.model small
.stack 100h
.data
    VAL1    dw 000Ah    ; 10
    VAL2    dw 0005h    ; 5 

    RES_ADD dw ?  
    RES_MUL dw ?   
    RES_DIV dw ? 

.code
MAIN PROC
    MOV AX, @data
    MOV DS, AX

    ; --- HOOK INTERRUPT 0x65 ---
    MOV AX, 0
    MOV ES, AX       

    MOV WORD PTR ES:[65h*4], OFFSET ISR_65
    MOV WORD PTR ES:[65h*4+2], CS

    ;SERVICE 0x1:
    LEA SI, VAL1      
    LEA DI, VAL2      
    LEA BX, RES_ADD   
    MOV AH, 01h       
    INT 65h

    ;SERVICE 0x2:
    LEA SI, VAL1
    LEA DI, VAL2
    LEA BX, RES_MUL   
    MOV AH, 02h       
    INT 65h

    ;SERVICE 0x3: 
    LEA SI, VAL1      
    LEA DI, VAL2      
    MOV AH, 03h       
    INT 65h
    
    MOV RES_DIV, AX 

    MOV AH, 4Ch
    INT 21h
MAIN ENDP

; --- INTERRUPT 0x65 HOOKING(ISR65) ---
ISR_65 PROC
    PUSH BX
    PUSH CX
    PUSH DX
    PUSH SI
    PUSH DI
    PUSH DS
    PUSH ES

    CMP AH, 01h
    JE DO_ADD
    
    CMP AH, 02h
    JE DO_MUL
    
    CMP AH, 03h
    JE DO_DIV
    
    JMP EXIT_ISR

DO_ADD:
    MOV AX, [SI]
    ADD AX, [DI]
    MOV [BX], AX
    JMP EXIT_ISR

DO_MUL:
    MOV AX, [SI]
    MOV CX, [DI]     
    MUL CX          
    MOV [BX], AX 
    JMP EXIT_ISR

DO_DIV:
    MOV AX, [SI] 
    MOV CL, [DI] 
    DIV CL   
    JMP EXIT_ISR

EXIT_ISR:
    POP ES
    POP DS
    POP DI
    POP SI
    POP DX
    POP CX
    POP BX
    
    IRET        
ISR_65 ENDP
END MAIN
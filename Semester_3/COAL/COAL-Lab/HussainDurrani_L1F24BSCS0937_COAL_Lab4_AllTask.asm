.model small
.data
.code
MAIN PROC FAR
    MOV AX, 1000h
    MOV DS, AX
    MOV SI, 0
    MOV BX, 1000h 
    mov word ptr [BX + SI], 0398h   ; low word
    ADD SI, 2
    mov word ptr [BX + SI], 1F54h   ; high word
    MOV BX, 1008h
    MOV SI, 0
    mov word ptr [BX + SI], 0F02Eh  ; low word
    ADD SI, 2
    mov word ptr [BX + SI], 0C0A1h  ; high word
    mov AX, word ptr [1000h]
    add AX, word ptr [1008h]
    mov word ptr [1010h], AX      ; result low
    mov AX, word ptr [1002h]
    adc AX, word ptr [100Ah]
    mov word ptr [1012h], AX      ; result high
    mov AH, 4Ch
    int 21h
MAIN ENDP
.exit



; ---------------------------------------------------------------------


; Task 2:
.model small
.data
RESULT dw 0
.code
MAIN PROC FAR
    MOV AX, 0FF12h
    NOT AX             
    MOV BX, AX         
    MOV AX, 02113h
    OR AX, 02340h      ; AX = 0x2113 | 0x2340
    AND AX, 0ABFFh     ; AX = 0xABFF & AX
    XOR AX, BX         ; X = (~0xFF12) ^ (0xABFF & (0x2113|0x2340))
    MOV RESULT, AX
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN	



; ---------------------------------------------------------------------


; Task 3:
.model small
.data
.code
MAIN PROC FAR
    
    MOV AX, 8000h
    ADD AX, 8000h    ; CF and OF both will be set

    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
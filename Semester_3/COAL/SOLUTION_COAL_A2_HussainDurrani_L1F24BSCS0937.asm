; Question 1:
.model small
.stack 64

.data
N dB 1
M dB 9
SUM dW ?

.code
MAIN PROC FAR
    MOV AX, @DATA
    MOV DS, AX
    
    MOV BL, N       ; BL = 1
    MOV BH, M       ; BH = 9
    MOV CX, 0       ; To clear CX
    ADD CL, BL      ; CL += 1
    
    MOV DX, 0       ; DX = 0
    
    KEEP_ADDING:
        ADD DX, CX      ;(DX += 1) -> (DX += 2) -> ... -> (DX += 9)
        INC CX          ; CX++  ->  1 -> 2 -> ... -> 9
        
        CMP CL, BH      ; CL - BH(9) -> 1 < 9 (below) -> ... -> 9 <= 9 (Below Equal)
        JBE KEEP_ADDING ; If CL <= 9  [Jump till CL is below or equal to BH (9)]
        
        
    MOV SUM, DX         ; Storing result (DX) in the SUM variable
    
    
MAIN ENDP
.exit


; Comment one code to run the other...

; --------------------------------------------   

; Question 2:
.model small
.stack 0x100

.data
array db 33 dup(?)   ; A1B1Fh - A1AFFh = 20h -> +1 = 21h = 33d -> 33 bytes total to store

.code
MAIN PROC FAR
    mov AX, @data
    mov DS, AX

    mov AX, 0A1AFh   ; To store segment address
    mov ES, AX
    mov SI, 000Fh    ; Storing offset for the 'ES' segment address
    mov DI, SI
    mov CX, 33     ; Counter for Filling Memory     

FillMemory:                    ; To put 3h at the memory (A1AFFh TO A1B1Fh)
    mov byte ptr ES:[SI], 3h
    inc SI
    loop FillMemory

    mov SI, 000Fh
    mov DI, offset array       ; Storing address of array
    mov CX, 33     ; Counter for reading from memory & storing in array loop
                               
ReadMemory:                    ; To read from memory to the Array
    mov AL, ES:[SI]
    mov [DI], AL
    inc SI
    inc DI
    loop ReadMemory

    mov AH, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit
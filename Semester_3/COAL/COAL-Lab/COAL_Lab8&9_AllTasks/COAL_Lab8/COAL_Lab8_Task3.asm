; Task 3:
.model small
.stack 100h
.data
    ROW db 0
    COL db 0
    
    msg db "L1", 13, 10, "L2", 13, 10, "L3", 13, 10, "L4", 13, 10
        db "L5", 13, 10, "L6", 13, 10, "L7", 13, 10, "L8", 13, 10
        db "L9", 13, 10, "L10", 13, 10, "L11", 13, 10, "L12", 13, 10
        db "L13", 13, 10, "L14", 13, 10, "L15", 13, 10, "L16", 13, 10
        db "L17", 13, 10, "L18", 13, 10, "L19", 13, 10, "L20", 13, 10
        db "L21", 13, 10, "L22", 13, 10, "L23", 13, 10, "L24", 13, 10
        db "L25", 13, 10, "L26 (Triggers Scroll)", 0

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
    PUSH SI

LOOP_STR:
    LODSB               ; Load next character from string
    CMP AL, 0           ; Check for null terminator
    JE END_STR
    
    CMP AL, 0Dh         ; Carriage Return
    JE DO_CR
    CMP AL, 0Ah         ; Newline
    JE DO_NL
    
    ; Memory Address = 2 * (Row * 80 + Col)
    PUSH AX             ; Save Char
    MOV AL, ROW
    MOV BL, 80
    MUL BL              ; AX = Row * 80
    MOV BL, COL
    MOV BH, 0
    ADD AX, BX          ; AX = (Row * 80) + Col
    SHL AX, 1           ; AX = Address * 2
    MOV DI, AX
    POP AX              ; Restore Char
    
    ; Write to Video Memory
    MOV ES:[DI], AL     ; ASCII
    MOV ES:[DI+1], 07h 
    
    INC COL
    CMP COL, 80
    JL LOOP_STR
    
    MOV COL, 0
    INC ROW
    CALL CHECK_SCROLL   ; Check if we need to scroll
    JMP LOOP_STR

DO_CR:
    MOV COL, 0          
    JMP LOOP_STR

DO_NL:
    INC ROW            
    CALL CHECK_SCROLL  
    JMP LOOP_STR

END_STR:
    POP SI
    POP DI
    POP DX
    POP BX
    POP AX
    RET
PRINT_STR ENDP

;---------------------------------------------------------
; Procedure: CHECK_SCROLL
;---------------------------------------------------------
CHECK_SCROLL PROC
    CMP ROW, 25    
    JNE NO_SCROLL
    
    CALL SCROLL_UP
    MOV ROW, 24     
    
NO_SCROLL:
    RET
CHECK_SCROLL ENDP

;---------------------------------------------------------
; Procedure: SCROLL_UP
;---------------------------------------------------------
SCROLL_UP PROC
    PUSH AX
    PUSH CX
    PUSH SI
    PUSH DI
    PUSH DS            ; Save Data Segment
    
    MOV AX, ES
    MOV DS, AX        
    
    MOV DI, 0         
    MOV SI, 160   
    
    ; We move 24 rows * 80 chars/row = 1920 words
    MOV CX, 1920       
    
    CLD                ; Clear Direction Flag
    REP MOVSW 

    
    MOV DI, 3840       ; Start of Row 24 (24 * 160 = 3840)
    MOV CX, 80   
    MOV AX, 0720h      ; AH=07 (Attr), AL=20h (Space)
    
CLEAR_LAST_ROW:
    MOV ES:[DI], AX 
    ADD DI, 2         
    LOOP CLEAR_LAST_ROW

    POP DS             ; Restore Data Segment
    POP DI
    POP SI
    POP CX
    POP AX
    RET
SCROLL_UP ENDP

END MAIN
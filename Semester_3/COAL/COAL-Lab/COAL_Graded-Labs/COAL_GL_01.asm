.model small
.stack 100h
.data
    strVowel db "HELLO WORLD$"
    msgVowels db 0Dh, 0Ah, "Vowels count: $"
    msgSum    db 0Dh, 0Ah, "Sum result: $"
    vowelCnt  db ?
    
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX

    ; --- PART B: HOOKING INTERRUPT 0x60 ---
    MOV AX, 0
    MOV ES, AX                      ; Point ES to IVT (Segment 0)
    
    CLI                             ; Disable interrupts for safety
    MOV WORD PTR ES:[60h*4], OFFSET ISR60   ; Store Offset
    MOV WORD PTR ES:[60h*4+2], CS           ; Store Segment
    STI                             ; Enable interrupts

    ; --- PART C: TESTING SERVICE 1 (Vowels) ---
    LEA SI, strVowel                ; DS:SI points to string
    MOV AH, 01h                     ; Service 1
    INT 60h                         ; Call ISR
    MOV vowelCnt, AL                ; Save result
    
    ; Display Result for Service 1
    MOV AH, 09h
    LEA DX, msgVowels
    INT 21h
    
    MOV AL, vowelCnt
    MOV AH, 0                       ; Clear AH for printing
    CALL PRINT_NUM_AX               ; Use our generic print function

    ; --- PART C: TESTING SERVICE 2 (Sum) ---
    MOV BL, 3
    MOV CL, 5
    MOV DL, 7
    MOV AH, 02h                     ; Service 2
    INT 60h                         ; Call ISR
    
    ; Display Result for Service 2
    PUSH AX                         ; Save sum
    MOV AH, 09h
    LEA DX, msgSum
    INT 21h
    POP AX                          ; Restore sum
    CALL PRINT_NUM_AX               ; Print sum

    MOV AH, 4Ch
    INT 21h
MAIN ENDP

; --- PART A: ISR IMPLEMENTATION ---
ISR60 PROC FAR
    CMP AH, 01h
    JE SERVICE_VOWEL
    CMP AH, 02h
    JE SERVICE_SUM
    IRET

    SERVICE_VOWEL:
        ; Input: DS:SI = String
        ; Output: AL = Count
        PUSH SI             ; Preserve registers [cite: 686]
        PUSH CX
        PUSH BX
        
        MOV CL, 0           ; Counter for vowels
    NEXT_CHAR:
        MOV BL, [SI]        ; Read char
        CMP BL, '$'         ; End of string?
        JE DONE_VOWEL
        
        ; Check Vowels (A,E,I,O,U)
        ; Simple way: Compare with each. 
        ; Note: To be case insensitive, we would handle 'a' and 'A', etc.
        CMP BL, 'A'
        JE IS_VOWEL
        CMP BL, 'E'
        JE IS_VOWEL
        CMP BL, 'I'
        JE IS_VOWEL
        CMP BL, 'O'
        JE IS_VOWEL
        CMP BL, 'U'
        JE IS_VOWEL
        JMP NOT_VOWEL
        
    IS_VOWEL:
        INC CL
    NOT_VOWEL:
        INC SI
        JMP NEXT_CHAR
        
    DONE_VOWEL:
        MOV AL, CL          ; Return count in AL
        POP BX
        POP CX
        POP SI
        IRET

    SERVICE_SUM:
        ; Input: BL, CL, DL
        ; Output: AX = Sum
        XOR AX, AX          ; Clear AX
        ADD AL, BL
        ADD AL, CL
        ADD AL, DL
        ; No registers to preserve per logic, output is in AX
        IRET

ISR60 ENDP

; Include the PRINT_NUM_AX proc from previous answer here...
PRINT_NUM_AX PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    CMP AX, 0
    JNE START_P
    MOV DL, '0'
    MOV AH, 02h
    INT 21h
    JMP END_P
START_P:
    MOV BX, 10
    MOV CX, 0
PUSH_D:
    MOV DX, 0
    DIV BX
    PUSH DX
    INC CX
    CMP AX, 0
    JNE PUSH_D
PRINT_L:
    POP DX
    ADD DL, 30h
    MOV AH, 02h
    INT 21h
    LOOP PRINT_L
END_P:
    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUM_AX ENDP

END MAIN
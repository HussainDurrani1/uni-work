.model small
.stack 100h

.data
    ; Defined as per your logic (using $ terminator)
    ; But using the strings required by the exam question
    word1 dB 'BOOK$'
    word2 dB 'BOOKs$'
    
    ; The specific output messages requested
    msgSame dB 'SAME$'
    msgNotSame dB 'NOT SAME$'

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    ; --- SETUP VIDEO MEMORY ---
    MOV AX, 0B800h
    MOV ES, AX          ; ES now points to Video Memory
    
    ; --- STRING COMPARISON LOGIC ---
    LEA SI, word1
    LEA DI, word2
    
    NEXT_CHAR:
        CMP byte ptr [SI], '$' ; Check end of Word 1
        JNE CHECK_CHARS
        
        CMP byte ptr [DI], '$' ; If Word 1 ended, check Word 2
        JE WORDS_ARE_EQUAL     ; Both ended at same time -> EQUAL
        JMP WORDS_NOT_EQUAL    ; Word 1 ended but Word 2 didn't -> NOT EQUAL
        
        CHECK_CHARS:
        MOV AL, [DI]
        MOV AH, [SI]
        CMP AH, AL
        JNE WORDS_NOT_EQUAL    ; Char mismatch -> NOT EQUAL
        
        INC SI
        INC DI
        JMP NEXT_CHAR
        
    ; --- CASE: EQUAL ---
    WORDS_ARE_EQUAL:
        LEA SI, msgSame     ; Point SI to "SAME" message
        MOV AH, 02h         ; Attribute: GREEN (02h)
        JMP PRINT_TO_SCREEN
        
    ; --- CASE: NOT EQUAL ---
    WORDS_NOT_EQUAL:
        LEA SI, msgNotSame  ; Point SI to "NOT SAME" message
        MOV AH, 04h         ; Attribute: RED (04h)
        JMP PRINT_TO_SCREEN
        
    ; --- VIDEO MEMORY PRINTING ROUTINE ---
    PRINT_TO_SCREEN:
        ; Calculate Offset for Row 12, Col 35
        ; (12 * 80 + 35) * 2 = 1990
        MOV DI, 1990        
        
    DISPLAY_LOOP:
        MOV AL, [SI]        ; Get char from message
        CMP AL, '$'         ; Check for end of message
        JE END_CODE
        
        MOV ES:[DI], AX     ; Move Char (AL) and Color (AH) to Screen
        ADD DI, 2           ; Move to next screen cell (2 bytes)
        INC SI              ; Move to next char in string
        JMP DISPLAY_LOOP

    END_CODE:
        MOV AH, 4ch
        INT 21h
        
MAIN ENDP
END MAIN
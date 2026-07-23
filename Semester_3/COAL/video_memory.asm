.model small
.stack 100h

.data
msg1 db "Helloo", '$'
len equ $-msg1-1
.code
MAIN PROC FAR

    ; 1. Point ES to Video Memory [cite: 222-223]
    MOV AX, 0B800h
    MOV ES, AX
    MOV AX, @DATA
    MOV DS, AX          
    
    ; 2. Start at the beginning (Top-Left) [cite: 224]
    MOV DI, 0           
    
    ; 3. Total "words" on screen (80 columns * 25 rows = 2000 words) [cite: 215]
    MOV CX, 2000        
    
    ; 4. Prepare the "Character + Color" word [cite: 217, 218]
    ; AH = Attribute (4Fh = Red background, White text)
    ; AL = ASCII (20h = Space character to clear text)
    MOV AX, 5F20h       
    
    ; 5. Set Direction Flag to Forward [cite: 444]
    CLD                 
    
    ; 6. BLAST the screen with Red spaces
    REP STOSW           ; Fast clear
    
    CLD                 
        MOV CX, len     
        MOV AH, 1Fh     
        MOV DI, 1990    
        LEA SI, msg1    
    
        write:
            LODSB        
            STOSW        
            LOOP write
       
    END:      
        MOV AH, 4Ch
        INT 21H
    
MAIN ENDP
.exit



;.model small
;.stack 100h

;.data
string dB "Hello, World!", 0

;.code
;MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0XB800
    MOV ES, AX
    MOV SI, 1990    ; 2000d for the centre of screen
    MOV AX, 0
    
    MOV BX, offset string
    MOV CX, 13
    mov DI, 0
    
    DISPLAY:
        MOV AL, [BX+DI]
        INC DI
        MOV ES:[SI], AL
        INC SI
        MOV ES: [SI], 70h    ; for White (7 -> Background) text on Black (0 -> Foreground[text]) screen
        INC SI
        LOOP DISPLAY
        
;    END:      
        MOV AH, 4Ch
        INT 21H
    
;MAIN ENDP
;.exit
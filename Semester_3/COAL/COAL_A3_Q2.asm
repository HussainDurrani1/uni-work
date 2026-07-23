;================= PROBLEM STATEMENT #2 ================= 
; Hook INT 55h with services: 
; 01h -> Take (x,y) from user, set cursor, print '*' 
; 02h -> Beep until 'S' is pressed 
; 06h -> Display Hello, scroll, display message 
;=======================================================
.model small
.stack 100h

.data
    msgX    db 'Enter X-Coordinate (0-79): $'
    msgY    db 0Dh,0Ah,'Enter Y-Coordinate (0-24): $'
    msgStop db "Press 'S' to stop beep: $"
    msg1    db 'Hello$'
    msg2    db 'Have a good day!$'

    StarStr db '*', '$'

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    ;---------- Hook INT 55h ---------------
    MOV AX, 0
    MOV ES, AX

    MOV WORD PTR ES:[55h*4], OFFSET ISR55
    MOV WORD PTR ES:[55h*4+2], CS
    ;---------------------------------------

    ; Service 01h: Set cursor and display '*'
    MOV AH,01h
    INT 55h
    
    ; Service 02h: Beep until 'S' is pressed
    MOV AH,02h
    INT 55h
    
    ; Service 06h: Display msg1, move cursor 2 lines, display msg2
    MOV AH,06h
    INT 55h
    
    JMP EXIT
MAIN ENDP

;=======================================================
; INTERRUPT SERVICE ROUTINE FOR INT 55h
;=======================================================
ISR55 PROC FAR

    CMP AH,01h
    JE SERVICE_SetCursor

    CMP AH,02h
    JE SERVICE_BEEP

    CMP AH,06h
    JE SERVICE_DISPLAY

    IRET

;---------------- SERVICE 01h ----------------
SERVICE_SetCursor: 
    ; Print msgX (ask for X-coordinate): 
    MOV AH,09h 
    MOV DX,OFFSET msgX 
    INT 21h 
    
    ; Take X-Coordinate in Input (more than 1 digit)
    CALL SCAN_NUM       
    MOV SI, AX          ; SI = X 
    
    ; Print msgY (ask for Y-coordinate): 
    MOV AH,09h 
    LEA DX, msgY 
    INT 21h 
    
    ; Take Y-Coordinate in Input (more than 1 digit)
    CALL SCAN_NUM       
    MOV DI, AX          ; DI = Y 
    
    ; Clear Screen 
    MOV AX,0600h 
    MOV BH,07 
    MOV CX,0000 
    MOV DX,184Fh 
    INT 10h 
    
    ; 4. Set Cursor Position (X,Y)
    MOV AH,02h 
    MOV BH,00           
    MOV CX, SI          
    MOV DL, CL           
    MOV CX, DI          
    MOV DH, CL           
    INT 10h 
    
    ; Print Star
    MOV AH, 09h         
    LEA DX, StarStr     
    INT 21h             
    
    ; DELAY LOOP
    MOV CX, 01FFh
    DELAY:
        LOOP DELAY

    ; Clear screen again 
    MOV AX,0600h 
    MOV BH,07 
    MOV CX,0000 
    MOV DX,184Fh 
    INT 10h 
    
    ; Reset Cursor to (0,0)
    MOV AH,02h 
    MOV BH,00 
    MOV DH,0 
    MOV DL,0 
    INT 10h 
    
    IRET

;---------------- SERVICE 02h ----------------
SERVICE_BEEP:
    ; Display message to tell user to press 'S' to stop beep
    MOV AH,09h
    LEA DX, msgStop
    INT 21h

BEEP_LOOP:
    ; Generate beep sound    
    MOV AH,02h
    MOV DL,07
    INT 21h
    
    ; Check if a key has been pressed
    MOV AH,01h
    INT 16h
    JZ BEEP_LOOP    ; repeat beep if no key
    
    ; Read pressed key
    MOV AH,00h
    INT 16h
    CMP AL,'S'        ; compare with 'S' 
    JE STOP_BEEP
    JMP BEEP_LOOP     ; continue beep until 'S' pressed

STOP_BEEP:
    IRET

;---------------- SERVICE 06h ----------------
SERVICE_DISPLAY: 
    ; Clear the screen
    MOV AX,0600h 
    MOV BH,07 
    MOV CX,0000 
    MOV DX,184Fh 
    INT 10h
    
    ; Set cursor at start (0,0)
    MOV AH,02h
    MOV BH,00
    MOV DH,0
    MOV DL,0
    INT 10h
    
    ; Display first message ("Hello")
    MOV AH,09h
    MOV DX,OFFSET msg1
    INT 21h
    
    ; Move cursor two lines below (row 2, column 0)
    MOV AH,02h
    MOV BH,00
    MOV DH,2
    MOV DL,0
    INT 10h
    
    ; Display second message ("Have a good day!")
    MOV AH,09h
    MOV DX,OFFSET msg2
    INT 21h

    IRET

ISR55 ENDP

;=======================================================
; HELPER PROCEDURE: SCAN_NUM
;=======================================================
SCAN_NUM PROC
    PUSH BX
    PUSH CX
    PUSH DX

    XOR BX, BX          

NEXT_KEY:
    MOV AH, 01h         
    INT 21h

    CMP AL, 0Dh         ; Check for Enter
    JE FINISH_INPUT     

    SUB AL, 30h         
    MOV AH, 0           
    MOV CX, AX          

    MOV AX, 10
    MUL BX              
    ADD AX, CX          
    MOV BX, AX          

    JMP NEXT_KEY        

FINISH_INPUT:
    MOV AX, BX          
    POP DX
    POP CX
    POP BX
    RET
SCAN_NUM ENDP

EXIT:
    MOV AH,4Ch
    INT 21h
    END MAIN
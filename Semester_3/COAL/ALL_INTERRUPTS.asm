; INTERRUPTS:
.model small
.stack 100h

.data
    prompt  db 'Enter a char (Echo): $'
    msg1    db 0Dh, 0Ah, 'You typed: $'
    msg2    db 0Dh, 0Ah, 'Press any key (No Echo) to clear screen...$'
    bell    equ 07h

.code
MAIN PROC FAR
    MOV AX, @DATA
    MOV DS, AX

    ; 1. [INT 21h / AH=09h] - Display String
    MOV AH, 09h
    mov dx, offset prompt
    int 21h

    ; 2. [INT 21h / AH=01h] - Read Character with Echo
    mov ah, 01h
    int 21h         ; Input stored in AL
    mov bl, al      ; Save it in BL

    ; 3. [INT 21h / AH=09h] - Display Message 1
    mov ah, 09h
    mov dx, offset msg1
    int 21h

    ; 4. [INT 21h / AH=02h] - Display Character (The one we saved)
    mov ah, 02h
    mov dl, bl
    int 21h

    ; 5. [INT 21h / AH=09h] - Display Message 2
    mov ah, 09h
    mov dx, offset msg2
    int 21h

    ; 6. [INT 21h / AH=07h] - Character Input (No Echo)
    mov ah, 07h
    int 21h         ; Program pauses until key press

    ; 7. [INT 10h / AH=06h] - Clear Screen (Green BG, White Text)
    mov ax, 0600h   ; AH=06, AL=00
    mov bh, 27h     ; Green (2), White (7)
    mov cx, 0000h   ; Top-left
    mov dx, 184Fh   ; Bottom-right
    int 10h

    ; 8. [INT 10h / AH=02h] - Set Cursor (Row 10, Col 10)
    mov ah, 02h
    mov bh, 00h
    mov dx, 0A0Ah   ; DH=10, DL=10
    int 10h

    ; 9. [INT 10h / AH=09h] - Write Char & Attribute (Blinking Red)
    mov ah, 09h
    mov al, '!'
    mov bl, 84h     ; 8 (Blink), 4 (Red)
    mov cx, 10      ; 10 times
    int 10h

    ; 10. [INT 21h / AH=02h] - The Bell Sound
    mov ah, 02h
    mov dl, bell
    int 21h

    ; 11. [INT 16h / AH=01h] - Check Keyboard Buffer (Non-blocking)
WAIT_KEY:
    mov ah, 01h
    int 16h
    jz WAIT_KEY     ; Jump if no key is pressed

    ; 12. [INT 16h / AH=00h] - Read Keyboard Buffer (Clears it)
    mov ah, 00h
    int 16h

    ; 13. [INT 21h / AH=4Ch] - Exit
    MOV AH, 4Ch
    INT 21H
MAIN ENDP
END MAIN





;=====================================================



; INT 10h -> SERVICE "06h" FOR CLEARING THE SCREEN
.model small
.stack 100h

.data
msg dB "Hello there! Durrani...$"
msg1 dB "ISN'T IT COOL...$"

.code
MAIN PROC FAR
    MOV AX, @DATA
    MOV DS, AX
    mov dx, offset msg
    mov ah, 09h
    int 21h
    
    
    MOV AH, 06h
    MOV AL, 00h     ; Clear the specified area
    MOV BH, 47h     ; 4 = Red background, 7 = White text
    MOV CH, 10      ; Start Row
    MOV CL, 20      ; Start Column
    MOV DH, 15      ; End Row
    MOV DL, 60      ; End Column
    INT 10h
    
    mov dx, offset msg1
    mov ah, 09h
    int 21h
    
    MOV AH, 4Ch
    INT 21H
MAIN ENDP





;=====================================================



; INT 10h -> SERVICE "06h" FOR CLEARING THE SCREEN
.model small
;.stack 100h

;.data
;msg dB "Hello there! Durrani...$"
;msg1 dB "ISN'T IT COOL...$"

;.code
;MAIN PROC FAR
    MOV AX, @DATA
    MOV DS, AX
    mov dx, offset msg
    mov ah, 09h
    int 21h
    
    
    MOV AH, 06h     ; Service 06h
    MOV AL, 00h     ; Special flag: Clear entire window
    MOV BH, 30h     ; 2 = Green background, 0 = Black text
    MOV CX, 0000h   ; Top-left corner (0,0)
    MOV DX, 184Fh   ; Bottom-right corner (Row 24, Col 79)
    INT 10h 
    
    mov dx, offset msg1
    mov ah, 09h
    int 21h
    
    MOV AH, 4Ch
    INT 21H
;MAIN ENDP
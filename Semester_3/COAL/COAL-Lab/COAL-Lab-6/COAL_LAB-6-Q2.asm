; Question 2:

;Write a program to do the following comparisons between two single digit signed numbers
; - Perform Less Than
; - Perform Greater Than
; - Perform Equal To

;You should also print the message after performing operation


.model small
.stack 100h

.data
num1 db 79h
num2 db 69h
MIN dB 0
MAX dB 0

; Messages to be printed:
msg_less db "Number1 is less than Number2$"
msg_greater db "Number1 is greater than Number2$"
msg_equal db "Both numbers are equal$"

.code
MAIN PROC FAR
    mov ax, @data
    mov ds, ax

    mov bl, num1
    mov cl, num2

    cmp bl, cl
    ; Jumping for Signed values -> JL, JG, JE
    JL LESS
    JG GREATER
    JE EQUAL

LESS:
    MOV dx, offset msg_less    ; To print the message.
    mov ah, 09h
    int 21h
    MOV MIN, BL     ; Storing the Smaller value in a Variable
    jmp EXIT

GREATER:
    lea dx, msg_greater     ; To print the message.
    mov ah, 09h
    int 21h
    MOV MAX, BL     ; Storing the Greater value in a Variable
    jmp EXIT

EQUAL:
    lea dx, msg_equal   ; To print the message.
    mov ah, 09h
    int 21h
    MOV MIN, CL     ; When both are equal
    MOV MAX, CL     ; Storing the same value at both variables
    
EXIT:
    mov ah, 4Ch
    int 21h

MAIN ENDP
end main
.exit
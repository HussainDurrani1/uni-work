; ----------------------------------------------------------------------------------------------------------

; SORTING IN ASCENDING ORDER
.model small
.stack 100h

.data
ARR dW 4, 7, 5, 2, 3, 10, 8, 9, 6, 1

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV DX, 9
    
    OUTERLOOP:
        MOV CX, DX
        MOV BX, offset ARR
        
        INNERLOOP:
            MOV AX, [BX]
            CMP AX, [BX+2]
            
            JA SWAP
            JMP NOTSWAP
            
        SWAP:
            MOV DI, [BX+2]
            MOV [BX+2], AX
            MOV [BX], DI
            
        NOTSWAP:
            ADD BX, 2
            
        LOOP INNERLOOP
        
        DEC DX
        CMP DX, 0
        JNE OUTERLOOP
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit    


; ----------------------------------------------------------------------------------------------------------


;SORTING IN DESCENDING ORDER
.model small
.stack 100h
.data
ARR dW 4, 7, 5, 2, 3, 10, 8, 9, 6, 1 
TEMP dW 0
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX

    MOV DX, 9
    PUSH DX
    MOV BX, offset ARR
    PUSH BX
    
    CALL SORT
    jmp endcode

MAIN ENDP

SORT PROC
    PUSH BP
    MOV BP, SP
    OUTERLOOP:
        MOV BX, [BP+4]
        MOV CX, [BP+6]
    INNERLOOP:
        MOV AX, [BX]
        CMP AX, [BX+2]
        JB SWAP
        JMP NOTSWAP
    SWAP:
        MOV DI, [BX+2]
        MOV [BX+2], AX
        MOV [BX], DI
    NOTSWAP:
        ADD BX, 2
                  
                  
    LOOP INNERLOOP
    DEC DX
    CMP DX, 0
    MOV [BP+6], DX
    JNE OUTERLOOP
    
    POP BP
    RET  6 
SORT ENDP
      
endcode:     
    END MAIN
    mov ah, 4Ch
    int 21h
    .exit

; -----------------------------------------------------------------------


; Q Add two 64-bit numbers using byte arrays

.model small
.stack 100h

.data
Num1 db 77h,00h,ABh,67h,EFh,45h,CDh,54h
Num2 db 45h,EFh,87h,B9h,6Bh,45h,FFh,23h
Sum  db 8 dup(0)

.code
MAIN PROC FAR
    mov ax, @data
    mov ds, ax

    mov si, 0
    mov cl, 8            ; 8 bytes total
    mov bl, 0            ; BL = carry

ADD_LOOP:
    mov al, BYTE PTR Num1+si
    mov dl, BYTE PTR Num2+si

    add al, dl           ; AL = Num1 + Num2
    add al, bl           ; add previous carry

    jc SET_CARRY
    mov bl, 0
    jmp STORE

SET_CARRY:
    mov bl, 1

STORE:
    mov BYTE PTR Sum+si, al

    inc si
    dec cl
    jnz ADD_LOOP

    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN

; -------------------------------------------------------------------------------------------------
; Q Search for a number in a word array

.model small
.stack 100h

.data
ARRAY dw 9,4,2,1,5,7,3,9,8,6
num   dw 7

.code
MAIN PROC FAR
    mov ax, @data
    mov ds, ax

    mov si, 0
    mov cx, 10        ; array size
    mov dx, 0         ; default = not found

SEARCH_LOOP:
    mov ax, WORD PTR ARRAY+si
    cmp ax, num
    je FOUND

    add si, 2
    loop SEARCH_LOOP
    jmp EXIT

FOUND:
    mov dx, 1

EXIT:
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN


; ----------------------------------------------------------------------------------


; Q Count the number of 1 bits in each byte

.model small
.stack 100h

.data
Num1 db 77h,00h,ABh,67h,EFh,45h,CDh,54h
Ones db 8 dup(0)

.code
MAIN PROC FAR
    mov ax, @data
    mov ds, ax

    mov si, 0                ; index = 0

NEXT_BYTE:
    mov al, BYTE PTR Num1+si ; load byte
    mov bl, 0                ; count = 0
    mov cl, 8                ; check all 8 bits

COUNT_LOOP:
    shr al, 1                ; lowest bit ? CF
    jc BIT_ONE               ; if CF=1, bit was 1

    jmp SKIP

BIT_ONE:
    inc bl                   ; count++

SKIP:
    dec cl
    jnz COUNT_LOOP           ; repeat for 8 bits

    mov BYTE PTR Ones+si, bl ; save count in array

    inc si                   ; go to next byte
    cmp si, 8
    jne NEXT_BYTE

    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN


; -------------------------------------------------------------------   


; FIND FREQUENCY OF A NUMBER
.model small
.stack 100h

.data
ARR dW 1, 3, 1, 2, 1, 4, 1, 5, 1, 6, 7, 1, 8, 1, 9, 10
SIZE dW 16
FREQ dW 0
NUM dW 1

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV SI, offset ARR
    MOV CX, SIZE
    MOV AX, NUM
    MOV DX, 0
    
    LOOPING:
        MOV BX, [SI]
        CMP BX, AX
        JE FOUND
        JMP NEXT
        
        FOUND:
            INC DX
        
        NEXT:
            ADD SI, 2
            LOOP LOOPING         
    
    
    MOV FREQ, DX
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit

; -------------------------------------------------------------------

;  CHARACTER ARRAY PRINTING
.model small
.stack 100h

.data
MSG dB 'HELLO, HUSSAIN DURRANI!$'
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV BX, offset MSG
    MOV AH, 09h
    INT 21h
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit

; -------------------------------------------------------------------

; FIND AVERAGE
.model small
.stack 100h

.data
ARR dW 4, 7, 5, 10, 3, 2, 8, 1, 6, 9
COUNT dW 10
AVG dW 0
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV BX, offset ARR
    MOV CX, COUNT
    
    MOV DX, 0
    
    LOOP_START:
        MOV AX, [BX]
        ADD DX, AX
        ADD BX, 2
        LOOP LOOP_START
    
    MOV AX, DX
    MOV DX, 0
    MOV CX, COUNT    
    DIV CX        
    
    MOV AVG, AX
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit
                                                                     

; -------------------------------------------------------------------


; FIND MAXIMUM
.model small
.stack 100h

.data
ARR dW 4, 7, 5, 11, 3, 10, 8, 1, 16, 9
MAX dW 0
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV BX, offset ARR
    MOV CX, 9
    
    MOV AX, [BX]
    MOV DX, AX
    
    LOOP_START:
        MOV AX, [BX]
        CMP AX, DX
        JA MAX_FOUND
        JMP NOT_MAX
        
        MAX_FOUND:
            MOV DX, AX
            
        NOT_MAX:
            ADD BX, 2
            LOOP LOOP_START
    
    MOV MAX, DX
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit
     

; ----------------------------------------------------------------------------------------------------------



; FIND MINIMUM
.model small
.stack 100h

.data
ARR dW 4, 7, 5, 11, 3, 10, 8, 1, 6, 9
MIN dW 0
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV BX, offset ARR
    MOV CX, 9
    
    MOV AX, [BX]
    MOV DX, AX
    
    LOOP_START:
        MOV AX, [BX]
        CMP AX, DX
        JB MIN_FOUND
        JMP NOT_MIN
        
        MIN_FOUND:
            MOV DX, AX
            
        NOT_MIN:
            ADD BX, 2
            LOOP LOOP_START
    
    MOV MIN, DX
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit
     

; ----------------------------------------------------------------------------------------------------------


; COUNT NO. OF ODDS
.model small
.stack 100h

.data
ARR dW 4, 7, 5, 11, 3, 13, 8, 9, 6, 1
COUNT dW 0
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV CX, 10
    MOV BX, offset ARR
    MOV SI, 0
    
    LOOP_START:
    
        MOV AX, [BX+SI]
        AND AX, 1
        
        JP NOT_ODD
        JNP ODD
        
        ODD:
            INC COUNT            
        
        NOT_ODD:
            ADD SI, 2
            LOOP LOOP_START
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit
     

; ----------------------------------------------------------------------------------------------------------



; COUNT NO. OF EVENS
.model small
.stack 100h

.data
ARR dW 4, 7, 5, 2, 3, 10, 8, 9, 6, 1
COUNT dW 0
.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV CX, 10
    MOV BX, offset ARR
    MOV SI, 0
    
    LOOP_START:
    
        MOV AX, [BX+SI]
        AND AX, 1
        
        JP EVEN
        JNP NOT_EVEN
        
        EVEN:
            INC COUNT            
        
        NOT_EVEN:
            ADD SI, 2
            LOOP LOOP_START
        
    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
.exit

  

; ----------------------------------------------------------------------------------------------------------

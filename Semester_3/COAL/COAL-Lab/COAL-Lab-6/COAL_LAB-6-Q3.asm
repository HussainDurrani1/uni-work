.model small
.stack 100h

.data
NUM dB 22

msg_Even dB "The Number is EVEN.$"
msg_Odd dB "The Number is ODD.$"

.code

    MAIN PROC FAR
        MOV AX, @data
        MOV DS, AX
        
        MOV BL, NUM
        
        AND BL, 1    ; AND BL with 0001 -> So it check if the LSB is 1 or 0
                              ;8421
        JP EVEN     ; If BL is 0110 (EVEN as LSB is 0)-> AND 0001 -> Result=0000 ->Even 1's -> PF=1 -> EVEN     
                    ; If BL is 0101 (ODD as LSB is 1) -> AND 0001 -> Result=0001 -> Odd 1's -> PF=0 -> ODD 
        
        JNP ODD
        
        
        ; (Alternative Option using Zero Flag:)
        ; jz EVEN        ; If result of AND = 0 ? even
        ; jnz ODD        ; If result of AND ? 0 ? odd
                    
        
        EVEN:
            
            lea dx, msg_Even
            mov ah, 09h
            int 21h
            jmp EXIT
            
        ODD:
                
            lea dx, msg_Odd
            mov ah, 09h
            int 21h
        
        EXIT:
            MOV AH, 4Ch
            int 21h
            
    MAIN ENDP
end main
.exit
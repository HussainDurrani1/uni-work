include 'emu8086.inc'
.stack 100h
.model small

.data


.code

main proc
print 'Enter Your Character: '

mov ah, 01h
int 21h

mov bl, al

mov dl, 10
mov ah, 02h
int 21h

mov dl, 13
mov ah, 02h
int 21h

print 'Your Character: '

mov dl, bl

mov ah, 02h
int 21h

main endp
end main


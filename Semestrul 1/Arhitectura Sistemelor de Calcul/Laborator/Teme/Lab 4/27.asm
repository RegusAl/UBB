; Se da quadwordul A. 
; Sa se obtina numarul intreg N reprezentat de bitii 35-37 ai lui A. 
; Sa se obtina apoi in B dublucuvantul rezultat prin rotirea spre dreapta a dublucuvantului inferior al lui A cu N pozitii. 

; Sa se obtina octetul C astfel:

;   bitii 0-3 ai lui C sunt bitii 8-11 ai lui B
;   bitii 4-7 ai lui C sunt bitii 16-19 ai lui B

; Date de test: a = 12348a9f5678af9a

bits 32

global start                

extern exit
import exit msvcrt.dll

; A - quadword, 
segment data use32 class=data
    a dq 12348a9f5678af9ah 
    b resw 2 ; se rezerva 2 words  = 1 doubleword
    c resb 1 ; se rezerva un octet
    n resb 1
    
    ; n = 3
    ; c = f5
    
segment code use32 class=code
    start:
    
        mov bx, 0   ; in registrul bx vom calcula rezultatul
    
       mov eax, [a]
       mov edx, [a+4]               ; edx:eax = a
       
       and edx, 0000009fh
       and dl, 0011_1000b
       mov cl, 3
       ror dl, cl                           ; dl  = 0000_0101b
       mov [n], dl
      
       mov cl, [n]
       ror eax, cl                  ; se roteste la dreapta doubleword-ul inferior (eax) a lui a cu n pozitii
       mov [b], eax

       and ax, 0000_1111_0000_0000b   ; izolam bitii 8-11 ai lui b
       mov cl, 8
       ror ax, cl
       or bx, ax  
       
       mov ax, [b+2]
       and al, 0000_1111b    ; izolam bitii 16-19 ai lui b
       mov cl, 4
       rol al, cl          
       or bx, ax
       
      mov [c], bx ; punem valoarea din registru in variabila rezultat
       
     push dword 0
     call [exit]


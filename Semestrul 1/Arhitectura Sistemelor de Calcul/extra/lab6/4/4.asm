; Se da un sir de octeti s. Sa se construiasca sirul de octeti d, care contine pe fiecare pozitie numarul de biti 1 ai octetului de pe pozitia corespunzatoare din s.
; Exemplu:
; s: 5, 25, 55, 127
; in binary: 101, 11001,10111,1111111
; d: 2, 3, 5, 7
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 5, 25, 55, 127
    len equ ($-s)
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        
        cld             ; CLD = 0
        mov esi, s      
        mov edi, d
        
        repeta:
           lodsb    ; AL = s[ESI]         ; AL = <DS:ESI>
           push ecx      ; protejam ECX
           mov ecx, 8    ; ECX = 8 pentru a face 8 cicluri
           mov bl, 0     ; in BL vom numara numarul de biti 1
            numara:
                shr al, 1     ; shift right cu 1 bit
                adc bl, 0     ; BL = BL + 0 + CF
            loop numara
            mov al, bl        ; AL = BL
            stosb        ; d[edi] = AL    ; <ES:EDI> = AL
           pop ecx       ; scoatem din stiva ECX pentru a continua ciclurile
        loop repeta
        
    final:
    push dword 0
    call [exit]
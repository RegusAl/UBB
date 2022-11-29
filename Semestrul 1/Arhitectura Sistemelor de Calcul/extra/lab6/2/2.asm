; Se da un sir de cuvinte.
; Sa se obtina din acesta un sir de dublucuvinte, in care fiecare dublucuvant
; va contine nibble-urile despachetate pe octet (fiecare cifra hexa va fi precedata de un 0), aranjate crescator in interiorul dublucuvantului.
; Exemplu:
; pentru sirul initial:
; 1432h, 8675h, 0ADBCh, ...
; Se va obtine:
; 01020304h,  05060708h, 0A0B0C0Dh, ... 
bits 32
global start

extern exit
import exit msvcrt.dll


segment data use32 class=data
	s dw 1432h, 8675h, 0ADBCh
    len equ ($-s)/2
    octeti times 4 db 0
    d times len dd 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        cld
        mov edi, d
        mov esi,0
        
        parcurg_sirul:
        
        push ecx
        push edi
        
        ; 1. obtin sirul de octeti
        mov ecx, 2
        ;mov edi, octeti
        formez_octeti:
            mov al, [s+esi]      ; AL = 32h
            mov dl, al           ; DL = 32h
            and al, 0000_1111b   ; AL = 02h
            and dl, 1111_0000b
            shr dl, 4           ; DL = 03h
            stosb
            mov al, dl
            stosb
            inc esi
        loop formez_octeti
 
        pop ecx
        loop parcurg_sirul
        
        final:
    push dword 0
    call [exit]
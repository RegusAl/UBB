bits 32

global suma_hexa

extern exit
import exit msvcrt.dll

segment data use32 class=data
    hexa db 16

segment code use32 class=code
    suma_hexa:
        ; [ESP + 0] -> Adresa de revenire
        ; [ESP + 4] -> Sirul de sume
        ; [ESP + 8] -> Sirul de dublucuvinte
        ; [ESP + 12] -> Lungimea sirului
        mov ecx, [esp+12]
        mov esi, [esp+8]
        mov edi, [esp+4]
        cld
        repeta:
            lodsd ; eax = sir[esi]
            push ecx
            mov ecx, 8    ; 
            mov ebx, 0    ; EBX = suma cifrelor in baza 16
            shiftare:
                mov edx, 0
                div dword [hexa]
                add ebx, edx
            loop shiftare
        
            mov al, bl
            stosb
        
            pop ecx
        loop repeta
        
        ret

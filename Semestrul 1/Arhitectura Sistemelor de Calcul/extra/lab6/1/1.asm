; Se da un sir de dublucuvinte continand date impachetate (4 octeti scrisi ca un singur dublucuvant). Sa se obtina un nou sir de dublucuvinte, in care fiecare dublucuvant se va obtine dupa regula: suma octetilor de ordin impar va forma cuvantul de ordin impar, iar suma octetilor de ordin par va forma cuvantul de ordin par. Octetii se considera numere cu semn, astfel ca extensiile pe cuvant se vor realiza corespunzator aritmeticii cu semn.
 
;   Exemplu:
;       Pentru sirul initial: 127F5678h, 0ABCDABCDh, ... 
;       Se va obtine: 006800F7h,  0FF56FF9Ah 
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s dd 127F5678h, 0ABCDABCDh
    len equ ($-s)/4
    d times len dd 0

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, s
        mov edi, d
        cld
        repeta:
            lodsd
            mov ebx, eax
            ; luam octetii impari si ii adunam
            and eax, 1111_1111__0000_0000_1111_1111_0000_0000b
            shr eax, 8
            mov dl, al
            shr eax, 16
            cbw
            adc al, dl
            cbw
            push ax
            ; luam octetii pari si ii adunam
            mov eax, ebx
            and eax, 0000_0000__1111_1111_0000_0000_1111_1111b
            mov dl, al
            shr eax, 16
            cbw
            adc al, dl
            push ax
            
            pop eax
            stosd
        loop repeta
        
    final:
    push dword 0
    call [exit]
bits 32

global _concateneaza

segment data use32 class=data  

segment code use32 class=code
    _concateneaza:
        push ebp
        mov ebp, esp
        
        ; 1. copiez sirul s1 in sirul final s
        cld
        xor ebx, ebx            ; numar caractere
        mov esi, [ebp+8]
        mov edi, [ebp+16]
    loop_1:
        lodsb
        
        cmp al, 0
        je pas_2
        
        stosb
        inc ebx
        jmp loop_1
        
        ; 2. adaug sirul s2 la sirul final s
    pas_2:
        mov esi, [ebp+12]
    loop_2:
        lodsb
        
        cmp al, 0
        je iesire
        
        stosb
        inc ebx
        jmp loop_2
        
    iesire:
        ; termin sirul final s cu ZERO
        mov al, 0
        stosb
        
        ; stochez numarul de caractere in EAX
        mov eax, ebx
        
        mov esp, ebp
        pop ebp
        
        ret
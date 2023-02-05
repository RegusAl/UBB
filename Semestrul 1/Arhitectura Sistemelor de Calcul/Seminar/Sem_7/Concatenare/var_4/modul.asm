bits 32

global _concateneaza

segment data use32 class=data
    max_len equ 100     ; numarul maxim de caractere din sirul final
    
segment code use32 class=code
    _concateneaza:
        push ebp
        mov ebp, esp
        
        sub esp, max_len        ; aloc spatiu de stocare a sirului final pe stiva
        
        ; 1. copiez sirul s1 in sirul final
        cld
        xor ebx, ebx            ; numar caractere
        mov esi, [ebp+8]
        mov edi, [ebp-max_len]
        push edi                ; stochez pe stiva offset-ul primului caracter din sirul final
    loop_1:
        lodsb
        
        cmp al, 0
        je pas_2
        
        stosb
        inc ebx
        jmp loop_1
        
        ; 2. adaug sirul s2 la sirul final
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
        
        pop eax             ; pun in EAX offset-ul primului caracater din sirul final
        
        add esp, 25*4       ; eliberez spatiul alocat pe stiva pentru sirul final
        
        mov esp, ebp
        pop ebp
        
        ret

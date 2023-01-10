bits 32

global _dublare

segment code public code use32
_dublare:
    ; creare cadru de stiva pentru programul apelat
    push ebp
    mov ebp, esp
    
    ; argumente
    ; [ebp] - valoarea ebp pentru apeland
    ; [ebp+4] - adresa de retur
    ; [ebp+8] - adresa vector
    ; [ebp+12] - lungime vector
   
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
    mov edi,[ebp+8]
    cld

    repeta:
        lodsd               ; eax = v[esi]
        add eax,eax
        stosd               ; v[edi] = v[esi] = eax + eax

    loop repeta

    mov eax,[ebp+8]

    ; refacem cadrul de stiva
    mov esp, ebp
    pop ebp

    ret
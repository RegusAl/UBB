bits 32

; informam asamblorul ca dorim ca functia sa fie disponibila altor unitati de compilare
global _dublare


; codul scris in asamblare este dispus intr-un segment public, posibil a fi partajat cu alt cod extern
segment code public code use32

; int dublare(int, int)
; conventie cdecl
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
        lodsd ; eax <- v[esi]
        add eax,eax
        stosd ;v[edi]=v[esi]=2*eax

    loop repeta

    mov eax,[ebp+8] ;returned value

    ; refacem cadrul de stiva pentru programul apelant
    mov esp, ebp
    pop ebp

    ret
    ; conventie cdecl - este responsabilitatea programului apelant sa elibereze parametrii transmisi
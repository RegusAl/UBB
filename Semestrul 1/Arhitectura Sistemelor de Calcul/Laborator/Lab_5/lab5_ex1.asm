bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 'a', 'b', 'c', 'm', 'n'    ; declararea sirului initial s
	len equ $-s                     ; stabilirea lungimea sirului initial l
	d times len db 0                ; rezervarea unui spatiu de dimensiune l pentru sirul destinatie d si initializarea acestuia
	
; Se da un sir de caractere format din litere mici.
; Sa se transforme acest sir in sirul literelor mari corespunzator.
segment code use32 class=code
    start:
        mov ecx, len    ; ECX = lungimea sirului initial s
        jecxz sfarsit
        mov esi, 0      ; i = 0
        mov edi, 0      ; j = 0
    repeta:
        ; citesc s[i]
        mov al, [s+esi]
        
        ; transform in litera mare corespunzatoare
        mov bl, 'a'-'A'
        sub al, bl
        
        ; pun in d[i]
        mov [d+edi], al
    
        inc esi         ; i++
        inc edi         ; j++
    loop repeta
        
    sfarsit:
        push dword 0
        call [exit]

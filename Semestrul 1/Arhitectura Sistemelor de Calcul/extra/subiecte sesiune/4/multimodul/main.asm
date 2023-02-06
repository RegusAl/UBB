; se da sir de qwords, verific daca dword ul inferior are minim 2 secvente de 111 in binar
;daca are, salvez dword ul inferior si il afisez pe ecran in baza 2
bits 32

global start

extern exit, printf, degree
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir dq 1110111b, 100000000h, 0ABCD0002E7FCh, 5
    len_sir equ ($-sir)/8
    rez times len_sir dd 0
    format_hexa db "%x ", 0
    format_dec db "%d", 0
    afisare db " ", 0
    
segment code use32 class=code
    start:
    
        mov ecx, len_sir ; pentru a cicla cele len_sir qword-uri
        mov esi, 0
        mov edi, 0
        repeta:
            push ecx
            mov eax, [sir+esi*8]    ; eax - dwordul inferior
            
            mov bl, 0      ; contorul in care punem degree-ul
            
            mov dl, 0      ; punem numarul de biti 1 consecutivi
            mov dh, 0
            
            push eax
            call degree
            add esp, 4
            
            cmp bl, 2           ; daca degree-ul este peste 2, vom afisa 
            jb nu_afiseaza
            
            mov eax, [sir+esi*8]
            mov [rez+edi*4], eax        ; punem in sirul rez
            
            ; afisare in hexa
            ; pushad
            
            ; push dword eax
            ; push dword format_hexa
            ; call [printf]
            ; add esp, 2*4
            
            ; popad 
           
             
            inc(edi)
            
            nu_afiseaza:
            
            inc(esi)
            
            pop ecx
        loop repeta
            
        mov ecx, edi
        mov esi, 0
        parcurgere_rez:         ; parcuregere rez
            
            push ecx
            mov eax, [rez+esi*4]
            mov ecx, 32
            afisare_biti:
            
            shl eax, 1
            push eax
            push ecx
            jc unu
            
            push dword 0
            push dword format_dec
            call [printf]
            add esp, 2*4
            
            jmp gata_afisat_bit
            
            unu:
            
            push dword 1
            push dword format_dec
            call [printf]
            add esp, 2*4
            
            gata_afisat_bit:
            
            pop ecx
            pop eax
            
            loop afisare_biti
            
            push dword afisare
            call [printf]
            add esp, 4
            
            pop ecx
        
            inc(esi)
        loop parcurgere_rez
    
    
    push dword 0
    call [exit]
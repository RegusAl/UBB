; Se da un sir de qword definit in data segment. elementele sirului sunt in baza 16
; a) sa se printeze bytes care compun qword urile din sir
; b) sa se identifice words care au ultima cifra egala cu constanta k definita in segmentul de date. sa se salveze aceste words in sirul d
; c) sa se identifice dwords care sunt cuprinse in intervalul AAA - FFFF. sa se determine numarul dwords din acest interval. sa se afiseze acest numar in baza 10 in fisierul 'iesire.txt'
bits 32

global start

extern exit, printf, fopen, fclose, fprintf
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    quads dq 0AAAAh, 12345678h, 23005h, 0AAh, 011A2B3C5FFFFh, 0FFFFh
    numar_bytes equ ($-quads)
    format_printare_bytes db "%x ", 0
    afisare_bytes db "Bytes: ", 0
    endline db " ", 10, 13, 0
    k dw 2h
    words times 10 dw 0
    hexa dw 010h
    nume_fisier db "iesire.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    format_dec db "%d", 0
    
segment code use32 class=code
    start:
    
    ; a) printare bytes
    push dword afisare_bytes
    call [printf]
    add esp, 1*4
    
    mov ecx, numar_bytes
    mov esi, quads
    printare_bytes:
    
        push ecx
        
        mov eax, 0
        lodsb      ; al = quads[esi]  -> eax = quads[esi]
        
        push dword eax
        push dword format_printare_bytes
        call [printf]
        add esp, 2*4
        
        pop ecx
    
    loop printare_bytes
    
    push dword endline
    call [printf]
    add esp, 1*4
    
    ; b) identificare words ce au ultima cifra egala cu k
    mov ecx, numar_bytes/2
    mov esi, quads
    mov edi, words
    repeta_words:
    
        push ecx
        
        mov eax, 0
        lodsw
        
        mov bx, ax
        
        div word [hexa]         ; dx = eax % 16
        cmp dx, word [k]
        jne peste_word
        
        mov ax, bx
        stosw
        
        peste_word:
        
        pop ecx
    
    loop repeta_words
    
    ; c) identificare dwords in intervalul AAA-FFFF
    
    ; deschidere fisier
    push dword mod_acces
    push dword nume_fisier
    call [fopen]
    add esp, 2*4
    
    ; verificare fisier 
    cmp eax, 0
    je final
    mov [descriptor_fisier], eax
    
    mov ecx, numar_bytes/4
    mov esi, quads
    mov ebx, 0
    repeta_dwords:
        
        push ecx
        
        lodsd       ; eax = quads[esi]
        cmp eax, 0AAAh
        jl peste_dword
        
        cmp eax, 0FFFFh
        jg peste_dword
        
        add ebx, 1
        
        peste_dword:
        
        pop ecx
        
    loop repeta_dwords
    
    ; afisare numar de dword in fisier
    push dword ebx
    push dword format_dec
    push dword [descriptor_fisier]
    call [fprintf]
    add esp, 3*4
    
    final:
    ; inchidere fisier
    push dword [descriptor_fisier]
    call [fclose]
    add esp, 1*4
    
    push dword 0
    call [exit]
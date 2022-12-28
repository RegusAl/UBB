;Se da un fisier text. Fisierul contine numere (in baza 10) separate prin spatii.
   ;Sa se citeasca continutul acestui fisier, sa se determine minimul numerelor citite
   ;si sa se scrie rezultatul la sfarsitul fisierului
bits 32 
global start        

extern exit, fopen, fread, fclose, fprintf, printf
    import exit msvcrt.dll  
    import fopen msvcrt.dll  
    import fread msvcrt.dll
    import fclose msvcrt.dll
    import fprintf msvcrt.dll
    import printf msvcrt.dll


segment data use32 class=data
    nume_fisier db "fisier.txt", 0  ; numele fisierului care va fi deschis
    mod_acces db "a+", 0          ; modul de deschidere a fisierului - 
    format db 'Cel mai mic numar este: %s', 0
    numar times 4 db 0
    inumar times 4 db 0
    descriptor_fis dd -1
    len equ 20
    sir times len dd 0
    

segment code use32 class=code        
    start:
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_fis], eax
        
        cmp eax, 0
        je final
        
        push dword [descriptor_fis]
        push dword len
        push dword 4
        push dword sir        
        call [fread]
        add esp, 4*4
        
        mov ecx, eax
        inc ecx
        
        mov esi, sir
        mov edi, 0
        xor ebx, ebx
        mov edx, 2147483647
        lp:
            cld
            lodsb
            cmp al, ' '
            je verifica
            shl ebx, 8
            mov bl, al
            jmp sf
            verifica:
            inc edi
                cmp ebx, edx
                jl schimba
                xor ebx, ebx
                jmp sf
            schimba:
                mov edx, ebx
                xor ebx, ebx
        sf:
        cmp edi, ecx
        jne lp
        mov [numar], edx
        mov ecx, 4
        mov esi, numar
        add esi, 3
        mov edi, inumar
        invers:
            std
            lodsb
            cld
            cmp al, 0
            je e0
            stosb
            e0:
        loop invers
        
        
        final:
        
        push dword inumar
        push dword format
        push dword [descriptor_fis]
        call [fprintf]
        add esp, 4*3
        
        
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
        push    dword 0
        call    [exit]

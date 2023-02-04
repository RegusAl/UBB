bits 32             ; lucram pe 32 de biti
global start        

extern exit, printf, suma_hexa
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data       ; segmentul de date
    sir dd -1,123456,0xabcdeff,0xabcdeff,0xcbcdeff,0xdbcdeff,0111010101b    ;sirul dublucuvintelor
    len_sir equ ($-sir) / 4
    sir_sume times len_sir db 0
    suma db 0
    format_dec db "%d ", 0
    format_hex db "%x ", 0
    format_desc db "( ", 0
    format_inc db " )", 0ah
    ok db 0
    secvente times len_sir db 0
    
segment code use32 class=code       ; segmentul de cod
    start:
    
    push dword len_sir      
    push dword sir
    push dword sir_sume
    
    call suma_hexa      ; apelam functia suma_hexa din modulul b.asm
    
    add esp, 4*3        ; curatam stiva
    
    ; secvente strict crescatoare
    mov ecx, len_sir-1
    mov esi, 0
    mov edi, 0
    cld
    gasire_secvente:
        push ecx
        
        mov al, [sir_sume+esi]
        cmp al, [sir_sume+esi+1]        ; comparam sumele doua cate doua
        jge peste
        
        cmp byte [ok], 0
        jne nu_arcolada
        
        push dword format_desc
        call [printf]
        add esp, 1*4
        
        nu_arcolada:
           
        push dword [sir+esi*4]
        push dword format_hex
        call [printf]
        add esp, 2*4
        
        mov byte [ok], 1
        
        jmp next
        
        peste:
        
        cmp byte [ok], 0
        je next
        
        mov byte [ok], 0
        
        push dword [sir+esi*4]
        push dword format_hex
        call [printf]
        add esp, 2*4
        
        push dword format_inc
        call [printf]
        add esp, 1*4
        
        next:
        
        inc(esi)
    
        pop ecx
    loop gasire_secvente
    
    push dword 0
    call [exit]
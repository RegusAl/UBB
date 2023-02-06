bits 32

global degree

segment code use32 class=code
    degree:
        
        mov ecx, 32    ; punem in ECX 32 deoarece atatea shiftari vom face
            aflare_degree:
                
                shr eax, 1      ; shiftam pentru a afla carryflag
                adc dl, 0
                
                cmp dl, 0       ; comparam dl cu 0
                jne nu_zero
                mov dh, 0
                jmp peste
                nu_zero:
                add dh, 1
                
                cmp dh, 3       ; vedem daca avem un degree
                jne peste
                mov dh, 0
                add bl, 1
                
                peste:
                
                mov dl, 0

            loop aflare_degree
        
        ret
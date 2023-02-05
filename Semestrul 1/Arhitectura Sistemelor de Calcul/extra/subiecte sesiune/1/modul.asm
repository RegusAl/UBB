bits 32

global numarare_biti

segment code use32 class=code
    numarare_biti:
        mov ecx, 16     ; punem in ecx 16 deoarece vom face 16 shiftari
        mov eax, [esp+4]
        biti:  ; numaram bitii de 1 din word (ax)
            shl ax, 1
            adc edx, 0  ; adunam in edx suma de biti 1 (CF = 1)
        loop biti
    ret
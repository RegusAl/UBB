bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
	s1 db 12h, 23h, 56h, 34h, 45h, 67h, 78h, 89h
    s2 db 34h, 12h, 56h, 45h, 23h, 78h, 89h, 67h

; 5. Se dau două șiruri de octeți s1 și s2 de lungimi egale.
; Să se determine poziția p în care elementele ambelor șiruri sunt egale.
segment code use32 class=code
    start:
        
        ; exit(0)
        push dword 0
        call [exit]

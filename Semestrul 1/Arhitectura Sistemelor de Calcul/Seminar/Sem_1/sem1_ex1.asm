; programez pe 32 de biti
bits 32

; declar punctul de intrare in program
; (o eticheta care indica prima instructiune din program)
global start

; declar functiile externe pe care le voi folosi
extern exit
import exit msvcrt.dll

; segmentul de date
; aici vom declara datele (constante, variabile etc.)
segment data use32 class=data
    a dw 3
    b dw 4
    c dw 2
    x dw 0

; segmentul de cod
; aici vom scrie programul
; calculez expresia x = a + b - c, unde a, b, c, x - word
segment code use32 class=code
    start:
        mov ax, [a]     ; ax = a = 3
        add ax, [b]     ; ax = ax + b = a + b = 3 + 4 = 7
        sub ax, [c]     ; ax = ax - c = a + b - c = 7 - 2 = 5

        mov [x], ax     ; x = ax = a + b - c = 5
        
        ; exit(0)
        push dword 0    ; pun pe stiva argumentul functiei exit()
        call [exit]     ; apelez functia exit() pentru a incheia programul

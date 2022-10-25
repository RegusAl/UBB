bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; a,b,c,d-byte, e,f,g,h-word
segment data use32 class=data
   a db 110
   b db 20
   c db 30
   d db 40
   e dw 100
   f dw 150
   g dw 200
   h dw 250

; 19. (e + g) * 2 / (a * c) + (h – f) + b * 3
segment code use32 class=code
    start:
        ; (e+g)
        mov ax,[e]
        add ax,[g] ;ax=e+g
        
        ;(e+g)*2
        mov bx,2
        mul bx ; dx:ax=ax*bx=ax*2
        ;mov bx,ax
        ;mov cx,dx ;cx:bx=dx:ax=(e+g)*2 - mut rezultatul din dx:ax
        push dx
        push ax
        
        ;(a*c) 
        mov al,[a]
        mul byte [c] ;ax=al*c=a*c 
        
        ;(e+g)*2/(a*c)
        ;(e+g)*2 este un dw
        ;(a*c) este un w
        ;push ax
        ;mov dx,cx
        ;mov ax,bx ; pun inapoi in dx:ax (e+g)*2
        ;pop bx ;bx=(a*c)
        mov bx,ax 
        pop ax
        pop dx
        div bx ;ax=dx:ax/bx=(e+g)*2/(a*c) si dx=dx:ax%bx
  
        ;(h-f)
        mov dx,[h]
        sub dx,[f]; dx=h-f
        
        ;(e + g) * 2 / (a * c) + (h – f)
        add ax,dx; ax=(e + g) * 2 / (a * c) + (h – f)
        
        ;b*3
        mov cx,ax; pastrez in cx rezultatul (e + g) * 2 / (a * c) + (h – f)
        mov al,[b]
        mov bl,3
        mul bl ;ax=al*bl=b*3
        add cx,ax ;cx=cx+ax=(e + g) * 2 / (a * c) + (h – f) + b*3
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

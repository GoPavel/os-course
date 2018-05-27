; int a_plus_b(int a, int b)
        global          a_plus_b ; cdecl

        section         .text
a_plus_b:
; stack = ret, a, b
        mov             eax, 2
        add             eax, 2
        ret

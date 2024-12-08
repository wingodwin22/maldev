section .data
    msg db 'Bien joue Godwin', 0xA ; Message à afficher (avec un saut de ligne)

section .text
    global _start

_start:
    ; Afficher "Bien joué Godwin"
    mov rax, 0x1          ; sys_write
    mov rdi, 0x1          ; STDOUT
    mov rsi, msg          ; adresse du message
    mov rdx, 18           ; longueur du message
    syscall

    ; Sauter à l'adresse du point d'entrée du programme (0x1090)
    jmp 0x1090

    ; Exit le shellcode
    mov rax, 60           ; sys_exit
    xor rdi, rdi          ; code de sortie 0
    syscall

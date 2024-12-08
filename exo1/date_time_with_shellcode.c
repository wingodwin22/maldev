#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

unsigned char shellcode[] = {
    // Copiez ici le shellcode en hexadécimal
    0x48, 0x31, 0xc0, 0x48, 0x31, 0xff, 0x48, 0x31, 0xf6, 0x48, 0x31, 0xd2, 0x48,
    0x8d, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00,
    0x00, 0x60, 0x0f, 0x00, 0x00
};

int main() {
    // Exécuter le shellcode
    void (*func)() = (void (*)())shellcode;
    func(); // Appel du shellcode pour afficher "Bien joué Godwin"
    
    // Logic du programme principal
    time_t t = time(NULL);
    if (t != (time_t)(-1)) {
        struct tm *tm_info = localtime(&t);
        
        char buffer[26];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Date et heure actuelle : %s\n", buffer);
    } else {
        printf("Erreur lors de la récupération de l'heure actuelle.\n");
    }

    return 0;
}

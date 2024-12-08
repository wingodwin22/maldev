#include <stdio.h>
#include <time.h>

int main() {
    // Créer un objet time_t pour stocker l'heure actuelle
    time_t t = time(NULL);
    
    // Si l'heure actuelle a pu être récupérée, on l'affiche
    if (t != (time_t)(-1)) {
        struct tm *tm_info = localtime(&t);
        
        // Afficher la date et l'heure sous un format lisible
        char buffer[26];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Date et heure actuelle : %s\n", buffer);
    } else {
        printf("Erreur lors de la récupération de l'heure actuelle.\n");
    }

    return 0;
}


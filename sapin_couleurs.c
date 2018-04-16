// #include "sapin.h"

// Version colorée

void my_putchar(char c) {
    write(1,&c,1);
}

void my_putstr(char *str) {
    int longueur = 0;
    while (str[longueur]!='\0')
    {
        write(1,&str[longueur],1);
        longueur++;
    }
}

int nb_etoiles_actuel(int i) {
    int etoiles = 0;
    while (etoiles < i)
        etoiles++;
    return (etoiles);
}

int nb_etoiles_max(int n) {
    int i = 0;  // compteur d'étages
    int j = 4;  // compteur de niveaux par étage
    int k = 1;  // nombre d'étoiles à afficher par étage
    int l = 0;
    int etoiles = 0;
    int soustraire_etoiles = 0;

    while (i < n)                       // nombre d'étages totaux
    {
        if (i > 1 && i%2 == 0)          // si on est à un étage impair
                soustraire_etoiles+=2;  // s'incrémente de 1 à chaque étage impair (modulo inverse à cause de i qui commence à 0)
        while (l < j+i)                 // nombre de niveaux par étage
        {
            while (etoiles < k)         // nombre d'étoiles
                etoiles++;
            k+=2;                       // 2 étoiles supplémentaires par niveau
            l++;
        }
        k=k-soustraire_etoiles-4;
        l = 0;
        i++;
    }
    return (etoiles);
}

void my_sapin(int n) {
    int i = 0;  // compteur d'étages
    int j = 4;  // nombre de niveaux par étage (ne change jamais)
    int k = 1;  // nombre d'étoiles à afficher par étage
    int l = 0;  // compteur nombre de niveaux (par étage)
    int etoiles = 0;
    int espaces = 0; // calculer nb étoiles final et soustraire nb étoiles étage actuel
    int etoiles_max = nb_etoiles_max(n);
    int soustraire_etoiles = 0;
    int deco1 = 0;
    int deco2 = 0;
    int deco3 = 0;

    // Fabrication du feuillage
    while (i < n)                       // i = étage actuel / n = nombre d'étages totaux
    {
        if (i > 1 && i%2 == 0)          // si on est à un étage impair
                soustraire_etoiles+=2;  // incrémente le nombre d'étoiles à soustraire
        while (l < j+i)                 // l = niveau actuel / j+i = nombre de niveaux par étage
        {
            espaces = ((etoiles_max - (nb_etoiles_actuel(k)))/2);
            while (espaces > 0)         // nombre d'espaces
            {
                my_putchar(' ');
                espaces--;
            }
            while (etoiles < k)         // nombre d'étoiles
            {
                deco1 = rand()%etoiles_max+1;
                deco2 = rand()%etoiles_max+1;
                deco3 = rand()%etoiles_max+1;
                my_putstr(YELLOW_FOND);
                my_putstr(GREEN);
                if (etoiles == deco1) {
                    my_putstr(RED);
                    my_putstr(RED_FOND);
                    }
                if (etoiles == deco2) {
                    my_putstr(MAGENTA);
                    my_putstr(MAGENTA_FOND);
                    }
                if (etoiles == deco3) {
                    my_putstr(CYAN);
                    my_putstr(CYAN_FOND);
                    }
                if (k == 1) {
                    my_putstr(GREEN_FOND);
                    my_putstr(YELLOW);
                }
                my_putchar('*');
                my_putstr(COLOR_RESET);
                etoiles++;
            }
            etoiles = 0;
            my_putchar('\n');
            k+=2;   // incrémente le nombre d'étoiles max par niveau
            l++;
        }
        k=k-soustraire_etoiles-4;
        l = 0;
        i++;
    }
    i = 0;
    k = 0;
    // Fabrication du tronc
    while (i < n)
    {
        k = n;
        // k prend la valeur de n
        // (pour gérer les cas impairs où la largeur est plus grande de 1)
        espaces = (etoiles_max - n)/2;
        while (espaces > 0)
        {
            my_putchar(' ');
            espaces--;
        }
        if (n%2==0)
            k++;
        while (l < k)
        {
            my_putstr(YELLOW);
            my_putchar('|');
            my_putstr(COLOR_RESET);
            l++;
        }
        l = 0;
        my_putchar('\n');
        i++;
    }
}

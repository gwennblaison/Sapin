#include "sapin.h"

int main(int argc, char *argv[]) {
    if (argc!=2)    // on attend au minimum 1 argument (la taille)
    {
        my_putstr("Error.\n");
        return (1);
    }
    else
    {
        int i = 0;
        int j = 0;
        while (argv[1][i] != '\0')
        {
            j = argv[1][i];
            if (j < 48 || j > 57)
            {
                my_putstr("Error.\n");
                return (1);
                // erreur si tous les caractères passés en argument 1 ne sont pas des chiffres
            }
            i++;
        }
        if (atoi(argv[1]) <= 0 || atoi(argv[1]) > 100 || argv[1] == NULL)
        {
            my_putstr("Please chose a size between 1 and 100.\n");
            return (1);
            // erreur si la valeur passée est nulle ou négative
        }
        else
            my_sapin(atoi(argv[1]));
            // on appelle la fonction si tout est correct
    }
    return (0);
}

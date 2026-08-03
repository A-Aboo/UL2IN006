#include <stdio.h>

int evalExp(char *exp);

int main(void)
{
    char exp[] = "((5+2)*3)";
    int resultat = evalExp(exp);

    printf("Expre: %s\n", exp);
    printf("Res  : %d\n", resultat);

    return 0;
}
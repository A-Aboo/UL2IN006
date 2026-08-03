#include "pile.h"

Pile *creerPile(void)
{
    Pile *p = malloc(sizeof(Pile));
    p->top = -1;
    return p;
}

int pileVide(Pile *p)
{
    return p->top == -1;
}

void empile(Pile *p, int valeur)
{
    p->top++;
    p->tab[p->top] = valeur;
}

int depile(Pile *p)
{
    if (pileVide(p))
        return 0;
    int valeur = p->tab[p->top];
    p->top--;
    return valeur;
}


int evalExp(char *exp)
{
    int n1, n2, res;
    char op;
    Pile *p = creerPile();

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];
        if (c >= '0' && c <= '9')
            empile(p, c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            empile(p, c);
        else if (c == ')')
        {
            n2 = depile(p);
            op = depile(p);
            n1 = depile(p);

            if (op == '+')res = n1 + n2;
            else if (op == '-')res = n1 - n2;
            else if (op == '*')res = n1 * n2;
            else res = n1 / n2;
            empile(p, res);
        }
    }

    res = depile(p);
    free(p);

    return res;
}
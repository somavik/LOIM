#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "debugmalloc.h"
#include "fomenu.h"

char fomenu()
{
    char s;
    printf("\n\n\n\n\n");
    printf("        Legyen �n is Milliomos!\n");
    printf("            �j j�t�k(1)\n");
    printf("           Dics�s�glista(2)\n");
    printf("            Kil�p�s(3)\n");
    printf("            V�laszt�s:");
    scanf(" %c", &s);
    return s;
}

char ujjatek()
{
    char s;
    printf("\n\n\n\n\n");
    printf("         V�lassz j�t�km�dot!\n");
    printf("              Tv-s(0)\n");
    printf("     Meghat�rozott neh�zs�g(1)\n");
    printf("            V�laszt�s:");
    scanf(" %c", &s);
    return s;
}

void nehezsegbeo(int *nehezseg)
{
    printf("V�lassz neh�zs�gi fokozatot!");
    scanf("%d", nehezseg);
    if(*nehezseg>15 || *nehezseg<1)
        {
        while(*nehezseg>15 || *nehezseg<1)
            {
            system("cls");
            printf("Hib�s bemenet!\n");
            printf("V�lassz neh�zs�gi fokozatot!");
            scanf("%d", nehezseg);
            }
        }
}

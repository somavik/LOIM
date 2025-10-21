#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "debugmalloc.h"
#include "fomenu.h"

char fomenu()
{
    char s;
    printf("\n\n\n\n\n");
    printf("        Legyen Ön is Milliomos!\n");
    printf("            Új játék(1)\n");
    printf("           Dicsõséglista(2)\n");
    printf("            Kilépés(3)\n");
    printf("            Választás:");
    scanf(" %c", &s);
    return s;
}

char ujjatek()
{
    char s;
    printf("\n\n\n\n\n");
    printf("         Válassz játékmódot!\n");
    printf("              Tv-s(0)\n");
    printf("     Meghatározott nehézség(1)\n");
    printf("            Választás:");
    scanf(" %c", &s);
    return s;
}

void nehezsegbeo(int *nehezseg)
{
    printf("Válassz nehézségi fokozatot!");
    scanf("%d", nehezseg);
    if(*nehezseg>15 || *nehezseg<1)
        {
        while(*nehezseg>15 || *nehezseg<1)
            {
            system("cls");
            printf("Hibás bemenet!\n");
            printf("Válassz nehézségi fokozatot!");
            scanf("%d", nehezseg);
            }
        }
}

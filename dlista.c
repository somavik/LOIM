#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "debugmalloc.h"
#include "strukturak.h"
#include "dlista.h"

void add(Lista *lista, jatekos *adat)
{
    dlista *mozgo = lista->elso->kov;
    dlista *uj = (dlista*)malloc(sizeof(dlista));
    uj->adat.eredmeny = adat->eredmeny;
    uj->adat.nev = adat->nev;
    uj->adat.ido = adat->ido;


    while (mozgo != lista->utolso && mozgo->adat.eredmeny > adat->eredmeny)
        mozgo = mozgo->kov;

    uj->elozo = mozgo->elozo;  /* õ a szomszédaira mutat */
    uj->kov = mozgo;
    mozgo->elozo->kov = uj;    /* a szomszédai rá */
    mozgo->elozo = uj;
}

void dfelsz(Lista *lista)
{
    dlista *mozgo = lista->elso->kov;
    dlista *kov;

    while (mozgo != lista->utolso) {
        kov = mozgo->kov;
        free(mozgo->adat.nev);
        free(mozgo);
        mozgo = kov;
    }
    free(lista->elso);
    free(lista->utolso);

}

void init(Lista *lista)
{
    lista->elso = (dlista*)malloc(sizeof(dlista));
    lista->utolso = (dlista*)malloc(sizeof(dlista));

    // Az elsõ strázsát inicializáljuk
    lista->elso->adat.nev = NULL;
    lista->elso->adat.eredmeny = 0;
    lista->elso->adat.kozonseg = false;
    lista->elso->adat.felezo = false;
    lista->elso->elozo = NULL;
    lista->elso->kov = lista->utolso;

    // A második strázsát inicializáljuk
    lista->utolso->adat.nev = NULL;
    lista->utolso->adat.eredmeny = 0;
    lista->utolso->adat.kozonseg = false;
    lista->utolso->adat.felezo = false;
    lista->utolso->elozo = lista->elso;
    lista->utolso->kov = NULL;
}

void dfajlbeo(Lista *lista)
{
    char tt[100][255];
    int i=0;
    FILE* fp;
    fp=fopen("dlista.txt", "r");
    while(fgets(tt[i], 255, fp)!=NULL)
    {

        i++;
    }
    fclose(fp);
    int meret=i;
    char *ttt[8];
    for(i=1;i<meret-1;i++)
    {
    const char s[2] = "\t";
    char *token;
    int segindex = 0;
    token = strtok(tt[i], s);
    while( token != NULL )
        {
        ttt[segindex]=token;
        token = strtok(NULL, s);
        segindex++;
        }
    jatekos uj;
    uj.nev = (char*)malloc((strlen(ttt[0])+1) * sizeof(char));
    if(uj.nev==NULL) printf("Nem sikerult memoriat foglalni");
    strcpy(uj.nev, ttt[0]);
    uj.eredmeny=((unsigned int) atoi(ttt[1]));
    uj.ido=(strtod(ttt[2], NULL));
    add(lista, &uj);
    }
}

char dkiir(Lista *lista)
{
    char s;
    printf("\n\n\n\n\n");
    printf("            Dicsoseglista\n");
    printf("\tJatekos nev\tElnyert penz:\tEltoltott ido:\n");

    dlista *mozgo = lista->elso->kov;
    while (mozgo != lista->utolso)
    {
    printf("\t%s\t", mozgo->adat.nev);
    printf("%uFt\t", mozgo->adat.eredmeny);
    printf("%0.fmp\n", mozgo->adat.ido);
    mozgo = mozgo->kov;
    }

    printf("               Kilepes:");
    scanf(" %c", &s);
    return s;

}

void fajlbair(Lista *lista)
{
    FILE* fp;
    fp=fopen("dlista.txt", "w");
    fprintf(fp, "Dicsoséglista\n");
    dlista *mozgo2 = lista->elso->kov;
    while (mozgo2 != lista->utolso) {
    fprintf(fp, "%s\t", mozgo2->adat.nev);
    fprintf(fp, "%u\t", mozgo2->adat.eredmeny);
    fprintf(fp, "%0.f\n", mozgo2->adat.ido);
    mozgo2 = mozgo2->kov;
    }
    fprintf(fp, "------------");
    fclose(fp);
}



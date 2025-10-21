#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "debugmalloc.h"
#include "fajltkezel.h"
#include "strukturak.h"

void nevbeo(jatekos *p1)
{
    char s[21];
    printf("\nAdd meg a játékos neved(max 20 karakter):");

    int ch; //Ez a ciklus addig olvas a bemenetrõl, amíg el nem éri az újsor karaktert vagy a bemenet végét
    while ((ch = getchar()) != '\n' && ch != EOF);

    fgets(s, 21, stdin);
    s[strcspn(s, "\n")] = 0;  // Eltávolítja az újsor karaktert, ha van.
    p1->nev = (char*)malloc((strlen(s)+1) * sizeof(char));
    strcpy(p1->nev, s);
    p1->felezo=true;
    p1->kozonseg=true;
}


void fajlbeo(int *pmeret, millio **t)
{
    char tt[5010][255];
    int i=0;
    FILE* fp;
    fp=fopen("millio.txt", "r");
    while(fgets(tt[i], 255, fp)!=NULL)
    {

        //printf("%s\n", tt[i]);
        i++;
    }
    fclose(fp);
    *pmeret=i;

    *t = (millio*)malloc((*pmeret-2) * sizeof(millio));
    if(*t==NULL) printf("Nem sikerult memoriat foglalni");
    char *ttt[8];
    for(i=1;i<*pmeret-1;i++)
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
    (*t)[i-1].nehezseg=(atoi(ttt[0]));

    (*t)[i-1].kerdes = (char*)malloc((strlen(ttt[1])+1) * sizeof(char));
    if((*t)[i-1].kerdes==NULL) printf("Nem sikerult memoriat foglalni");
    strcpy((*t)[i-1].kerdes, ttt[1]);

    (*t)[i-1].A = (char*)malloc((strlen(ttt[2])+1) * sizeof(char));
    if((*t)[i-1].A==NULL) printf("Nem sikerult memoriat foglalni");
    strcpy((*t)[i-1].A, ttt[2]);

    (*t)[i-1].B = (char*)malloc((strlen(ttt[3])+1) * sizeof(char));
    if((*t)[i-1].B==NULL) printf("Nem sikerult memoriat foglalni");
    strcpy((*t)[i-1].B, ttt[3]);

    (*t)[i-1].C = (char*)malloc((strlen(ttt[4])+1) * sizeof(char));
    if((*t)[i-1].C==NULL) printf("Nem sikerult memoriat foglalni");
    strcpy((*t)[i-1].C, ttt[4]);

    (*t)[i-1].D = (char*)malloc((strlen(ttt[5])+1) * sizeof(char));
    if((*t)[i-1].D==NULL) printf("Nem sikerult memoriat foglalni");
    strcpy((*t)[i-1].D, ttt[5]);

    (*t)[i-1].valasz=ttt[6][0];

    (*t)[i-1].kategoria = (char*)malloc((strlen(ttt[7])) * sizeof(char));
    if((*t)[i-1].kategoria==NULL) printf("Nem sikerult memoriat foglalni");
    memcpy((*t)[i-1].kategoria, ttt[7], (strlen(ttt[7])-1));
    (*t)[i-1].kategoria[strlen(ttt[7])-1]='\0';
    }
    *pmeret-=2;
}

void kiir(int *pmeret, millio **t)
{

    for(int i=0; i<*pmeret; i++)
    {
    printf("%d:\t", i);
    printf("%d\t", (*t)[i].nehezseg);
    printf("%s\t", (*t)[i].kerdes);
    printf("%s\t", (*t)[i].A);
    printf("%s\t", (*t)[i].B);
    printf("%s\t", (*t)[i].C);
    printf("%s\t", (*t)[i].D);
    printf("%c\t", (*t)[i].valasz);
    printf("%s\n", (*t)[i].kategoria);
    }
}

void felsz(int *pmeret, jatekos *p1, millio **t)
{
    for(int i=0;i<*pmeret;i++)
        {
            free((*t)[i].kerdes);
            free((*t)[i].A);
            free((*t)[i].B);
            free((*t)[i].C);
            free((*t)[i].D);
            free((*t)[i].kategoria);
        }
    free(*t);
    //free(p1->nev);
}



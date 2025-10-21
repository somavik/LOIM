#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "debugmalloc.h"
#include "tvs.h"
#include "strukturak.h"


int randkerdes(int *pmeret, millio **t, int i, int *volt)
{
        srand(time(0));
        int j, k, m=1;
        bool jo=false;
        if(i==1)
        {
        j=-1;
        while((*t)[j].nehezseg!=i)
            {
                j=(rand()%*pmeret-1+0);
            }
            volt[0]=j;
        }
        else
        do
        {
            j=-1;
            while((*t)[j].nehezseg!=i)
        {
            j=(rand()%*pmeret-1+0);
        }
        k=0;

        while(k<m && !(j==volt[k]))
        {
            k++;
        }
        if(k==m)
        {
            volt[k]=j;
            m++;
            jo=true;
        }
        }while(jo==false);
        return j;
}

int nrandkerdes(int *pmeret, millio **t, int i, int *volt, int *nehezseg)
{
        srand(time(0));
        int j, k, m=1;
        bool jo=false;
        if(i==1)
        {
        j=-1;
        while((*t)[j].nehezseg!=*nehezseg)
            {
                j=(rand()%*pmeret-1+0);
            }
            volt[0]=j;
        }
        else
        do
        {
            j=-1;
            while((*t)[j].nehezseg!=*nehezseg)
        {
            j=(rand()%*pmeret-1+0);
        }
        k=0;

        while(k<m && !(j==volt[k]))
        {
            k++;
        }
        if(k==m)
        {
            volt[k]=j;
            m++;
            jo=true;
        }
        }while(jo==false);
        return j;
}

void kerdesek(millio **t, int j, jatekos *p1)
{
        printf("\t\t\t\t\t\t\tKilépek(0)\n");
        printf("%d:%s",(*t)[j].nehezseg, (*t)[j].kerdes);
        printf("\tElérhetõ segítségek:");
        printf("\nA:%s\t\tB:%s", (*t)[j].A,  (*t)[j].B);
        if(p1->kozonseg)printf("\tközönség(1)");
        printf("\nC:%s\t\tD:%s", (*t)[j].C, (*t)[j].D);
        if(p1->felezo)printf("\tfelezõ(2)\n");
        printf("\nMelyik választ jelöli meg? ");
}

char felezo(millio **t, int j, jatekos *p1)
{
    srand(time(0));
    char fvalsz;
    p1->felezo=false;
    bool jo=false;
    int r;
    char fele[2];
    fele[0]=(*t)[j].valasz;
    while(!jo)
    {
        r=(rand()%4+1);
        if(r==1)    fele[1]='A';
        else if(r==2)    fele[1]='B';
        else if(r==3)    fele[1]='C';
        else        fele[1]='D';

        if(fele[0]!=fele[1]) jo=true;
    }
        printf("\t\t\t\t\t\t\tKilépek(0)\n");
        printf("%d:%s",(*t)[j].nehezseg, (*t)[j].kerdes);
        printf("\tElérhetõ segítségek:\n");
        if(fele[0]=='A'||fele[1]=='A')printf("A:%s\t", (*t)[j].A);
        if(fele[0]=='B'||fele[1]=='B')printf("\tB:%s", (*t)[j].B);
        if(p1->kozonseg)printf("\tközönség(1)");
        if(fele[0]=='C'||fele[1]=='C')printf("\nC:%s\t", (*t)[j].C);
        if(fele[0]=='D'||fele[1]=='D')printf("\tD:%s", (*t)[j].D);
        printf("\nMelyik választ jelöli meg?");
        fvalsz=valsztad();
        if(fvalsz!=fele[0] && fvalsz!=fele[1])
        {
            while(fvalsz!=fele[0] && fvalsz!=fele[1])
            {
            system("cls");
            printf("\nHibás bemenet!\t\t\t\t\tKilépek(0)\n");
            printf("%d:%s",(*t)[j].nehezseg, (*t)[j].kerdes);
            printf("\tElérhetõ segítségek:\n");
            if(fele[0]=='A'||fele[1]=='A')printf("A:%s\t", (*t)[j].A);
            if(fele[0]=='B'||fele[1]=='B')printf("\tB:%s", (*t)[j].B);
            if(p1->kozonseg)printf("\tközönség(1)");
            if(fele[0]=='C'||fele[1]=='C')printf("\nC:%s\t", (*t)[j].C);
            if(fele[0]=='D'||fele[1]=='D')printf("\tD:%s", (*t)[j].D);
            printf("\nMelyik választ jelöli meg?");
            fvalsz=valsztad();
            }
        }
        return fvalsz;
}

char kozonseg(millio **t, int j, jatekos *p1)
{
    srand(time(0));
    char fvalsz;
        typedef struct kozonseg
    {
        int n;
        char c;
    }kozonseg;
    kozonseg tnc[4];
    p1->kozonseg=false;
    char c[4]={'A', 'B', 'C', 'D'};
    char valasz=(*t)[j].valasz;
    bool jo=false;
    while(!jo)
    {
        tnc[0].n=rand()%20+50;
        tnc[1].n=rand()%(15)+(100-tnc[0].n-20);
        tnc[2].n=rand()%(5)+(100-tnc[0].n-tnc[1].n-5);
        tnc[3].n=(100-tnc[0].n-tnc[1].n-tnc[2].n);
        if(tnc[0].n+tnc[1].n+tnc[2].n+tnc[3].n==100) jo=true;
    }
        tnc[0].c=valasz;
        tnc[1].c=tnc[0].c;
        do
        {
            tnc[1].c=c[rand()%(4)+(0)];
        } while(tnc[1].c==tnc[0].c);

        tnc[2].c=tnc[1].c;
        do
        {
            tnc[2].c=c[rand()%(4)+(0)];
        } while(tnc[2].c==tnc[1].c || tnc[2].c==tnc[0].c);

        tnc[3].c=tnc[2].c;
         do
        {
            tnc[3].c=c[rand()%(4)+(0)];
        } while(tnc[3].c==tnc[2].c || tnc[3].c==tnc[1].c || tnc[3].c==tnc[0].c);
    for(char i='A';i<'E';i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(tnc[j].c==i)
            {
            printf("%c:  ", tnc[j].c);
            printf("%d%%  ", tnc[j].n);
            for (int k = 0; k < (tnc[j].n/10); k++)
            {
            printf("#");
            }
            }
        }
    printf("\n");
    }
    printf("\nMelyik választ jelöli meg?");
    fvalsz=valsztad();
    if(fvalsz!='A' && fvalsz!='B' && fvalsz!='C' && fvalsz!='D')
    {
        while(fvalsz!='A' && fvalsz!='B' && fvalsz!='C' && fvalsz!='D')
        {
            system("cls");
            printf("\nHibás bemenet!\t\t\t\t\tKilépek(0)\n");
            for(char i='A';i<'E';i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(tnc[j].c==i)
                    {
                    printf("%c:  ", tnc[j].c);
                    printf("%d%%  ", tnc[j].n);
                    for (int k = 0; k < (tnc[j].n/10); k++)
                    {
                    printf("#");
                    }
                    }
                }
                printf("\n");
            }
            printf("\nMelyik választ jelöli meg?");
            fvalsz=valsztad();
        }
    }
    return fvalsz;
}

char helyesvalasz(jatekos *p1, int i, unsigned int *nyeremeny, unsigned int *eredmenytemp)
{
    char folyt;
    printf("\nHelyes válasz!\n");
        if(((i)%5==0))
        {
        p1->eredmeny=nyeremeny[i-1];
        }
    *eredmenytemp=nyeremeny[i-1];
    printf("\nFolytatom(I)");
    printf("\nKiszállok(N)");
    printf("\n?");
    scanf(" %c", &folyt);
    folyt=toupper(folyt);
    if(folyt!='I' && folyt!='N')
    {
        while(folyt!='I' && folyt!='N')
        {
        system("cls");
        printf("\nHibás bemenet!(I vagy N)");
        printf("\nFolytatom(I)");
        printf("\nKiszállok(N)");
        printf("\n?");
        scanf(" %c", &folyt);
        folyt=toupper(folyt);
        }
    }
    return folyt;
}


bool rosszvalasz(millio **t, int j, jatekos *p1, time_t start, time_t *end, double *elteltido)
{
    char c;
    bool jatek;
    printf("\n\tHelytelen válasz!\n");
    printf("\tHelyes válasz a(z) %c volt.\n", (*t)[j].valasz);
    if(p1->eredmeny<=0)printf("\tÖn nem lesz milliomos!\n");
    else printf("\nNyereménye:%uFt", p1->eredmeny);

    *end=time(NULL);
    *elteltido=difftime(*end, start);
    p1->ido=*elteltido;
    printf("\nA Játékban eltöltött ideje: %.0f másodperc\nTovább:", *elteltido);
    if(scanf(" %c", &c)==1)
    {
    jatek=false;
    return jatek;
    }

}

bool hibasbemenet(int *jtemp, int j)
{
    bool h=true;
    printf("\nHibás bemenet");
    *jtemp=j;
    return h;
}

bool hibassegitseg(int *jtemp, int j)
{
    bool h=true;
    printf("\nNincs ilyen segítsége!");
    *jtemp=j;
    return h;
}

char valsztad()
{
        char valsz;
        scanf(" %c", &valsz);
        return toupper(valsz);
}

char elmentie()
{
    char s;
    printf("Elmenti adatait, hogy látszodjon a dicsoseglistán?");
    printf("\nIgen(I)");
    printf("\nNem(N)");
    printf("\n?");
    scanf(" %c", &s);
    s=toupper(s);
    if(s!='I' && s!='N')
    {
        while(s!='I' && s!='N')
        {
        system("cls");
        printf("\nHibás bemenet!(I vagy N)");
        printf("\nIgen(I)");
        printf("\nNem(N)");
        printf("\n?");
        scanf(" %c", &s);
        s=toupper(s);
        }
    }
    return s;
}

void tvs(int *pmeret, millio **t, jatekos *p1, bool *kilep, int *nehezseg)
{
    time_t start, end;
    double elteltido;

    unsigned int nyeremeny[15]={5000, 10000, 25000, 50000, 100000, 200000, 300000, 500000, 800000, 1500000, 3000000, 5000000, 10000000, 20000000, 40000000};
    unsigned int eredmenytemp=0;
    p1->eredmeny=0;

    int volt[15];
    int j, i=1;

    char valsz;
    char valsze;
    char folyt;
    char c;

    bool jatek=true;
    bool hbemenet=false;
    int jtemp;

    start = time(NULL);
    do
    {
    if(hbemenet)
        {
        j=jtemp;
        hbemenet=false;
        }
    else if(*nehezseg==0)
        {
        j=randkerdes(pmeret, t, i, volt);
        }
    else j=nrandkerdes(pmeret, t, i, volt, nehezseg);

    kerdesek(t, j, p1);
    valsz=valsztad();

    if(valsz!='A' && valsz!='B' && valsz!='C' && valsz!='D' && valsz!='0' && valsz!='1' && valsz!='2')
    {
        system("cls");
        hbemenet=hibasbemenet(&jtemp, j);
        continue;
    }
    else if (valsz == 'A' || valsz == 'B' || valsz == 'C' || valsz == 'D')  valsze = '3';
    else valsze=valsz;

        switch(valsze)
        {
        case'0':
            {
                *kilep=true;
                free(p1->nev);
                system("cls");
                jatek=false;
            }break;
        case'1':
            {
                system("cls");
                if(p1->kozonseg)
                {
                valsz=kozonseg(t, j,p1);
                    if(valsz==(*t)[j].valasz)
                    {
                    folyt=helyesvalasz(p1, i, nyeremeny, &eredmenytemp);
                    break;
                    }
                    else
                    {
                    jatek=rosszvalasz(t, j, p1, start, &end, &elteltido);
                    break;
                    }
                }
                else
                    {
                    hbemenet=hibassegitseg(&jtemp, j);
                    }continue;
            }continue;
        case'2':
            {
                system("cls");
                if(p1->felezo)
                {
                valsz=felezo(t, j,p1);
                    if(valsz==(*t)[j].valasz)
                    {
                    folyt=helyesvalasz(p1, i, nyeremeny, &eredmenytemp);
                    break;
                    }
                    else
                    {
                    jatek=rosszvalasz(t, j, p1, start, &end, &elteltido);
                    break;
                    }
                }
                else
                    {
                    hbemenet=hibassegitseg(&jtemp, j);
                    }continue;
            }break;
        case'3':
            {
                if(valsz==(*t)[j].valasz) folyt=helyesvalasz(p1, i, nyeremeny, &eredmenytemp);
                else
                {
                jatek=rosszvalasz(t, j, p1, start, &end, &elteltido);
                }
            }break;
        default:
            {
            system("cls");
            hbemenet=hibasbemenet(&jtemp, j);
            }continue;
        }
        switch(folyt)
            {
                case 'I':
                    {
                    system("cls");
                    i++;
                    }continue;
                case 'N':
                    {
                    system("cls");
                    printf("\nÖn kilépett a játékból");
                    p1->eredmeny=eredmenytemp;
                    printf("\nNyereménye:%u", eredmenytemp);
                    end=time(NULL);
                    elteltido=difftime(end, start);
                    p1->ido=elteltido;
                    printf("\nA Játékban eltöltött ideje: %.0f másodperc\nTovább:", elteltido);
                    if(scanf(" %c", &c)==1)
                        {
                        jatek=false;
                        }
                    }continue;
            }
    }while(i!=16 && jatek);
}

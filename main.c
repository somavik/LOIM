#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


#include "debugmalloc.h"
#include "fajltkezel.h"
#include "tvs.h"
#include "fomenu.h"
#include "strukturak.h"
#include"dlista.h"

#ifdef _WIN32
#include <windows.h>
#endif


int main()
{
#ifdef _WIN32
SetConsoleCP(1250);
SetConsoleOutputCP(1250);
#endif

srand((unsigned)time(NULL));

printf("\nNHF\n");

jatekos p1;
millio *t;
Lista lista;

    int meret=0;
    fajlbeo(&meret, &t);

    init(&lista);
    dfajlbeo(&lista);

    bool megy=true;
    bool kilep=false;
    char s;

    int nehezseg;

    while(megy)
    {
        system("cls");
        s=fomenu();
        if(isdigit(s)==0)
        {
        continue;
        }
        else
        {
        switch(s)
            {
            case '1':
                {
                system("cls");
                s=ujjatek();
                switch(s)
                    {
                    case '0':
                        {
                        system("cls");
                        nehezseg=0;
                        nevbeo(&p1);
                        tvs(&meret, &t, &p1, &kilep, &nehezseg);
                        if(kilep==false)
                            {
                            //system("cls");
                            s=elmentie();
                            if(s=='I')
                                {
                                add(&lista, &p1);
                                fajlbair(&lista);
                                break;
                                }
                            else break;
                            }
                        else
                        break;
                        }continue;
                    case '1':
                        {
                        system("cls");
                        nehezsegbeo(&nehezseg);
                        nevbeo(&p1);
                        tvs(&meret, &t, &p1, &kilep, &nehezseg);
                        if(kilep==false && nehezseg==15)
                            {
                            system("cls");
                            s=elmentie();
                            if(s=='I')
                                {
                                add(&lista, &p1);
                                fajlbair(&lista);
                                break;
                                }
                            else break;
                            }
                        else
                        break;
                        }continue;
                    }
                }continue;
            case '2':
                {
                system("cls");
                s=dkiir(&lista);
                }continue;
            case '3':
                {
                system("cls");
                printf("\nKilépés...");
                megy=false;
                }break;
            default:
                {
                system("cls");
                }continue;
            }
        }
    }
    //kiir(&meret, &t);
    printf("\n\n");
    felsz(&meret, &p1, &t);
    dfelsz(&lista);
    return 0;
}


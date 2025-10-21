#ifndef STRUKTURAK_H_INCLUDED
#define STRUKTURAK_H_INCLUDED

typedef struct jatekos
{
    char *nev;
    unsigned int eredmeny;
    bool kozonseg;
    bool felezo;
    double ido;
}jatekos;

typedef struct millio
{
    int nehezseg;
    char *kerdes;
    char *A;
    char *B;
    char *C;
    char *D;
    char valasz;
    char *kategoria;
}millio;

typedef struct dlista
{
    jatekos adat;
    struct dlista *elozo, *kov;
}dlista;

typedef struct Lista {
    dlista *elso;
    dlista *utolso;
} Lista;

#endif // STRUKTURAK_H_INCLUDED

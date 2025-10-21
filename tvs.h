 #ifndef TVS_H_INCLUDED
#define TVS_H_INCLUDED
#include "fajltkezel.h"

int randkerdes(int *pmeret, millio  **t, int i, int *volt);

int nrandkerdes(int *pmeret, millio **t, int i, int *volt, int *nehezseg);

void kerdesek(millio **t, int j, jatekos *p1);

char felezo(millio **t, int j, jatekos *p1);

char kozonseg(millio **t, int j, jatekos *p1);

char valsztad();

char elmentie();

char helyesvalasz(jatekos *p1, int i, unsigned int *nyeremeny, unsigned int *eredmenytemp);

bool rosszvalasz(millio **t, int j, jatekos *p1, time_t start, time_t *end, double *elteltido);

bool hibasbemenet(int *jtemp, int j);

bool hibassegitseg(int *jtemp, int j);

void tvs(int *pmeret, millio **t, jatekos *p1, bool *kilep, int *nehezseg);


#endif // TVS_H_INCLUDED

#include <stdio.h>
#include <string.h>

/*structura colorat memoreaza prin cele doua campuri pentru fiecare element din card
valoarea, respectiv daca elementul este colorat*/
typedef struct{
    int valoare, clr;
}colorat;

//functie care coloreaza elementul cu indicii dati ca parametri din cardul de tip colorat
void coloreaza(colorat a[5][5], int i, int j, int val)
{
    if (a[i][j].valoare== val)
        a[i][j].clr = 1;
}

//functie care face interschimbarea coloanelor x si y din card conform comenzii swap din cerinta
void swap(colorat a[5][5], int x, int y)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        colorat aux = a[i][x];
        a[i][x] = a[i][y];
        a[i][y] = aux;
    }  
}

//functie care face shiftarea coloanei x din card cu y pozitii conform comenzii shift din cerinta
void shift(colorat a[5][5], int x, int y)
{
    //o coloana din card avand 5 elemente este suficient sa shiftam cu restul impartirii numarului de pozitii la 5
    if (y > 4)
        y %= 5;
    int i;
    //prima oara inversam elementele din coloana
    for (i = 0; i < 2; i++)
    {
        colorat aux = a[i][x];
        a[i][x] = a[4-i][x];
        a[4-i][x] = aux;
    }
    //mai apoi inversam doar primele y elemente
    for (i = 0; i < y / 2; i++)
    {
        colorat aux = a[i][x];
        a[i][x] = a[y-1-i][x];
        a[y-1-i][x] = aux;
    }
    //iar la final inversam ultimele 5-y elemente
    for (i = 0; i < (5 - y) / 2; i++)
    {
        colorat aux = a[y+i][x];
        a[y+i][x] = a[4-i][x];
        a[4-i][x] = aux;
    }
}

//functie care sorteaza crescator prin selectie elementele de pe coloana x
void asc(colorat a[5][5], int x)
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (a[i][x].valoare > a[j][x].valoare)
            {
                colorat aux = a[i][x];
                a[i][x] = a[j][x];
                a[j][x] = aux;
            }
}

//functie care sorteaza descrescator prin selectie elementele de pe coloana x
void dsc(colorat a[5][5], int x)
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (a[i][x].valoare < a[j][x].valoare)
            {
                colorat aux = a[i][x];
                a[i][x] = a[j][x];
                a[j][x] = aux;
            }
}

//functie care afiseaza cardul
void show(colorat a[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            if (a[i][j].clr == 1)
            //elementul este colorat deci afisam #
                printf("# ");
            else
            //elementul nu este colorat deci ii afisam valoarea
                printf("%d ", a[i][j].valoare);
        printf("\n");
    }
}

//functie care verifica prin numararea combinatiilor castigatoare de pe card daca sunt castigatori
int winner(colorat a[5][5])
{
    //nr contorizeaza combinatiile castigatoare
    int i, j, ok = 1, nr = 0;
    //se numara liniile castigatoare
    for (i = 0; i < 5; i++)
    {
        ok = 1;
        for (j = 0; j < 5; j++)
            if (a[i][j].clr == 0)
                ok = 0;
        if (ok)
            nr++;
    }
    //se numara coloanele castigatoare
    ok = 1;
    for (j = 0; j < 5; j++)
    {
        ok = 1;
        for (i = 0; i < 5; i++)
            if (a[i][j].clr == 0)
                ok = 0;
        if (ok)
            nr++;
    }
    //se verifica daca diagonala principala este castigatoare
    ok = 1;
    for (i = 0; i < 5; i++)
        if (a[i][i].clr == 0)
            ok = 0;
    if (ok)
        nr++;
    //se verifica daca diagonala secundara este castigatoare
    ok = 1;
    for (i = 0; i < 5; i++)
        if (a[i][4-i].clr == 0)
            ok = 0;
    if (ok)
        nr++;
    //se returneaza numarul de combinatii castigatoare
    return nr;
}

int main()
{
    //se citeste numarul de carduri ce urmeaza a fi citite
    int n;
    scanf("%d", &n);
    //a reprezinta vectorul de carduri cu n elemente de tip colorat
    colorat a[100][5][5];
    int k, i, j, ind;
    for (k = 0; k < n; k++)
    {
        //citim cardul curent
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                scanf("%d", &a[k][i][j].valoare);
                a[k][i][j].clr = 0;
            }
        }
        //coloram elementul din centru
        a[k][2][2].clr = 1;
    }
    //citim numarul de comenzi date
    int nr;
    scanf("%d", &nr);
    int pmax = 0, kmin;
    for (ind = 0; ind < nr; ind++)
    {
        //sirul s reprezinta comanda citita, iar mai apoi se face identificarea ei
        char s[100];
        scanf("%s", s);
        //s este o comanda standard de extragere a unei bile
        if (s[1] == '-')
        {
            int poz, val = 0, len = strlen(s);
            //formam numarul corespunzator bilei extrase in variabila int val
            for (poz = 2; poz < len; poz++)
                val = val * 10 + (s[poz] - '0');
            //cautam bila in carduri si coloram daca este cazul
            for (k = 0; k < n; k++)
                for (i = 0; i < 5; i++)
                    for (j = 0; j < 5; j++)
                        coloreaza(a[k], i, j, val);
        }
        //s reprezinta una dintre cerintele implementate in functiile anterioare
        else
        {
            //identificam comanda ceruta
            if (strstr(s, "SHIFT"))
            {
                //extragem numerele x si y din stringul citit
                int x = s[6] - '0', poz, y = 0, len = strlen(s);
                for (poz = 8; poz < len; poz++)
                    y = y * 10 + (s[poz] - '0');
                //apelam functia shift
                for (i = 0; i < n; i++)
                    shift(a[i], x, y);
            }
            if (strstr(s, "SWAP"))
            {
                //extragem numerele x si y din stringul citit
                int x = s[5] - '0', y = s[7] - '0';
                //apelam functia swap
                for (i = 0; i < n; i++)
                    swap(a[i], x, y);
            }
            if (strstr(s, "ASC"))
            {
                //extragem numarul x din stringul citit
                int x = s[4] - '0';
                //apelam functia asc
                for (i = 0; i < n; i++)
                    asc(a[i], x);
            }
            if (strstr(s, "DSC"))
            {
                //extragem numarul x din stringul citit
                int x = s[4] - '0';
                //apelam functia dsc
                for (i = 0; i < n; i++)
                    dsc(a[i], x);
            }
            if (strstr(s, "SHOW"))
            {
                //extragem indicele cardului ce trebuie afisat
                int poz, ind = 0, len = strlen(s);
                for (poz = 5; poz < len; poz++)
                    ind = ind * 10 + (s[poz] - '0');
                //afisam cardul
                show(a[ind]);
            }
        }
        /*stabilim castigatorul;
        daca exista mai multi jucatori cu acelasi nr de puncte il retinem pe primul dintre ei*/
        for (k = 0; k < n; k++)
            if (winner(a[k]) > pmax)
            {
                pmax = winner(a[k]);
                kmin = k;
            }
        //daca exista afisam castigatorul si numarul sau de puncte si oprim programul
        if (pmax)
        {
            printf("%d\n", kmin);
            show(a[kmin]);
            printf("%d\n", 10 * pmax);
            return 0;
        }
    }
    //nu exista castigatori
    printf("NO WINNER\n");
    return 0;
}

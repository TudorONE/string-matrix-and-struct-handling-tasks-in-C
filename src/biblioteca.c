#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//definim structura asa cum este specificat in cerinta
typedef struct{
    int ID;
    char titlu[50];
    char autor[30];
    int an_ap;
    char *descriere;
}carte;

//functie pentru afisarea unei carti
void afisare(carte c)
{
    printf("%d\n", c.ID);
    printf("%s\n%s\n", c.titlu, c.autor);
    printf("%d\n", c.an_ap);
    printf("%s", c.descriere);
}
/*functie care face cautarea conform comenzii search din cerinta
functia are ca parametri vectorul de carti citit, *c, numarul de carti din vector, n,
respectiv sirul cautat, *arg*/
void search(carte *c, int n, char *arg)
{
    /*prin id memoram id-ul cartilor care corespund cautarii cautarii
    ca mai apoi sa le sortam si afisam in ordinea crescatoare a acestuia*/
    int len = strlen(arg), id[100], cnt = 0;
    /*prin ok stabilim daca facem cautarea dupa anul aparitiei (cazul ok = 1)
    sau dupa titlu sau autor in caz contrar*/ 
    int i, ok = 0;
    //daca primul caracter al sirului este o cifra atunci cautam dupa anul aparitiei
    if ('0' <= arg[0] && arg[0] <= '9')
        ok = 1;
    if (ok)
    {
        int val = 0;
        //formam anul aparitiei in variabila int val
        for (i = 0; i < len; i++)
            val = val * 10 + (arg[i] - '0');
        //adaugam id-ul cartilor corespunzatoare in vectorul id
        for (i = 0; i < n; i++)
            if (c[i].an_ap == val)
                id[cnt++] = c[i].ID;
    }
    //cazul in care nu cautam dupa an
    else
        for (i = 0; i < n; i++)
        /*comparam case-insensitive folosind functia strcasecmp autorul si titlul cu stringul dat ca parametru 
        si actualizam daca este cazul id*/
            if (!strcasecmp(c[i].autor, arg) || !strcasecmp(c[i].titlu, arg))
                id[cnt++] = c[i].ID;
    //daca id are numar de elemente nenul implicit exista elemente de afisat
    if (cnt) 
    {
        int j;
        //facem sortare crescatoare prin selectie dupa id
        for (i = 0; i < cnt - 1; i++)
            for (j = i + 1; j < cnt; j++)
                if (id[i] > id[j])
                {
                    int aux = id[i];
                    id[i] = id[j];
                    id[j] = aux;
                }
        //afisam in ordine cartile
        for (i = 0; i < cnt; i++)
            for (j = 0; j < n; j++)
                if (id[i] == c[j].ID)
                {
                    afisare(c[j]);
                    printf("\n");
                }
    }
    //id nu are elemente deci afisam NOT FOUND
    else
        printf("NOT FOUND\n\n");
}

/*functie care face inlocuirea conform comenzii replace din cerinta
functia are ca parametri vectorul de carti citit, *c, numarul de carti din vector, n,
cuvantul cautat in descriere, word1, si cel cu care trebuie inlocuit, word2*/
void replace(carte *c, int n, char *word1, char *word2)
{
    int i;
    //il cautam pe word1 in descriere separand sirul in cuvinte prin strtok
    for (i = 0; i < n; i++)
    {
        char *p = strtok(c[i].descriere, " \n");
        /*in sirul descmod se va memora descrierea modificata,
        continutul sau urmand a fi copiat in descrierea cartii*/
        char descmod[1000];
        descmod[0] = '\0';
        while (p)
        {
            //il gasim pe word1 si il adaugam pe word2 la descmod
            if (!strcmp(word1, p))
                strcat(descmod, word2);
            else
            //altfel adaugam cuvantul curent la descmod
                strcat(descmod, p);
            strcat(descmod, " ");
            p = strtok(NULL, " \n");
        }
        //realocam dinamic dimensiunea noii descrieri
        c[i].descriere = realloc(c[i].descriere, (strlen(descmod) + 2) * sizeof(char));
        //stergem enterul de la finalul lui descmod si il adaugam la final descrierii
        descmod[strlen(descmod) - 1] = '\0';
        //actualizam descrierea cartii prin copierea continutului lui descmod
        strcpy(c[i].descriere, descmod);
        strcat(c[i].descriere, "\n");
    }
}

/*functie care face codificarea conform comenzii encode din cerinta
functia are ca parametru o carte c din vectorul citit*/
void encode(carte *c)
{
    int i, len = strlen(c->descriere), cnt = 1, j = 0;
    /*in sirul descmod se va memora codificarea descrierii,
    care nu poate avea lungimea mai mare decat dublul descrierii initiale*/
    char *descmod = (char*)malloc((2 * len + 1) * sizeof(char));
    for (i = 0; i < len - 1; i++)
    {
        //tratam cazul in care caracterul curent e litera
        if (('A' <= c->descriere[i] && c->descriere[i] <= 'Z') || ('a' <= c->descriere[i] && c->descriere[i] <= 'z'))
        {
            //contorizam numarul de caractere consecutive egale si incrementam indicele de deplasare in descriere
            while (c->descriere[i] == c->descriere[i+1])
            {
                cnt++;
                i++;
            }
            //adaugam caracterul curent la descmod si incrementam indicele de deplasare in acesta
            descmod[j++] = c->descriere[i];
            /*in variabila cnthexa se memoreaza conversia contorului in hexazecimal,
            realizata prin functia sprintf*/
            char cnthexa[3];
            cnthexa[0] = '\0';
            sprintf(cnthexa, "%X", cnt);
            //il adaugam pe cnthexa la descmod caracter cu caracter
            int lhd = strlen(cnthexa);
            int k;
            for (k = 0; k < lhd; k++)
                descmod[j++] = cnthexa[k];
            //resetam contorul
            cnt = 1;
        }
        else
        //daca nu este litera adaugam caracterul neschimbat
            descmod[j++] = c->descriere[i];
    }
    //inversam sirul conform cerintei
    for (i = 0; i < j / 2; i++)
    {
        char aux = descmod[i];
        descmod[i] = descmod[j-i-1];
        descmod[j-i-1] = aux;
    }
    //realocam dinamic dimensiunea noii descrieri
    c->descriere = realloc(c->descriere, (strlen(descmod) + 2) * sizeof(char));
    //adaugam terminatorul NULL lui descmod
    descmod[j] = '\0';
    //actualizam descrierea cartii prin copierea continutului lui descmod
    strcpy(c->descriere, descmod);
    //adaugam enter la finalul noii descrieri
    strcat(c->descriere, "\n");
    //eliberam memoria consumata de descmod
    free(descmod);
}

//functie care adauga o noua carte, book, la vectorul c
void add_book(carte **c, int *n, carte book)
{
    //incrementam numarul de elemente al vectorului
    (*n)++;
    //adaugam memorie pentru noua carte in vector
    *c = realloc(*c, *n * sizeof(carte));
    //alocam dinamic memoria necesara descrierii cartii book
    (*c)[*n-1].descriere = (char*)malloc((strlen(book.descriere) + 2) * sizeof(char));
    //ultimul element din vector este book
    (*c)[*n-1] = book;
}

int main()
{
    //citim numarul de carti care urmeaza a fi citite
    int n;
    scanf("%d", &n);
    //alocam memorie vectorului c
    carte *c = (carte*)malloc(n * sizeof(carte));
    int i;
    for (i = 0; i < n; i++)
    {
        /*citim campurile unei carti
        titlul si autorul se citesc pana la aparitia unui enter*/
        scanf("%d\n%[^\n]\n%[^\n]\n%d\n", &c[i].ID, c[i].titlu, c[i].autor, &c[i].an_ap);
        //in aux memoram si citim desccrierea pentru a sti cata memorie sa ii alocam campului descriere
        char aux[501];
        fgets(aux, 500, stdin);
        //alocam memoria necesara descrierii si copiem in camp continutul lui aux
        c[i].descriere = (char*)malloc((strlen(aux) + 1) * sizeof(char));
        strcpy(c[i].descriere, aux);
    }
    //citim numarul de comenzi date
    int nr;
    scanf("%d", &nr);
    for (i = 0; i < nr; i++)
    {
        //sirul s reprezinta denumirea comenzii citite, iar mai apoi se face identificarea ei
        char s[100];
        scanf("%s", s);
        if (strstr(s, "SEARCH"))
        {
            char str[50];
            //consumam spatiul ramas in buffer
            getchar();
            //citim pana la enter stringul ce urmeaza a fi parametru in functia corespunzatoare
            scanf("%[^\n]", str);
            //apelam functia
            search(c, n, str);
        }
        if (strstr(s, "REPLACE"))
        {
            char str1[50], str2[100];
            //citim cuvintele ce urmeaza a fi date ca parametri in functie
            scanf("%s %s", str1, str2);
            //apelam functia
            replace(c, n, str1, str2);
        }
        if (strstr(s, "ENCODE"))
        {
            int x;
            //citim id-ul cartii ce trebuie codificate
            scanf("%d", &x);
            int j;
            //cautam cartea si o codificam
            for (j = 0; j < n; j++)
                if (c[j].ID == x)
                    encode(&c[j]);
        }
        if (strstr(s, "ADD_BOOK"))
        {
            carte book;
            //citim similar celorlalte elemente campurile noii carti
            scanf("%d\n%[^\n]\n%[^\n]\n%d\n", &book.ID, book.titlu, book.autor, &book.an_ap);
            char aux[501];
            fgets(aux, 500, stdin);
            book.descriere = (char*)malloc((strlen(aux) + 1) * sizeof(char));
            strcpy(book.descriere, aux);
            //adaugam cartea
            add_book(&c, &n, book);
        }
    }
    //afisam numarul de carti si fiecare carte in parte
    printf("%d\n", n);
    for (i = 0; i < n; i++)
        afisare(c[i]);
    //eliberam memoria consumata de vectorul de carti
    for (i = 0; i < n; i++)
        free(c[i].descriere);
    free(c);
}
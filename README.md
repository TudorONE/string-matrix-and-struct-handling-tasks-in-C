# string-matrix-and-struct-handling-tasks-in-C
2 problems of handling strings/matrices using C structures


Problema 1

1.1 Descriere

Bingo este un joc de noroc popular care implica extragerea aleatorie a unor numere si marcarea acestora pe carduri speciale.
Fiecare card contine 25 de numere, asezate sub forma unei matrici cu 5 linii si 5 coloane.

Fiecare coloana este etichetata cu o litera si contine un interval de numere restrictionat dupa cum urmeaza:

coloana 1 – B (contine doar numere naturale din intervalul [1, 15])

coloana 2 – I (contine doar numere naturale din intervalul [16, 30])

coloana 3 – N (contine doar numere naturale din intervalul [31, 45])

coloana 4 – G (contine doar numere naturale din intervalul [46, 60])

coloana 6 – O (contine doar numere naturale din intervalul [61, 75])

Organizatorul extrage, pe rand, cate o bila.
Fiecare bila contine o litera specifica unei coloane de pe card si un numar corespunzator.
Toti jucatorii care au pe card numarul extras, la coloana indicata, vor colora, pe card, celula respectiva.

Fiecare linie, coloana sau diagonala colorata complet valoreaza cate 10 puncte.
De asemenea, organizatorul va extrage un anumit numar de bile, ceea ce inseamna ca nu intotdeauna vom avea un castigator.

Jocul este castigat daca un jucator reuseste sa coloreze toate celulele de pe o linie, de pe o coloana sau de pe o diagonala.
Pentru a oferi un ajutor jucatorului, dupa primirea cardului, acesta trebuie sa inlocuiasca numarul din centrul cardului cu simbolul # (coloreaza elementul din mijloc).
Jocul se opreste cand un jucator a atins o combinatie si a strigat „BINGO”.

Noi vom face jocul putin mai interesant. La un moment dat, in timpul jocului, organizatorul poate extrage bile mai speciale:

o bila de tip SWAP-X-Y are ca efect interschimbarea coloanelor X si Y, unde X si Y vor fi numere ce reprezinta coloanele.

o bila de tip SHIFT-X-Y va produce mutarea ciclica in jos a numerelor de pe coloana X cu Y pozitii in jos, pe aceeasi coloana (unde X si Y vor fi numere).

o bila de tip ASC-X va ordona crescator numerele de pe coloana X (unde X este un numar ce reprezinta indexul coloanei).

o bila de tip DSC-Y va ordona descrescator numerele de pe coloana Y (unde Y este un numar ce reprezinta indexul coloanei).

o bila de tip SHOW-I va forta jucatorul I sa isi afiseze cardul (unde I este un numar).

Multe persoane s-au inscris la jocul nostru si, pentru a valida cardurile castigatoare, avem nevoie de ajutorul vostru.
Veti primi N carduri pe care dorim sa le verificati. Cardurile se afla in starea initiala, inainte de inceperea jocului.

1.2 Cerinte

Voi trebuie sa implementati un program care sa realizeze urmatoarele:

1. Citirea cardurilor de joc

Pentru a intelege formatul in care vor fi furnizate aceste carduri, analizati sectiunea 1.4.

Important:
Dupa ce a fost citit un card, coloram elementul aflat in mijlocul fiecarei matrici.

Vom considera ca fiecare card va avea asociat un ID egal cu pozitia sa in input.
Consideram indexarea cardurilor de la 0.

Observatie:
Pentru a putea stoca toate cardurile de joc, puteti folosi un tablou tridimensional.

Exemplu:

int carduri[10][5][5];


In acest caz, carduri poate fi privit drept un vector cu 10 elemente de tip matrice 5×5.

carduri[0] o sa fie matricea in care stocam numerele existente in cardul jucatorului cu ID-ul 0.

carduri[1][2][3] o sa fie numarul din cardul jucatorului 1 aflat pe linia 2 si coloana 3.

💡 Hint: Puteti utiliza un tablou suplimentar in care sa marcati celulele colorate.

2. Implementarea unei functii pentru fiecare tip de operatie

(a) o functie care interschimba coloanele dintr-un card;
(b) o functie care produce o mutare ciclica pe coloana X a cardului;
(c) o functie care sorteaza crescator numerele de pe coloana X;
(d) o functie care sorteaza descrescator numerele de pe coloana Y;
(e) o functie care coloreaza o anumita celula de pe card daca aceasta contine valoarea indicata;
(f) o functie care afiseaza continutul unui card;
(g) o functie care verifica daca un card contine o combinatie finala (contine cel putin o linie, coloana sau diagonala colorata complet).

Important:
Puteti alege ce antet doriti pentru aceste functii si puteti adauga functii suplimentare daca veti considera necesar, dar este obligatoriu sa aveti definita cel putin o functie pentru fiecare operatie.

3. Citirea si aplicarea comenzilor una cate una

Pentru a intelege formatul in care vor fi furnizate aceste comenzi, analizati sectiunea 1.4.

Important:
Daca dupa aplicarea unei comenzi va exista un card ce contine o combinatie finala:

vom afisa indicele cardului castigator;

vom afisa cardul castigator (celulele colorate vor fi marcate cu #);

vom afisa numarul de puncte acumulate;

vom termina executia programului, ignorand restul comenzilor.

Daca dupa aplicarea unei comenzi vom gasi mai multe carduri castigatoare:

il vom desemna castigator pe cel ce colecteaza mai multe puncte.

In cazul in care exista mai multe carduri ce au acelasi punctaj maxim, alegem cardul cu ID-ul minim.

Daca dupa aplicarea tuturor comenzilor niciun card nu a iesit castigator:

vom afisa mesajul NO WINNER.

1.3 Restrictii si precizari

Vor exista doua tipuri de teste:

Teste cu un singur card.

Teste cu mai multe carduri.

Observatie:
In cazul in care doriti sa rezolvati problema doar pentru cazul cu un singur card, atunci acest lucru este posibil si puteti primi punctaj doar pentru prima categorie de teste (cele cu un singur card).

Vor exista teste simple care vor verifica individual fiecare tip de bila.
Astfel, puteti obtine punctaj partial daca alegeti sa implementati doar o parte din functionalitati.

1.4 Date de intrare

Prima linie contine N, numarul de carduri.

Urmeaza N matrici de dimensiune 5×5. Fiecare matrice contine numere de la 1 la 75, asa cum am descris mai sus.

Dupa fiecare matrice este o linie goala.

Pe urmatoarea linie este numarul de bile care vor fi extrase de organizator, M.

Urmeaza M linii, fiecare continand un text de forma COLOANA-NUMAR sau SPECIAL (bile speciale, asa cum am descris mai sus).

1.5 Date de iesire

Pentru fiecare bila de tip SHOW, vom afisa cardul corespunzator jucatorului specificat.
Celule colorate vor fi marcate cu # in output.

Daca exista un castigator:

vom afisa pe o linie noua indicele cardului castigator;

pe urmatoarele linii vom afisa cardul castigatorului;

pe ultima linie vom afisa punctajul castigatorului.

Daca niciun card nu a iesit castigator, se va afisa pe o linie noua textul:

NO WINNER



Problema 2

2.1 Descriere

O biblioteca are probleme cu gestionarea cartilor si managerul a decis sa va ceara ajutorul pentru a implementa un sistem de gestiune care sa permita gasirea celor mai potrivite carti.
O carte contine urmatoarele detalii:

ID carte – un numar natural;

titlul cartii – sir de maximum 40 caractere;

autorul cartii – sir de maximum 20 caractere;

anul aparitiei – un numar natural;

descrierea – un text pentru care trebuie sa alocati dinamic exact cat este nevoie.

Observatie
Vom considera ca descrierea unei carti este un text ce contine un numar de maximum 500 de caractere care se termina cu newline (\n).
Pentru eficienta in implementare, veti folosi alocare dinamica si veti aloca doar cat aveti nevoie.

Important
In implementare trebuie sa folositi o structura pentru retinerea informatiilor aferente unei carti.
Pentru a retine toate cartile din biblioteca, vom folosi un vector de structuri ce este alocat dinamic si realocat atunci cand este cazul.

2.2 Cerinte

Bibliotecarii au nevoie de un program care sa ii ajute sa tina evidenta cartilor. Astfel, va trebui sa ii ajutati prin implementarea unui program care sa realizeze urmatoarele:

Citirea cartilor care exista in biblioteca. Pentru a intelege formatul in care vor fi furnizate aceste carti, analizati sectiunea 2.3.

Implementarea unei functii pentru fiecare dintre urmatoarele comenzi:

Comanda SEARCH <ELEMENT>, unde <ELEMENT> poate fi un numar sau un sir de caractere.

Daca argumentul comenzii SEARCH este un numar, atunci va trebui sa gasim si sa afisam toate cartile ce au anul aparitiei egal cu acel numar.

Daca argumentul comenzii SEARCH este un sir de caractere, atunci va trebui sa gasim si sa afisam toate cartile pentru care sirul de caractere furnizat reprezinta titlul cartii sau autorul cartii.

Important
Operatia de cautare este case-insensitive, iar daca avem mai multe carti ce indeplinesc conditiile cautarii, va trebui sa le afisam in ordinea crescatoare a ID-ului.

Comanda REPLACE <WORD1> <WORD2>, unde <WORD1> si <WORD2> pot fi siruri de caractere.
Aceasta comanda va cauta in toate descrierile cartilor cuvantul <WORD1> si ii va inlocui toate aparitiile cu <WORD2>.

Important
Este garantat ca <WORD1> si <WORD2> nu vor contine spatii.

Comanda ENCODE <ID>, unde <ID> este un numar natural reprezentand ID-ul unei carti.
Aceasta comanda va codifica descrierea cartii prin aplicarea urmatorului algoritm:

Presupunem ca descrierea este un sir de caractere S ce contine N caractere. Pentru fiecare cuvant din acest sir de caractere, aplicam urmatoarele operatii:

se inlocuieste fiecare subsir de caractere identice cu acest caracter urmat de numarul de aparitii;

numarul de aparitii este convertit din baza 10 in baza 16;

sirul obtinut este inversat si afisat drept output la iesirea standard.

Important
Semnele de punctuatie din descriere vor fi ignorate. Consideram cuvintele drept siruri de caractere ce contin doar litere din alfabetul englez despartite prin spatiu. Daca apar cifre in descriere acestea vor fi ignorate in codificare.
Daca nu exista o carte cu ID-ul furnizat, atunci ignoram comanda ENCODE.

Comanda ADD_BOOK care o sa fie urmata de 5 linii ce vor contine urmatoarele:

ID carte

titlul cartii

autorul cartii

anul aparitiei

descrierea

Important
Adaugarea se va face la finalul vectorului de carti. Daca nu mai aveti suficient spatiu in vectorul de carti pentru noua carte atunci il veti realoca dinamic.

Citirea si aplicarea de diverse comenzi furnizate ca intrare de la tastatura. Pentru a intelege formatul in care vor fi furnizate aceste comenzi, analizati sectiunea 2.3.

Printarea informatiilor despre cartile din biblioteca obtinute dupa aplicarea comenzilor anterioare. Consultati sectiunea 2.4 pentru a intelege formatul in care va trebui sa le afisati.

2.3 Date de intrare

Prima linie contine N, numarul de carti din biblioteca.

Pentru fiecare din cele N carti vor exista cate 5 linii:

o linie ce contine un numar natural ce reprezinta ID-ul cartii;

o linie ce contine un sir de maximum 20 de caractere ce reprezinta titlul cartii;

o linie ce contine un sir de maximum 20 de caractere ce reprezinta autorul cartii;

o linie ce contine un numar natural ce reprezinta anul de aparitie;

o linie ce contine un sir de maximum 500 de caractere ce reprezinta descrierea cartii.

Dupa cele N × 5 linii ce contin informatiile despre carti, urmeaza o linie pe care se afla un numar natural M ce reprezinta numarul total de comenzi pe care le veti avea de executat.

In continuare, vor fi furnizate comenzile (fiecare comanda incepe pe o linie noua).

2.4 Date de iesire

Pentru fiecare comanda de tip SEARCH vom afisa toate cartile care indeplinesc conditiile de cautare. O carte o sa fie afisata folosind acelasi format utilizat la citire.

Daca pentru o comanda de tip SEARCH nu exista un rezultat, vom afisa mesajul NOT FOUND.

Dupa fiecare afisare produsa de o comanda de tip SEARCH se va afisa un rand liber.

Dupa ce am executat toate comenzile, vom afisa pe un rand nou numarul total de carti din biblioteca, dupa care pentru fiecare carte vom afisa urmatoarele:

o linie ce contine un numar natural ce reprezinta ID-ul cartii;

o linie ce contine un sir de maximum 20 de caractere ce reprezinta titlul cartii;

o linie ce contine un sir de maximum 20 de caractere ce reprezinta autorul cartii;

o linie ce contine un numar natural ce reprezinta anul de aparitie;

o linie ce contine un sir de maximum 500 de caractere ce reprezinta descrierea cartii.

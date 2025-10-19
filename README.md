# string-matrix-and-struct-handling-tasks-in-C
2 problems of handling strings/matrices using C structures

## Problema 1

### 1.1 Descriere

Bingo este un joc de noroc popular care implica extragerea aleatorie a unor numere si marcarea acestora pe carduri speciale.  
Fiecare card contine 25 de numere, asezate sub forma unei matrici cu 5 linii si 5 coloane.

Fiecare coloana este etichetata cu o litera si contine un interval de numere restrictionat dupa cum urmeaza:

- Coloana 1 – B (numere naturale [1,15])
- Coloana 2 – I (numere naturale [16,30])
- Coloana 3 – N (numere naturale [31,45])
- Coloana 4 – G (numere naturale [46,60])
- Coloana 6 – O (numere naturale [61,75])

Organizatorul extrage, pe rand, cate o bila.  
Fiecare bila contine o litera specifica unei coloane de pe card si un numar corespunzator.  
Toti jucatorii care au pe card numarul extras, la coloana indicata, vor colora celula respectiva.

- Fiecare linie, coloana sau diagonala colorata complet valoreaza cate 10 puncte.  
- Organizatorul va extrage un anumit numar de bile, deci nu intotdeauna vom avea un castigator.  

Jocul este castigat daca un jucator reuseste sa coloreze toate celulele de pe o linie, coloana sau diagonala.  
- Pentru a ajuta jucatorul, numarul din centrul cardului se inlocuieste cu simbolul `#`.  
- Jocul se opreste cand un jucator striga „BINGO”.

#### Bile speciale:

- `SWAP-X-Y` → interschimbarea coloanelor X si Y
- `SHIFT-X-Y` → mutarea ciclica in jos a numerelor pe coloana X cu Y pozitii
- `ASC-X` → ordonarea crescatoare a numerelor de pe coloana X
- `DSC-Y` → ordonarea descrescatoare a numerelor de pe coloana Y
- `SHOW-I` → afisarea cardului jucatorului I

Veti primi N carduri in starea initiala, inainte de inceperea jocului.

### 1.2 Cerinte

1. **Citirea cardurilor de joc**  
   - Dupa citire, se coloreaza elementul din mijlocul fiecarei matrici (`#`).  
   - Fiecare card va avea un ID egal cu pozitia sa in input (indexare de la 0).  
   - Se poate folosi un tablou tridimensional:  
     ```c
     int carduri[10][5][5];
     ```
     - `carduri[0]` → matricea jucatorului 0  
     - `carduri[1][2][3]` → elementul linia 2, coloana 3, jucator 1

   💡 Hint: Se poate folosi un tablou suplimentar pentru celulele colorate.

2. **Functii pentru fiecare tip de operatie**
   - Interchange coloane
   - Mutare ciclica pe coloana X
   - Sortare crescatoare pe coloana X
   - Sortare descrescatoare pe coloana Y
   - Colorare celula daca contine valoarea indicata
   - Afisare card
   - Verificare combinatii finale (linie, coloana sau diagonala completa)

3. **Aplicarea comenzilor**
   - Dupa aplicarea unei comenzi:
     - Daca exista un card castigator:
       - Afisare indice card castigator
       - Afisare card castigator (`#` pentru celulele colorate)
       - Afisare punctaj
       - Terminarea executiei
     - Daca mai multe carduri sunt castigator:
       - Castigatorul este cel cu punctaj maxim
       - In caz de egalitate, ID-ul minim castiga
   - Daca niciun card nu castiga la final: `NO WINNER`

### 1.3 Restrictii

- Teste cu un singur card
- Teste cu mai multe carduri
- Se poate primi punctaj partial implementand doar anumite functionalitati

### 1.4 Date de intrare

- Prima linie: N (numarul de carduri)  
- Urmeaza N matrici 5x5 (numere intre 1 si 75)  
- Dupa fiecare matrice: linie goala  
- Urmeaza M (numarul de bile)  
- Urmeaza M linii: COLOANA-NUMAR sau SPECIAL

### 1.5 Date de iesire

- Pentru SHOW: afisarea cardului jucatorului
- Daca exista castigator:
  - Linie cu indicele cardului castigator
  - Cardul castigator
  - Linie cu punctaj
- Daca nu exista castigator: `NO WINNER`

---

## Problema 2

### 2.1 Descriere

Biblioteca cu carti:

- ID carte – numar natural
- Titlu – sir de max 40 caractere
- Autor – sir de max 20 caractere
- Anul aparitiei – numar natural
- Descriere – alocare dinamica exact cat este nevoie (max 500 caractere, newline final)

**Important:**  
Structura pentru carte + vector dinamic pentru toate cartile.

### 2.2 Cerinte

- Citire carti
- Implementarea comenzilor:

1. `SEARCH <ELEMENT>`  
   - Daca numar → cauta cartile cu anul aparitiei egal  
   - Daca sir de caractere → cauta in titlu sau autor (case-insensitive)  
   - Afisare in ordine crescatoare ID  
   - Daca nu exista rezultate: `NOT FOUND`

2. `REPLACE <WORD1> <WORD2>`  
   - Inlocuieste toate aparitiile lui WORD1 cu WORD2 in descrierea cartilor  
   - WORD1 si WORD2 fara spatii

3. `ENCODE <ID>`  
   - Codifica descrierea cartii:  
     - Fiecare subsir de caractere identice → caracter + nr aparitii  
     - Nr aparitii convertit in hex  
     - Sirul obtinut inversat  
   - Ignora semne de punctuatie si cifre  
   - Daca ID inexistent → ignor comanda

4. `ADD_BOOK` (urmata de 5 linii: ID, Titlu, Autor, An, Descriere)  
   - Adaugare la finalul vectorului  
   - Realocare dinamica daca este nevoie

### 2.3 Date de intrare

- Prima linie: N (numar carti)  
- Pentru fiecare carte: 5 linii (ID, Titlu, Autor, An, Descriere)  
- Dupa cele N×5 linii: linie cu M (numar comenzi)  
- Urmeaza M comenzi

### 2.4 Date de iesire

- Pentru SEARCH: afisare carti gasite (format la fel ca citire)  
- Daca SEARCH nu gaseste nimic → `NOT FOUND`  
- Dupa fiecare SEARCH: rand liber  
- La final:
  - Linie cu nr total carti  
  - Pentru fiecare carte: 5 linii (ID, Titlu, Autor, An, Descriere)

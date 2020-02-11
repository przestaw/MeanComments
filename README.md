# Analiza Algorytmu

## Temat projektu :

Detektyw Karczoch - nieuczciwe konta na instagramie

Zadanie : Przygotować program, który na podstawie zamieszczonych komentarzy oceni, czy dane konto jest uczciwe.
Szczegóły algorytmu i zadania w dokumentacji *.pdf *w folderze ./Doc*


## Opis użytkowania :

Program umożliwia profilowanie algorytmu, generowanie oraz rozwiazywanie problemów.
W przypadku nie podania żadnego trybu działania lub opcji -h wyświetlona bedzie lista trybów.
W przypadku podania rozmiaru jednej z grup równego 0 *[--group_count]* rozmiary grup sa każdorazowo losowane.

### Parametry :
- -h *[ --help ]* - ekran z objaśnieniami
- -m *[ --mode ]* - tryb działania programu *[1 = rozwiazywanie, 2 = generacja, 3 = profilowanie]*
- -o *[ --output ]* - plik wyjściowy dla generowanych problemów *[przy braku problem jest wypisywany na stdout]*
- -i *[ --input ]* - plik wejściowy do analizy *[przy braku problem jest pobierany z stdin, aż do napotkania EOF]*
- --iter (=1) - liczba iteracji przy profilowaniu algorytmu
- -c *[ --comments_count (=10)]* - całkowita liczba komentarzy *[dla generowanych problemów]*
- --users_count (=5) - całkowita liczba użytkowników *[dla generowanych problemów]*
- --group_count - liczność jednej z grup *[ma znaczenie przy generowaniu uczciwych problemów]*
- -f *[ --fairness ]* - uczciwosc konta *[dla generowanych problemów]*
- -s *[ --seed (=0)]* - ziarno dla generatora liczb losowych *[jesli = 0, RNG domyslny dla platformy generuje ziarno]*

### Przyklady polecen :

- przyklad rozwiazywania :
    `./AAL-program -m 1 -i 'moj-problem.txt'`
- przyklad generowania :
    `./AAL-program -m 2 -o 'moj-problem-uczciwy.txt' -f 1 --users_count 100 --group_count 20 -c 10000`
- przyklad profilowania :
    `./AAL-program -m 3 --iter 10 --users_count 1000 --group_count 325 -c 50000`

## Kompilacja : 

Kompilacja jest zarządzana przez system budowania cmake. Do zbudowania jest biblioteka z algorytmem, program zawirający plik main oraz testy. Bez zbudowania i przejścia testów nie można skompilować programu ani biblioteki.
Aby skompilować cały projekt należy wygenerować plik projektu lub makefile:

W katalogu glownym :
- dla makefile konfiguracji debug : 
    cmake ./Sources -DCMAKE_BUILD_TYPE="DEBUG"
- dla makefile konfiguracji relase : 
    cmake ./Sources -DCMAKE_BUILD_TYPE="RELASE"

po takiej operacji aby zbudować program wystarczy zawołać:

    make AAL-program

skompilowane pliki możan znaleźć w folderze ./bin


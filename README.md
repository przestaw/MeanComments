Stawczyk Przemysław 293153

## Temat projektu :
Detektyw Karczoch - nieuczciwe konta na instagramie

Zadanie : Przygotować program, który na podstawie zamieszczonych komentarzy oceni, czy dane konto jest uczciwe.
Szczegóły algorytmu i zadania w dokumentacji *.pdf

## Opis użytkowania
Program umożliwia profilowanie algorytmu, generowanie oraz rozwiazywanie problemów.
W przypadku nie podania żadnego trybu działania lub opcji -h domyslnie wybierana jest opcja generowania problemów.
W przypadku podania rozmiaru jednej z grup równego 0 [--group_count] rozmiary grup sa  ̨ każdorazowo losowane.

### Parametry
> -h [ --help ] - ekran z objaśnieniami
> -m [ --mode ] - tryb działania programu [1 = rozwiazywanie, 2 = generacja, 3 = profilowanie]
> -o [ --output ] - plik wyjściowy dla generowanych problemów [przy braku problem jest wypisywany na stdout]
> -i [ --input ] - plik wejściowy do analizy [przy braku problem jest pobierany z stdin]
> --iter (=1) - liczba iteracji przy profilowaniu algorytmu
> -c [ --comments_count (=10)] - całkowita liczba komentarzy [dla generowanych problemów]
> --users_count (=5) - całkowita liczba użytkowników [dla generowanych problemów]
> --group_count - liczność jednej z grup [ma znaczenie przy generowaniu uczciwych problemów]
> -f [ --fairness ] - [dla generowanych problemów]
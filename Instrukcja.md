# Instrukcja

## Budowanie
Aby zbudować program, otwórz terminal i wpisz polecenie `make` (lub `mingw32-make`). Wymagany jest kompilator `gcc`. Możesz posprzątać pliki obiektowe poleceniem `make clean`.

## Uruchomienie
1. Upewnij się, że posiadasz folder `dane` z plikami `A.txt` i `B.txt` obok pliku wykonywalnego.
2. Uruchom program z terminala: `./kalkulator.exe`
3. Wybierz opcję (1, 2 lub 3) i sprawdź zawartość pliku `wynik.txt`.

## Format danych
Dane muszą znajdować się w pliku tekstowym. Pierwszy wiersz zawiera dwie liczby całkowite - wymiary (np. `3 3`). Kolejne wiersze to elementy macierzy (liczby zmiennoprzecinkowe, z kropką dziesiętną) rozdzielone spacjami.

## Błędy
W przypadku nieprawidłowości (np. zły plik, złe wymiary, niewłaściwe dane) program wyświetla komunikat np. `Blad: niezgodne wymiary dla wybranej operacji` i kończy działanie z kodem wyjścia `1`.

## Testy
Weryfikacja znajduje się w pliku `testy.c`. Aby automatycznie skompilować i uruchomić bazę testową, użyj polecenia:
`make test` (lub `mingw32-make test`)
Zwróci ono komunikat [ OK ] dla poprawnych przypadków lub [ BLAD ], kończąc proces awaryjnie w razie niezgodności.

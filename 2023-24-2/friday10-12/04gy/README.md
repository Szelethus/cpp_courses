# 4. gyak

## Paraméter átvétel: swap
### Érték szerint
### Referencia / Pointner szerint
#### Különbség, konvenciók

### Mikor melyiket érdemes választani?
#### Rule of thumb: const & when in doubt
#### Memóriacímet is másolni kell
#### By-value optimization

### Visszatérési érték

## Tömb paraméter
### Pointer decay, sizeof
#### Tömb pointer + size
### Fix méretű tömb paraméter
### std::array
### Értékadás
### Template ízelítő

## Vector
### Hogy néz ki
### size(), capacity(), operator[], at(), size()
### push_back vs resize / constructor

## Polynom példa

## Complex osztály
### struct
### free fn: lus, minus, operator+, operator-
### operator*
### operator~
#### l.re * r.re - l.im * l.im, l.re * r.im + l.im * r.re

## Konstruktor
### Default konstrukor
### C++11 explicit default konstruktor
### Compiler generated
### temporálisokról NEM

### C-style initialization

## Névterek
### using namespace
### Argument Dependent Lookup

## Reference visszatérés

## operator<<
## operator>>

### operator~ tagfüggvénnyé alakítása

## Memóriamodell
### Stack, globális tárhely

## Heap
### Lassabb, de nagyobb
### Stacket nem kerültük meg
### nincs nevük
### Memory leak, leak sanitizer
### nullptr delete

## Fejelemes láncolt lista
### Törlési sorrend
### add, free, display
### add "egyszerűsítése"
### Konstruktor


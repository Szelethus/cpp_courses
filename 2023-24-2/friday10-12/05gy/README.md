# Öttedik gyakorlat

## Complex osztály
### struct
### free fn: lus, minus, operator+, operator-
### operator*
#### l.re * r.re - l.im * l.im, l.re * r.im + l.im * r.re
### negate
### negate tagfüggvénnyé alakítása
### negate -> operator~

### tagfv vs free függvény

### C-style initialization

## Konstruktor
### Default konstrukor
### C++11 explicit default konstruktor
### Compiler generated
### temporálisokról NEM

## Névterek
### using namespace
### Argument Dependent Lookup

## Reference visszatérés

## operator<<
## operator>>

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

### push_back, free beemelése

### Compiler generated methods
#### Konstruktor
##### default konstruktor
##### C++11 explicit default konstruktor hívás

##### Temporálisok
###### Név nélküli emporálisok
###### Temporálisok + const&
###### Literálok is ilyenek, csak nem változók

#### Destruktor
##### RAII
##### Általánosabb megoldás a garbage collectionre, sőt, garbage nem is keletkezik

#### Copy konstruktor (shallow, deep copy)
#### Értékadó operátor
##### Kell egy free is
##### return *this
##### self assignment
##### Miért nem konstans referenciával térünk vissza

### Rule of 3
### Reguláris típus, félig reguláris típus

### Design philosophy: Make it easy to use corrently, and hard to use incorrectly

### Láthatóság
#### Head védése
#### Node védése (majd vissza)
#### free() védelme

### Iterátorok
#### Tömböknél pointer
##### ++ -- + - * == !=
#### Pointerek általánosítása


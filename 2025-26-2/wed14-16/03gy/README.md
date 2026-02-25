# Háromadik gyakorlat

## Fájlokra bontás, fordítás lépései

## Jobbérték, balérték, láthatóság, élettartam
### globális változók
### automatikus változók, heap
### https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3055.pdf

## Stack működése

## Konstans korrektség

## Pointerek
### címképző, dereferáló operátor
### 0, NULL, nullptr
### Konstans korrektség
#### char * = "Hello"
#### Konstans mutató, konstansRA mutató
### Mutatóra mutató

## Paraméter átvétel: swap
### Érték szerint
### Referencia / Pointner szerint
#### Különbség, konvenciók

### Mikor melyiket érdemes választani?
#### Rule of thumb: const & when in doubt
#### Memóriacímet is másolni kell
#### By-value optimization

## login.cpp: nem definiált viselkedések kihasználása

## Visszatérési érték: read

## Tömb paraméter
### NEM pythonbeli lista
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

## Complex osztály
### struct
### free fn: plus, minus, operator+, operator-
### operator*
#### l.re * r.re - l.im * r.im, l.re * r.im + l.im * r.re
### negate
### negate tagfüggvénnyé alakítása
### negate -> operator~

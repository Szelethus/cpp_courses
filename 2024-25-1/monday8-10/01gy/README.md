# 1. Gyakorlat

## Bevezető
### Hatékonyság
### Resource management
### Általánosság
### Multiparadigma
### C++ szabványok, és annak implementációja (standard könyvtár + forditó)

## Hello World program
### #include, tranzitiv lezárt
### std névtér
### right shift operátor
### deklaráció, definíció, ODR

## Fordítás konzolból

## Definiált viselkedés, nem specifikált viselkedés, implementáció által definiált viselkedés

## Fordítás lépései

## Preprocesszor
### #define, #undef, #ifndf, #ifdef, #else, #endif
### -E -P
### #include, rekurzív include, header/include guard

## Linkelés
### két c++ fájl, include nélkül majd include-al
### -c kapcsoló
### nm parancs

## Compiler flagek
### -Wall, -Wextra, -Weverything
### -O2, -save-temps

## Globális változók
### Globális névtér
### linking error
### problémák

## Inicializációs hibák, global initialization

## Láthatóság, élettartam
### automatikus változók, globálisak, érintőlegesen heap
### Shadowing

## Jobb és balérték
### C++11ben változott ez
### https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3055.pdf

## Stack működése

## Pointerek
### címképző, dereferáló operátor
### 0, NULL, nullptr
### Konstans korrektség
#### Konstans mutató, konstansRA mutató
### Mutatóra mutató

## Tömbök
### sizeof(t), sizeof(t[0])
#### Operátor, nem függvény!
### stacken ábrázolva
### Túlindexelés, biztonsági rés
### Sanitizer, valgrind, warningok

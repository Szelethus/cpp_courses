# 8. gyakorlat

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
### factorial.cpp példa

- Fájlból beolvasás
- Program argumentumok
- FÁjlokra osztás

## Láthatóság, blokkok, modulok

***Emlékeztető:*** 
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok

1. Deklarálj és definiálj egy változót a main függvényen kívül! Változtasd az értékét és írasd ki!
2. Készíts egy függvényt, benne deklarálj és definiálj egy változót! El tudod érni a változót a függvényen kívül?
3. Írj egy elágazást az előző feladatban megírt függvénybe a változó definíció után! Vizsgáld meg, hogy a változót eléred-e az `if` feltételében, valamint az igaz blokkjában, továbbá opcionálisan az `else` és `else if` ágában!
4. Deklarálj és definiálj változót egy `if` bármelyik ágában, vagy egy tetszőleges ciklus magjában! Vizsgáld meg, hogy a változót eléred-e a blokkon kívül!
5. Hozz létre egymásba ágyazott scope-okat ("{}" párok közti blokkokat), vezess be mindegyikben egy változót! Vizsgáld, hogy melyik scope-ból melyik változókat éred el! Mikor lehet érdemes scope-okat használni? Mi az a verem és miképp csatlakozik a scope kezeléshez?
6. Deklarálj előre egy függvényt, majd definiáld azt, paraméterül más paraméterneveket használva! Mi történik? Mikor lehet ez hasznos?
7. Deklarálj egy kétparaméterű függvényt, ugyanazon változónevet használva a két paraméternek! Mi történik?
> Hozz létre egy **my_utils.h** és **my_utils.c** fájlt! Az elkövetkezendő feladatok (8,9,10) függvény deklarációit helyezd a header file-ba, a definícióit pedig a c fájlba. Az eddigi **main.c** fájlban include-old a headert, majd a main-ben hívd a függvényeket!
8. Hozz létre egy függvényt, deklarálj és definiálj benne egy `static` változót! Növeld meg a változó értékét és írasd ki! Hívd meg a `main`-ben többször is a függvényt! Mi történik?
9. Írj egy swap függvényt, amely megcseréli két int változó értékét!
10. Írj egy olyan függvényt, amely két int pointert vár paraméterül, és visszaadja a nagyobb értékre mutató pointert!
11. Módosítsd a swap feladatot úgy, hogy a függvényt a main-en belül deklarálod és definiálod! Működik-e a program GCC és Clang fordítóval? Mikor lehet ez a funkcionalitás hasznos?



### Opcionális feladatok

1. Deklarálj és definiálj egy változót egy ciklus magjában, majd ágyazz be egy második ciklust és vizsgáld, hogy azon belül eléred-e a külső ciklusban deklarált változót!
2. Static változó segítségével hozz létre egy olyan faktoriális függvényt, mely számon tartja, hogy hányszor hívták 1-nél kisebb paraméterrel!
3. Írj egy olyan függvényt, amely két `int`-et vár paraméterül és egy, az eredményre mutató pointert ad vissza! Mi történik, mikor a `main`-ben kiírod az eredményt (dereferálva)?

### Gyakorló feladatok

1. Hozz létre külön modulokat (.h és .c párokat) az eddigi gyakorlatok függvényeiből! pl Matematikai modult (faktoriális, stb), String Utils modult (strlen, strcpy saját implementációk), ArrayUtils modult! Fordítsd le a modulokat külön-külön, majd írj egy main.c fájlt, melyben include-olod őket és használod a függvényeiket, viszont úgy fordítsd a **main.c** állományt, hogy a hivatkozott libeket ne fordítsd újra!
2. Hozz létre további függvényeket a **my_utils.c** file-ban! A függvények hivatkozzanak egymásra! Ezeket a függvényeket meg tudod hívni a **main.c** fájlban is? Miért? Miért nem?

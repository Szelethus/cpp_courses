# 4. gyakorlat

## Tananyag

- Tömbök
  - sizeof
- pointerek
- preprocesszor makrók

## Eddigiek ismétlése, gyakorlása

***Emlékeztető:*** 
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- Az egyes feladatokat szervezzük ki saját alprogramba!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok

1. Írd ki, hogy a géped hány bájton ábrázol egy `int`, `long int`, `unsigned int`, `unsigned long int`, `char`, `_Bool`, `float`, `double`, `long double` értéket.
(Használd fel nyugodtan a már korábban elkészített kódodat, ha van!)
2. Próbáljuk ki az operator chaining-et (a\<b\<c)!
3. Írasd ki 10-től 0-ig csökkenő sorrendben az egész számokat. Próbáld `int` és `unsigned int` típusú ciklus változóval is megoldani a feladatot.
4. Írj programot, mely a standard inputról bekért számról eldönti, hogy szökőév-e. Szökőév minden néggyel osztható év, kivéve, ami százzal is osztható.  Viszont a négyszázzal oszthatók szintén szökőévek lesznek. 
> - A megoldásban **NE** használj `if`-et!
5. Készíts egy 6 oldalú dobókocka szimuláló alprogramot! Nézd meg/használd a `rand()` függvényt. A főprogramban dobj egymás után 10-szer a kockával és írasd ki az eredményeket.


### Opcionális feladatok

1. Kitalálós játék (guessing): Mindaddig olvass be egy számot a felhasználótól, míg az nem egyezik a programban megadottal (először lehet beégetett konstans (`const`) vagy `#define`, de később használj véletlenszerű értéket). Hibás tipp esetén segíts, hogy túl kicsi vagy túl nagy volt-e a tipp. 
> - Többféle ciklussal is próbálj megoldást adni
> - Próbáld ki hogyan helyettesíthetőek az `if` utasítások a '`?`' operátorral
2. Egészítsd ki a guessing programot a hibás próbálkozások számlálásával, majd ennek értéke alapján adj szöveges értékelést!
> - Kezdetnek egyszerűen kiírod, hogy hány próbálkozásból sikerült
> - Aztán a próbálkozások függvényében más-más dicséretet adsz a kimenetre ( Hasznos vezérlési szerkezet ehhez: `switch() case`)
3. Egészítsd ki a guessing programot, hogy a játék elején nehézségi szintet lehessen változtatni. Például:
> - **könnyű:** 1-10 között választ a program kitalálandó számot.
> - **közepes:** 1-100 között
> - **nehéz:** 1-10000 között
4. Szervezd úgy a guessing program kódját, hogy a `main()` függvényen kívül még legalább három másik alprogram szerepeljen (pl.: get_target, guessing, evaluate).


### Gyakorló feladatok

1. Kérjünk be 1-12 között egy számot a felhasználótól. A megadott szám az év megfelelő hónapját jelképezze. Írassuk ki, hogy melyik évszakhoz tartozik ez a hónap. Ha a megadott szám nem feleltethető meg egy hónapnak, akkor jelezzük a hibát és kérjünk be új számot.
2. Kérjünk a felhasználótól egy számot, egy műveleti jelet, majd egy második számot. Végezzük el a megadott matematikai kifejezést és adjuk vissza az eredményt.
3. Rajzold ki a Pascal háromszög első n sorát (n-et kérd be)!
4. Módosítsd az előző feladatokat, hogy parancssori argumentumokkal adod meg a számokat. Figyelj oda, hogy a program, akkor is jól működjön, ha nem érkezett külső argumentum, ilyenkor utólagos beolvasással pótolja a hiányt!
5. Készíts egy statisztikai programot. Olvass be egymás után egész számokat az alapértelmezett bemenetről, a beolvasás végét a 'q' karakter jelezze. A számokat nem kell tárolni. A program írja ki:
> hány számot olvastunk be
> mennyi a számok összege
> mennyi az átlag
> melyik a legkisebb szám
> melyik a legnagyobb szám
> hány pozitív szám volt
> hány negatív szám volt

6. Nézd meg, milyen nem definiált viselkedések fordulhatnak elő C programokban: [Github lista](https://gist.github.com/Earnestly/7c903f481ff9d29a3dd1)


### Verseny feladat

1. Hányféleképpen tudod a 42-t kiíratni a képernyőre? Csak előjeles (`signed`), egész (`int`) típusokat, literálokat használj. Egyetlen `char` típusú változót használhatsz. Az értékadás kivételével más operátor nem használható.
> - Néhány tipp: oktális, hexa literálok, típuskonverziók, túlcsordulás.
> - Több mint 20 féle megoldás képzelhető el!

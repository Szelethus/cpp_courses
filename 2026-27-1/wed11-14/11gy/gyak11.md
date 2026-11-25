# 11. gyakorlat

## Tananyag

- 10 pontos doga:
  - nem forduló kód
  - paraméter beolvasás nem volt jó
  - program gyakran nem tért vissza
  - scanf("%s")
- Enum
- Tagged union
- Struct
  - typedef
  - nyíl operátor
  - designated initializer

## Összetett adatszerkezetek

***Emlékeztető:***
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- A feladatokat headerekre és forrásfájlokra tagolva oldjuk meg!
- Ha elakadnál: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok

#### I. Összetett adatok kezelése
1. Készítsünk két tömböt, amelyekben `STUD_CNT` számú hallgató adatait szeretnénk tárolni. Írjuk egy inicializáló függvényt, ami ezt a két tömböt feltölti random adatokkal.
   * Az egyik tömb a hallgatóknak egy egyedi azonosítóját tárolja `int` típussal
   * A másik tömb pedig a hallgató tanulmányi átlagát tárolja `double` típussal
2. Most adjunk a hallgatók adatai mellé még egy attribútumot, amely a hallgatók életkorát tárolja `short` típussal. Írjuk át ez alapján a korábban megírt függvényünket.
3. Mi történne akkor, ha a későbiekben további adatokat kellene támogatnunk?

#### II. Struktúra bevezetése és használata
1. Hozzunk létre egy új típust `Student` néven, mellyel hallgatókat fogunk reprezentálni. Tartalmazza a korábbi azonosítót, átlagot és kort is. Vizsgáljuk meg a memóriaszükségletét a típusnak, kísérletezzünk az adattagok sorrendjével, és figyeljük meg ennek hatását.
2. A praktikusság jegyében hozzunk létre egy alias típust `typedef` fel, hogy a típust tudjuk a `struct` előtag nélkül is használni.
3. Készítsünk egy olyan függvényt (`student_init`), amely minden hívás alkalmával létrehoz egy random adatokkal feltöltött `Student` példányt (Az elkészült példányra mutató pointerrel tér vissza).
4. Készítsünk kiíró függvényt (`student_print`) a `Student` struktúrához, mely könnyen olvasható módon kiírja a standard kimenetre egy adott hallgató összes adatát.  
5. Hozzunk létre egy függvényt (`student_search`) mely egy `Student` példányokat tároló tömböt kap és visszaadja a legmagasabb átlagú hallgatót.

#### III. Struktúra továbbfejlesztése
1. A `Student` struktúra mintájára, hozzunk létre egy `AdvStudent` struktúrát, amelyben külön tudjuk kezelni a BSc-s, MSc-s és PhD-s hallgatókat. Erre hozzunk létre egy felsoroló típust (`enum`) `Type` néven és adjuk hozzá a struktúrához új adattagként.
2. A hallgató típusától függően tároljunk különböző plusz adatokat egy `union` típus segítségével.

  * **BSc:** összesen hallgatott kurzusok száma(`int`).
  * **MSc:** az összesített korrigált kreditindex(`double`)
  * **PhD:** legmagasabb impaktfaktorú folyóiratnak az impaktfaktora, melybe publikált (`double`), illetve Erdős-számát (`int`) egy `struct` segítségével.

  - Vizsgáljuk meg a típus memóriaszükségletét és vessük össze, mi lett volna, ha `struct`-ot használunk helyette.

3. Írjunk meg a korábbi inicializáló, kiíró és kereső függvényeket az új struktúrához is


### Opcionális feladatok

1. A korábbi órán megírt mátrixszorzáshoz, hozzunk létre egy `Matrix` típust, mely tartalmazza a mátrix dimenzióinak méretét, illetve a tömb első elemére mutató pointert adattagként.
2. Az indexelés megkönnyítése érdekében írjunk egy `at` függvényt, mely egy mátrix példányra mutató pointert, sor és oszlop indexet vár, és ezek alapján visszatér egy pointerrel, amely a mátrix megadott koordinátájú elemére mutat.
3. Alakítsuk át a mátrixszorzást ezek segítségével.

### Gyakorló feladatok

1. Hozzunk létre egy egészeket tartalmazó dinamikus tömb típust, mely adattagként tárolja a tömb aktuális méretét, kapacitását és egy tömbre mutatót.
2. Hozzunk létre egy függvényt mely a paraméterül kapott kezdeti kapacitás alapján létrehoz egy új példányt, megfelelően beállított adattagokkal. Majd ennek párját, mely megfelelően felszabadítja a kapott példányt.
3. Írjunk egy függvényt mellyel hozzá tudunk adni egy elemet a tömb végére. Ha megtelt a tömb, foglaljunk le egy kétszer nagyobb tömböt, majd a korábbi elemeket másoljuk át és frissítsük az adattagokat. Ügyeljünk a memóriaszivárgásra.

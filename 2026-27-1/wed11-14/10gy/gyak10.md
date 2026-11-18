# 10. gyakorlat

Tananyag

- buffert le kell zárni \0-val
- realloc kétirányból szabadítandó
- strcpy

## Dinamikus memóriakezelés

***Emlékeztető:***
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- A feladatokat headerekre és forrásfájlokra tagolva oldjuk meg!
- Törekedj a dinamikus memóriakezelésre!
- Ha elakadnál: [C reference](https://en.cppreference.com/w/c)


### Kötelező feladatok

1. Írj egy programot, ami bekér a felhasználótól egy legfeljebb **20** karakter hosszú szöveget, és készít belőle egy másolatot. Ügyelj arra, hogy a másolat csak akkora memóriaterületet használjon, ami feltétlenül szükséges.
2. Írj programot, ami **5** szót olvas be a felhasználótól, majd kiírja őket fordított sorrendben őket. A tároláshoz pontosan annyi memóriát használj, amennyit a szavak igényelnek! 
3. Írj programot, amely tetszőleges számú számot tud beolvasni a felhasználótól. A felhasználó úgy jelezheti a bevitel végét, hogy nem számot ad meg a bemeneten. A számok tárolásához csak dinamikus memóriakezelést használj! A beolvasott számokat írja ki a program fordított sorrendben. Legalább kétszer fusson le a program egymás után! (Azaz a szám bevitel és fordított kiírás.) Ügyelj arra, hogy csak a szükséges mértékben használj memóriát a tároláshoz és a program működés közben ne keletkezzen memóriaszemét!
4. Készíts egy _`reverse()`_ nevű függvényt, aminek egy string paramétere van. A függvény fordítsa meg a string karaktereit helyben. Azaz a függvény az eredményt ugyanazon a memóriaterületen adja vissza, amit paraméterként kapott. Például egy palindrom string karakterei nem változnak meg a függvény futása során.
5. Módosítsd az előző _`reverse()`_ nevű függvényt úgy, hogy ne helyben cserélje a karaktereket (azaz az eredeti string ne változzon), hanem egy másik, új stringet hozzon létre, és azzal térjen vissza. Dinamikusan foglald a szükséges memóriát!
6. A *3. feladat mintájára* írj egy programot, amely tetszőleges számú és hosszúságú szót tud beolvasni a felhasználótól, amíg **"0"** indikátor nem érkezik a felhasználótól a bemeneten. Továbbra is ügyelj a takarékos és helyes memóriakezelésre!


### Opcionális feladatok

1. Készíts egy függvényt, ami egészek tömbjét várja paraméterül. A függvény térjen vissza egy másik tömbbel, amiben a paraméter tömb elemei szortírozva találhatók: elöl a párosak, hátul a páratlanok. Dinamikusan kezeld a memóriát!
2. Módosítsd a *2. Kötelező feladat* programját, úgy hogy parancssori argumentumként várjon egy számot, és annyi szót olvas be a felhasználótól, amennyit megadott. Ha mindet megadta, írja ki fordított sorrendben a szavakat.
3. Módosítsd az előző feladat megoldását úgy, hogy ha a felhasználó az **end** szót írja be, akkor a beolvasás véget ér, mielőtt elérné a parancssori argumentumként megadott limitet. Használj tömböt. Majd írd ki a tömb tartalmát fordított sorrendben.


### Gyakorló feladatok

1. Adott egy fájl, aminek minden sorában számok vannak szóközökkel elválasztva. Írj egy programot, mely soronként olvas ebből a fájlból, és minden sort növekvő számsorrendben kiír egy output.txt nevű fájlba. Dinamikusan kezeld a memóriát!
2. *(Haladó)* Írj programot, amely számontartja egy cég alkalmazottait a felvételük sorrendjében. Vegyél fel egy struktúrát, amely eltárolja az alkalmazott nevét és fizetését. A program futás közben folyamatosan kérjen be adatokat új alkalmazottakról, és minden "felvétel" után írja ki az összes alkalmazott adatait! A program fejezze be a futást, ha a felhasználó az **exit** szót írja be. Dinamikusan kezeld a memóriát! Ügyelj rá, hogy optimális legyen a dinamikus memóriafoglalás!

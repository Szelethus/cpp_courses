# 9. gyakorlat

# Tananyag
- Fájlból beolvasás

## Stringek, Fájlok

***Emlékeztető:***
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- A feladatokat **headerekre és forrásfájlokra** tagolva oldjuk meg!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)


### Kötelező feladatok

0. Készíts a main-ben egy menüt, melyben külön menüpontok alá tudod elhelyezni a megírandó feladatok alprogramjait. A felhasználó parancssori argumentum segítségével tudja indítani a kívánt programot.
1. Írj programot, amely beolvas egy stringet a standard inputról, és megszámolja benne a karakterek és a szavak számát! A beolvasáshoz használd az `fgets()` függvényt.
2. Írj programot, amely beolvas egy második stringet, és összehasonlítja az előzővel! A feladatot végezd el beépített művelettel a `string.h` könyvtárból.
3. Másold le az előző stringet egy harmadik stringbe! A feladatot végezd el beépített művelettel.
4. Hozz létre egy stringet karakterek tömbjeként és egyet pointerként! Próbálj meg kicserélni mindkét változatban egy-egy karaktert! Mi a különbség a kettő között?
5. Hozz létre egy szöveges fájlt tetszőleges szöveggel. Írj programot, amelyben megnyitod a fájlt az `fopen()` függvény segítségével, és olvasd be a fájl tartalmát az `fgets()` függvény meghívásával. A beolvasott szöveget konvertáld csupa nagybetűssé, és írd ki a nagybetűs szöveget a standard kimenetre! A beolvasás után zárd be a fájlt az `fclose()` függvénnyel.
6. Egészítsd ki az előző feladatot úgy, hogy a nagybetűs szöveget nem a standard kimenetre írod ki, hanem egy másik fájlba, az `fprintf()` függvény segítségével. Az új fájl létrehozásához is használd az `fopen()` függvényt.


### Opcionális feladatok

0. Egészítsd ki a 2-es és 3-as feladatokat a beépített műveletes megoldás mellett saját magad implementált megoldással is. Egy második parancssori argumentum segítségével lehessen kiválasztani, hogy a beépített vagy saját megoldás fusson le a kiválasztott feladatnál, ha releváns.
1. Írj programot, amely megállapítja egy stringről, hogy az palindrom-e.
2. Hozz létre két új fájlt, amelyek ugyanannyi tetszőleges számot tartalmaznak. Olvasd be mindkét fájlból párhuzamosan a számokat, és írd ki a szorzatukat egy harmadik fájlba! A beolvasáshoz használd a `fscanf()` függvényt.
3. Vizsgáld meg, hogy a tanult beolvasó függvények közül melyek alkalmasak karakterek egyesével történő beolvasására a standard inputról!


### Gyakorló feladatok

1. Írj egy számológép alkalmazást, amely képes a __+, -, *, /__ és __%__ műveletek elvégzésére egész számokon (külön modulba)! Írj menüt is a programhoz! Addig fusson a program, amíg a felhasználó "exit" utasítást nem ad.
2. Módosítsd a számológép alkalmazást úgy, hogy induláskor a felhasználó választhassa ki, hogy az egész vagy a valós számokon értelmezett műveletekkel szeretne dolgozni. Hozd létre a valós számokhoz tartozó műveletek modulját (__+, -, *, /__, ahol a '/' most a valós osztásnak felel meg).
3. Bővítsd a számológép alkalmazást új tetszőleges modulokkal. (Pl.: hatványozó, trigonometrikus, memória modul stb.) 



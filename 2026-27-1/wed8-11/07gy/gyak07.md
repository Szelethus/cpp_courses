# 7. gyakorlat

## Tömbök, pointerek

***Emlékeztető:*** 
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- Az egyes feladatokat szervezzük ki saját alprogramba!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok 

0. Vizsgáljuk meg C-ben a parancssori argumentumok átvételét. Ezután készítsünk egy kis demót, melyben kiírjuk a kapott számot, ha a programot extra adattal hívták meg. (Feltesszük, hogy szám az adat.)
1. Készíts egy alprogramot, amely egy paraméterben kapott nxn-es mátrixot feltölt az n-es szorzótábla értékeivel. Majd írasd ki a főprogramban az egészet a standard kimenetre a következő formátumban: *a x b = c*, ahol *a* és *b* a szorzandó elemek, *c* pedig a mátrixban tárolt érték.
2. Írj programot, amely 1-től n-ig kiszámolja a pozitív számok összegét a következő megkötésekkel: *n*-et olvasd be a standard inputról a main-ben, a feladatot egy alprogram oldja meg amelynek nincs visszatérési értéke, az eredményt a main írja ki.
3. Írj programot, amely tárolja, majd kiírja egy számnak az első n darab hatványát (szám a 0.-ontól egészen a szám az n.-enig)! A számot olvasd be parancssori argumentumként. A program készüljön fel arra az esete is, ha nem érkezik külső argumentum.
4. Készíts egy alprogramot, mely feltölt egy kapott tömböt 0 és 100 közötti véletlen **valós** értékekkel (azaz törtszámok legyenek benne). Ezután a főprogram állapítsa meg a tömbről, hogy hány eleme nagyobb 50-nél.
4. Írj alprogramot, amely a kapott tömbben megszámolja, hogy hány pozitív, hány negatív és hány 0 elem található, majd az ereményeket a főprogramban kiírjuk. (Érdemes egy segéd függvénnyel véletlenszerűen egészekkel, mondjuk -2 - 2 tartományon, feltöltött tömböt elemezni. Hogyan tud egy függvény több eredményt a hívó rendelkezésére bocsájtani?)
6. Írj alprogramot, amely egy tömb elemeinek a sorrendjét helyben megfordítja, azaz nem használ más tömböt a feladat megoldásához. 
Pl.: [1,2,3,4,5] -> [5,4,3,2,1]
7. Egy alprogram segítségével olvassunk be számokat a standard bemenetről, melyeket tároljunk egy tömbben. A beolvasandó számok mennyiségét egyeztessük a felhasználóval. A beolvasás után a főprogramban írjuk ki, hány számot olvastunk be, majd soroljuk fel őket a standard kimeneten.
> - Jobb eszköz híján válasszunk egy "kellően" nagy tömböt a várható számok tárolásához


### Opcionális feladatok

1. Olvass be egy számot, és számítsd ki a számjegyeinek szorzatát!
2. Az előző feladathoz írd ki, hogy hány páros és páratlan számjegye van a számnak!
3. Írj programot, amely megcseréli egy legalább *3* jegyű szám első és utolsó számjegyét! (Bár nem ideális, de tömbös megoldás használata a cél.)
> - Tetszőleges sok számjegyű számra működjön!
4. Készíts egy alprogramot, ami a kapott tömb elemeit eltolja egy a paraméterben megadott 'n' pozícióval.
Pl.:[1,2,3,4,5] _ 2 _-> [4,5,1,2,3] vagy
    [1,2,3,4,5] _ -1 _-> [2,3,4,5,1]
5. Találd meg és írd ki a képernyőre az összes Armstrong-számot 0 és N között. *N*-et olvasd be a standard inputról. Armstrong-számnak nevezünk egy *n* jegyű számot, ha minden számjegyét az *n*-edik hatványra emelve és összeadva, az eredeti számot kapjuk.
> - *Például a 153 esetében 153=1^3+3^3+5^3*.
6. Írj alprogramot, amely kiszámítja egy egész szám faktoriálisát! Milyen korlátai vannak a megoldásnak?
7. Olvassunk be hexadecimális számokat a standard bemenetről (*0-9,a,b,c,d,e,f* karakterek), amíg más karakter nem érkezik.
A beolvasott számokat konvertáljuk át 10-es számrendszerbe, majd tároljuk őket.
> - Használd ki a karakter-szám "átjárhatóságot"
> - Csak a megfelelő karaktereket fogadjuk el, minden mást vessünk el (nagybetű belefér) és jelezzük a hibát
> - Jobb eszköz híján válasszunk egy "kellően" nagy tömböt a várható számok tárolásához


### Gyakorló feladatok

1. Rajzold ki a Pascal háromszög első n sorát (n-et kérd be)! A 3. gyakorlattal ellentétben, most ne a képletet (n alatt k) vagy a neten talált algoritmust (:P) használd, hanem segéd tömbök segítségével old meg (és törd át a korábban jelentkező ábrázolási korlátot, ha volt)!
2. Írj két függvényt, melyek egymást felváltva futnak. Az egyik, nevezzük a-nak, 2-vel osztja a paraméterként kapott értéket majd meghívja a b függvényt az eredménnyel, ha az nagyobb mint 0. A b függvény kivon 1-et a kapott értékből majd meghívja a-t a csökkentett értékkel, ha az még nagyobb mint 0. A kiinduló számot a felhasználótól kérd be, és számold, hány a-b iteráció történik, míg eléri a 0-át.
3. Tárolj el egy 4x4 mátrixban egy balra igazított karakterekből álló háromszöget. (Lásd a példát lent.) A felhasználó adhasson meg 1-től 4-ig egy értéket, mellyel szabályozhatja, hogy a háromszöget milyen orientációval rajzoljuk ki a kimenetre. (Balos, balos fejtetőn, jobbos, jobbos fejtetőn.) Kerüljük a kódismétlést! Egyetlen dupla ciklus segítségével old meg a kirajzolásokat!
> - &
> - && 
> - &&&
> - &&&&



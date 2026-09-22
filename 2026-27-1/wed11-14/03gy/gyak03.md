# 3. gyakorlat

## Aritmetikai és bit műveletek, operátorok

***Javaslat:*** Az egyes feladatokat szervezzük ki saját alprogramba!

***Emlékeztető:*** 
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok

1. Vizsgáld meg, mi a különbség a prefix ++ (`++i`) és a posztfix ++ (`i++`) operátorok között!
2. Egy ciklus segítségével olvass be pár betűt, és ha kisbetű, konvertáld nagybetűvé, ha nagybetű, akkor kisbetűvé! (Az eddig megismert `scanf()` mellé megnézhetjük a `getchar()` függvény működését is. )
> - Igyekezzünk hibabiztosra írni a kódot, nem karakter esetén, jelezzük a hibát a felhasználónak és kérjünk be új betűt!
> - A beolvasott karakterek mennyiségét többféle képpen szabályozhatjuk:
>   - előre meghatározott számú karaktert olvasunk (*n db*)
>   - külön megválasztott lezáró karakterig olvasunk (pl. bemeneten *0*-t kapunk)

3. Olvass be két számot, és végezd el rajtuk az összes lehetséges aritmetikai műveletet!
4. Olvasd be egy kör sugarát, és számold ki a kör átmérőjét, kerületét és területét!
5. Olvass be egy dátumot pozitív egész számként (egybeirva!), majd írd ki valamilyen dátum formátumban (év. hónap. nap. / DD-MM-YYYY / ...)!
6. Állapítsd meg 2-2 koordináta-rendszerbeli pontról, hogy az általuk alkotott egyenesek merőlegesek-e egymásra!
7. Olvass be két számot egy-egy változóba, és csak aritmetikai műveletek segítségével cseréld meg őket!
8. Fordítsd meg egy szám bitjeit! Mi lesz az eredmény?


### Opcionális feladatok

1. Olvasd be egy egyenlő szárú háromszög oldalait, és amennyiben a háromszög felrajzolható, számold ki a területét és kerületét! 
2. Olvasd be egy téglalap oldalait, és számold ki a területét és a kerületét!
3. Olvass be két számot, és emeld az egyik számot a másik hatványra! Mindkét irányba végezd el a feladatot!


### Gyakorló feladatok

1. Olvass utána, hogy a C milyen bitműveleteket támogat (illetve ezeknek milyen gyakorlati haszna lehet): [Bitműveletek](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
2. Döntsd el egy számról csak bitműveletek használatával, hogy páros vagy páratlan!
3. Olvass be két számot, és írasd ki a két szám között lévő összes prímszámot!
4. Fordítsd meg egy szám n-edik bitjét! Mi az eredmény?
5. Számítsd ki egy szám prímtényezős felbontását!
6. **Dátum v2** Olvassunk be egy tetszőleges természetes számot. Induljunk ki egy alap dátumból `n=0` esetén (pl.: *1800.01.01.*). A kapott egész szám az ezóta eltelt napok számát jelentse. Írjuk ki a meghatározott dátumot formázva. *Egyszerűsítés: tekinthejük az összes hónapot azonos méretűnek*
> - ***profi szint:*** A hónapokat megfelelő hosszal tekintjük
> - ***mester szint:*** Figyelembe vesszük a szökőéveket is
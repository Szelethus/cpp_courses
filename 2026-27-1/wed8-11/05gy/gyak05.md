# 5. gyakorlat

## Tömbök

***Emlékeztető:*** 
- Fordítás közben használd a **-W  -Wall  -Wextra  -pedantic** kapcsolókat!
- Tagold a forrás fájlodat, egyes feladatokat szervezz ki alprogramokba!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok 

1. Írj programot, amely egy (a programkódban) megadott méretű tömböt feltölt nullákkal!
2. Írj programot, amely összeadja egy egészeket tároló tömbben az összes elemet!
3. Írj programot, amely egy egészeket tároló tömb maximális elemét kiírja!
4. Írj programot, amely egy egészeket tároló tömb második legkisebb elemét írja ki!
5. Egészítsd ki a 2-es programot úgy, hogy legyen egy extra tömb, amely súlyokat határoz meg az elemekhez, és így számold ki az összeget! 
> - Pl. Első tömb: [1, 2, 3, 4, 5], második: [1, 1, 2, 3, 5], az összeg: 1\*1+1\*2+2\*3+3\*4+5\*5
6. Alakítsd át az előző feladatot úgy, hogy átlagot tudjon számolni! (Tudjon lebegőpontos súlyokkal is számolni.)
7. Írj programot, amely két karaktersorozatról eldönti, hogy melyik van előrébb az abc-sorrendben!
8. Írj programot, amely bekér egy stringet (karaktertömböt) és megszámolja a karakterek számát.

### Opcionális feladatok

1. Írj programot, amely egy egészeket tároló tömbben kicseréli a legkisebb és a legnagyobb elemet!
2. Írj programot, amely bekér egy szöveget az alapértelmezett bemeneten és megszámolja a sorok számát.
3. Írj programot, amely meghatározza, hogy a beírt szóban hány mássalhangzó, illetve magánhangzó van! (Csak az angol abc betűit használjuk.)
4. Próbáld ki, hogy ha egy karaktertömbbe beolvasod az *árvíztűrőtükörfúrógép* szót, akkor hány byte-on tárolódik el!
5. Írj egy programot, amely egy egészeket tároló tömbről eldönti, hogy van-e benne két szám, amelyek barátságosak! Két szám barátságos, ha a pozitív, önmagánál kisebb osztóik összege a másik számmal egyezik (*pl. 220 és 284*).
6. Írj programot, amely a táblázatkezelő szoftverek oszlopnév-oszlopszám konvertálást elvégzi! (*A -> 1, Z -> 26, AA -> 27, ...*). A programban tetszőleges darab oszlopnév megadható, maximum 9 hosszú nevekre kell számítani.
> - Tipp: Tipp: megállási feltétel, ha nem betűt kaptunk.
7. Írj egy programot, amelyben létrehozol egy 101 elemű tömböt, feltöltöd random számokkal 0 és 999 közt, majd meghatározod a középső elemet! Középső elemnek a medián értéket tekintjük. Alakítsd át úgy, hogy 100 elemű tömbre is működjön!
> - Tipp: Tesztelhetjük először 11 illetve 10 hosszú tömbre, hogy könnyebb legyen ellenőrizni

### Gyakorló feladatok

1. Írj függvényt, amely kiírja a paraméterül átadott szó összes permutációját!
2. Írj egy függvényt, amely kiszámolja a paraméterül kapott tömb elemei hosszú oldalakból képezhető legnagyobb háromszög területét!
3. Írj programot, amely bekér egy stringet (karaktertömböt) és megszámolja a szavak számát. (Egyezzen a viselkedése a wc paranccsal!)
# Első gyakorlat

## Adminisztratív információk

### Linkek, kezdés

Email címem: dkszelethus <kukac> gmail <pont> com
Canvas oldal: https://canvas.elte.hu/courses/26083
A tárgy honlapja: https://gsd.web.elte.hu/cpp-en/
Az IKs tárgyhoz jegyzet (sok átfedéssel ezzel a kurzussal): https://people.inf.elte.hu/szelethus/LaTeX/cpp/cpp_book/cpp_book.pdf

Az órák hétfőnként 12:00tól 13:30ig tartanak.

### Követelmények

Az aktuális követelményeket a tárgy honlapján lehet megtalálni, itt lesznek a beadandók is kiírva! Külön kiemelendő, hogy az órákon az aktív részvétel szintén szempont, az aktív hallgatóknak felfelé kerekítjük majd a jegyet. Aktív részvételnek számíthat az is, amikor valaki csak a chatbe ír, de akár az is, ha órákon kívül a teams csoportban aktív, észrevételeket fogalmaz meg, kérdéseket tesz fel, más kérdéséhez hozzászól.

### Rólam

Én most másodéves MSc hallgató vagyok az ELTE informatikati karán, és a kutatásaimban a C++ statikus analízisével foglalkozok. Ezzel párhuzamosan dolgozok az Ericsonban, ahol a Clang fordítóprogram Static Analyzer modulját fejlesztem, többet között inicializálatlan változók felfedezésével, adatfolyam elemzéssel és hibaüzenet érthetőséggel foglalkozok.

## Bevezető

### A C++ előnyei

#### A C++ gyors

A C++ előnyeit sok ember sokféleképp szokta megfogalmazni. Az előadáson elhangzott, többek között, hogy a C++ legnagyobb erőssége a gyorsaság. Bár ez valóban igaz -- ugyanarra a problémára különböző nyelvekben írt ideális megoldások közül a C++ban írtak többnyire hatékonyabbak, ez a történet picit árnyaltabb.

A C++ egyik nagy erénye, hogy rengeteg eszközt az a programozó kezébe. Egyrészről sok programozási paradigmát (objektum orientált, generikus, procedurális, stb) támogat a nyelv, és ezeknek az ötvözését is lehetővé teszi. Másrészt, sokkal jobban átlátható egy C++ programban, hogy a különböző erőforrások, pl. memória, mikor kerül lefoglalásra és felszabadításra. Azonban a nagy hatalommal nagy felelőséggel is jár, ezeknek az eszközönek a rossz használata nehezen felfedezhető programozói hibákhoz, lassú programokhoz, és kusza programkódhoz vezethet.

#### A C++ kompatibilis a C nyelvvel

Az, hogy egy C kód lefordítható egy modern C++ fordítóval, óriási előnynek számított amikor a nyelv megjelent. Ez lehetőséve tette a már sok millió soros C kódbázissal rendelkező cégeket hogy váltsanak C++ra anélkül, hogy (túl sok) energiát fektessenek a meglévő kód átírásába. Ez bár segített abban, hogy C++ elterjedjen, de számos komprumisszummal is jár, hisz a C egy nem olyan biztonságos nyelv mint a C++. Ez főleg amiatt van, mert egy idiomatikus C++ kódban több programozói hibát el tud csípni a fordító, mint egy idiomatikus C kódban. Mivel a C kódnak is le kell tudnia fordulnia egy C++ fordítóval, gyakran engedni kell a biztonságosságból a kompatibilitás javára.

#### A C++ statikusan erősen típusos

A félév folyamán meglátjuk, hogy a C++ban egy erős statikus típusrendszer van. Ez azt jelenti, hogy még fordítási időben (azaz, amikor a fordítóprogram a futtatható állományt [.exe, .out] állít elő a mi kódunkból [.cpp, .h]) ki tud szűrni számos hibát. Bár ettől néha körülményesebb a C++ kód írása, számos kutatás támasztja alá hogy minél később kerül felfedezésre egy hiba, annak a javítása annak költségesebb, így ez a kényelmetlenség többnyire megtérül.

### A tárgy célja

Többek között a fenti okokból a C++ több nem intuitívnak tűnő megoldásokat alkalmaz, de ezek gyakran azt a célt szolgálják, hogy idiomatikus (és végederményében gyors, biztonságos) C++ kódot tudjunk írni. Lehetetlen küldetés egy félév alatt piacképes C++ tudást átadni, így a tárgynak is a fő célja az, hogy a C++ filozófiáját adja át, és kedved hozzon hozzá.

## Feljesztői környezet felállítása

### Windows

1. Látogassunk el a https://info.caesar.elte.hu/ címre, jelentkezzen be, kattintson bal oldalt az alapadatokra, és igényelje meg az interaktív belépést.

![image](https://user-images.githubusercontent.com/23276031/154069432-abb3c2b6-7878-4bcd-8a56-6129779b356e.png)

2. Töltsük le a PuTTy-ot: https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html
3. Indítsuk el, és a "Host Name (or IP address)" részbe írjuk a következőt: `<IIG azonosító>@<caesar.elte.hu>`

![image](https://user-images.githubusercontent.com/23276031/154070081-4dcd44ca-bfd3-4109-868e-167d3a0335e5.png)

4. Kattintsunk az 'Open' gombra, fogadjuk el az figyelmeztető üzenetet, majd írjuk be a jelszavunkat. Akkor a kurzor nem fog mozogni, ettől még a billentyűleütéseket észleli a gép!

![image](https://user-images.githubusercontent.com/23276031/154446573-498e83e0-46ab-476e-9f31-c30f66247c36.png)

5. Nyomjunk entert, és ha minden jól ment, akkor bent is vagyunk a szerveren.

![image](https://user-images.githubusercontent.com/23276031/154446668-97d5918b-1b2e-4f71-9f50-398206117e2c.png)

6. Hozzunk létre egy új mappát `test` néven. Ezt az `mkdir` paranccsal lehet megtenni. Lépjünk be ebbe a mappába a `cd` paranccsal. (Az `ls` paranccsal tudjuk megnézni a jelenlegi mappánk tartalmát)
<!--Megjegyzésképp, a terminálba kiadandó parancsokat `$` jellel szokás kezdeni kódpéldában, ezt ti ne írjátok be.-->

```lang=bash
~$ mkdir test
~$ cd test
```

![image](https://user-images.githubusercontent.com/23276031/154481116-b596ae35-3a26-4c91-8c4a-4402ec2e7c57.png)

7. Nyissunk meg egy új fájlt `test.cpp` néven a `nano` text editor programmal. A `nano` egy olyan szövegszerksztő program, melyet a terminálból tudunk használni. Talán szokatlan módon, az egér itt nem használható, tehát a nyilakkal tudunk csak navigálni. A szövegszerkesztő allján megtekinthetőek milyen parancsok hajthatók végre. A kalap karakter a CTRL billentyűre hivatkozik, pl. a fájlt a CTRL+O billentyűkombinációval tudjuk lementeni.

```lang=bash
~/test$ nano test.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154482579-f4ad1a90-c1d5-48fa-b8ef-9968ff8798f2.png)

8. Másoljuk be az alábbi kódot. Windows a terminálba gyakran ezt az egéren a jobb klikk gombbal lehet megtenni (igen, komolyan). Linuxon (talán Mac-en is), a CTRL+SHIFT+V fog szöveget beszúrni a vágólapról.

```lang=c++
#include <iostream>

int main() {
  std::cout << "Hello world!";
}
```

9. Mentsük le (CTRL+O) ezt a fájlt, majd lépjünk ki a nano-ból (CTRL+X).
10. Fordítsuk le ezt a fájlt a `g++` nevű programmal. Ellenőrizzük, hogy valóban létrejött egy futtatható állomány az `ls` parancs segítségével. Ezután, futtassuk a programot úgy, hogy hivatkozunk a saját mappánkra, amelyet mindig a ponttal tehetünk meg (`.`), és ezen a mappán belül (`./`) megadjuk a létrejött generált fájl nevét (`./a.out`).

```lang=bash

~/test$ g++ test.cpp
~/test$ ls
~/test$ ./a.out
```

![image](https://user-images.githubusercontent.com/23276031/154488639-1d1236d3-1a6a-4afb-861c-863300e6dc02.png)
  
### Linux, Mac gépeken
  
1. Nyiss meg egy terminált
2. A 6. ponttal kezdve folytassátok a fenti lépéseket.

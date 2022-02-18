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

## Röviden a hello world programról

Amikor egy új programozási nyelvről tanulunk, az első feladat gyakran az, hogy kiírjuk valamilyen felületre a "Hello World" szöveget. Ezt C++ban az előbb látott kóddal tehetjük meg:

```lang=c++
#include <iostream>

int main() {
  std::cout << "Hello world!";
}
```

### A preprocesszor működése

A "Hello World" program első sora a `#inclued <iostream>`. Azok a sorok, melyek `#` jellel kezdődnek, a preprocesszornak szólnak, így a `#include` is egy preprocesszor parancs, vagy un. preprocesszor direktíva.

A fordítás (amikor a fordítóprogram a kódunkból a processzor számára érthető, futtatható állományt hoz létre) több lépésből áll, melyből a legelső a preprocesszor futtatása. A preprocesszálás, vagy "előszerkesztés" a fordítási folyamat első lépése. A preprocsszor egy nyelvfüggetlen, primitív eszköz, emiatt sok veszélyt hordoz magában.

#### Preprocesszor makrók

A preprocesszor segítségével lehet szöveget behelyettesíteni makrók segítségével. Makrót a `#define` direktívával tudunk definiálni, melynek az első argumentuma a makró neve, az összes többi pedig az, amire a makrót cserélni kell.

Legyen a `preproc.cpp` tartalma:
```lang=c++
#define ALMA 6

ALMA ALMA ALMA
```

Futtassuk a fordítóprogramot, de kérjük meg az `-E` kapcsoló segítéségével, hogy csak a preprocesszálást végezze el:

```lang=bash
$ g++ -E preproc.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154660847-81749d14-014b-46db-9940-b3d2d8d37ba9.png)

A kimenet utolsó sora a lényeg (a többi a preprocesszor működésével kapcsolatos információkat tárolnak, ezekre szükség lehet hogy a fordító pontosabb hibaüzeneteket tudjon adni, de most hagyjuk őekt figyelmen kívül), melyben feltűnhet, hogy a 3 darab `ALMA` szót a preprocesszor `6`-ra cserélte. Nem szükséges egyébként a `#define` első argumentumán kívül mást megadni, ebben az esetben a makrót egy üres szövegre ("semmire") cseréljük.

#### Elágazások a preprocesszorban

Elágazást is hozhatunk létre a preprocesszorban, függően attól, hogy egy makró definiálva van-e, tegyük ezt a `preproc2.cpp` fájlba:

```lang=c++
#define KORTE

#ifdef KORTE
Hello world!
#endif
```

A fenti kódban definiálunk egy új makrót, `KORTE`-t. Utána, amennyiben a `KORTE` makró definiálva van, akkor az elágazást eleje (`#ifdef KORTE`) és vége (`#endif`) közötti szöveget a preprocesszor beilleszti a fájlba, különben nem:

```lang=bash
$ g++ -E preproc2.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154663313-89c923c6-2afa-473f-9a88-41725f648e44.png)

Ha nincs definiálva a makró, akkor a preprocesszor direktívák álltal közrefogott szöveg nem kerül beillesztésre:


```lang=c++
#ifdef KORTE
Hello world!
#endif
```

```lang=bash
$ g++ -E preproc2.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154663595-c35a0914-c32f-4332-8f85-14e57eac6324.png)

Az elágazás eddig azt a gondolatot valósította meg, hogy "Ha ez a makró definiálva volt, akkor kerüljön ez a szövegrész beillesztésre". Van lehetőség ennek a negáltjára is, az `#ifndef` direktíva segítségével, ennek segítségével akkor lesz beillesztve egy szöveg, ha **nem** volt a makró definiálva.

```lang=c++
#ifndef KORTE
Hello world!
#endif
```

```lang=bash
$ g++ -E preproc2.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154663313-89c923c6-2afa-473f-9a88-41725f648e44.png)

Ezek segítségével kifejezhetjük azt is, hogy "Ha ez a makró definiálva volt, akkor kerüljön ez a szövegrész beillesztésre, különben kerüljön inkább ez". Kerüljön ez a `preproc_else.cpp` fájlba:

```lang=c++
#ifdef KORTE
KORTE definiálva!
#endif

#ifndef KORTE
KORTE nincs definiálva!
#endif
```

```lang=bash
$ g++ -E preproc_else.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154665214-fb945187-2d5e-48ca-a5ff-8c83e73bb489.png)

Ezt lerövödíthetjük az `#else` direktíva segítségével. Az `#else` és az `#endif` direktívák álltal közrefogott szöveg akkor kerül beillesztésre, ha az `#ifdef` vagy `#ifndef` (vagy a jelenlegi jegyzetben nem taglalt `#if`) direktívák feltétele nem teljesült.

```lang=c++
#ifdef KORTE
KORTE definiálva!
#else
KORTE nincs definiálva!
#endif
```

```lang=bash
$ g++ -E preproc_else.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154665214-fb945187-2d5e-48ca-a5ff-8c83e73bb489.png)

Ha definiáljuk a KORTE-t, akkor meglepetés érhet minket, hisz csak annyit látunk az utolsó sorban, hogy ` definiálva!`. Ennek az oka az, hogy a `KORTE` makró definiálva volt, így behelyettesítésre került (a helyére került egy üres szöveg).

```lang=c++
#define KORTE

#ifdef KORTE
KORTE definiálva!
#else
KORTE nincs definiálva!
#endif
```

```lang=bash
$ g++ -E preproc_else.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154666333-d2e50d02-0e1c-480a-aafc-c203adf6c1a6.png)

A meglevő tudásunkkal kifejezhetjük azt is, hogy "Ha a KORTE makró definiálva volt, akkor kerüljön ez a szövegrész beillesztésre, ha nincs, de az ALMA igen, akkor ez, különben pedig ez". Figyeljünk arra is, hogy behelyettesítés (mint azt az előző példában is láttunk) ne következzen be.

```lang=c++
#define ALMA

#ifdef KORTE
Korte definiálva!
#else
  #ifdef ALMA
  Korte nincs definiálva, de Alma igen!
  #else
  Se a Korte se az Alma nincs definiálva!
  #endif
#endif
```

```lang=bash
$ g++ -E preproc_else.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154668147-c320a2d1-d8e7-419a-9807-9231700ae058.png)

#### Fájl beillesztés a preprocesszorral

Ezzel eljutottunk a `#include` direktíváig. Ennek segítségével az arugmentumként megadott fájl tartalmát beilleszti a preprocesszor. Hozzunk létre egy új fájlt `header.h` néven:

```lang=c++
Header fájl!
```

Valamint egy új fájlt `preproc_include.cpp` néven:

```lang=c++
#include "header.h"

Cpp fájl!
```

Mivel a `preproc_include.cpp` fájl explicit módon megnevezi a billesztendő fájlt, elegendő csupán ezt a fájlt megadni a preprocesszornak:

```lang=bash
$ g++ -E preproc_include.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154682911-13039694-1ae9-45b1-9fb1-703687b5bc52.png)

Megfigyelhetjük, hogy a preprocesszor összeszerkesztette a `header.h` és `preproc_include.cpp` fájlokat. Ha többször használjuk ezt a direktívát, akkor többször tudjuk egy fájl tartalmát beilleszteni:

`preproc_include.cpp`:
```lang=c++
#include "header.h"
#include "header.h"
#include "header.h"
#include "header.h"

Cpp fájl!
```

```lang=bash
$ g++ -E preproc_include.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154683689-c71050b6-5c1d-499d-b5ad-7aebace4ebf3.png)

  Ez nem csak szándékosan követhet be. Amennyiben egy fájlba be`#include`oljuk `A` fájlt és `B` fájlt, és mindkettő be`#include`olja `C` fájlt, akkor a preprocesszor kétszer fogja beilleszteni a `C` fájlt. Valós C++ projektekben ha ez még nem is okoz fordítási hibát, akkor is lassíthatja a fordítás többi lépését (hisz több kódot kell majd beolvasni és feldolgozni). A preprocesszor az `#include` direktívák által meghatározott fájlok tranzitív lezártját adja vissza. 

![image](https://user-images.githubusercontent.com/23276031/154685771-775009fa-0894-4d13-acc6-1fd624a68354.png)

A fájl többszöri beillesztésénél súlyosabb hiba, ha az `#include` gráfban kör jelenik meg:

`header.h`:
```lang=c++
#include "preproc.cpp"

Header fájl!
```

`preproc_include.cpp`:

```lang=c++
#include "header.h"

Cpp fájl!
```

![image](https://user-images.githubusercontent.com/23276031/154686160-ce174fcf-782a-4866-bce8-7bfd92ddd223.png)

```lang=bash
$ g++ -E preproc_include.cpp
```

A kimenetben láthatjuk hogy a beillesztés egyik fájlról ugrik a másikra. Ha feljebb tekerünk, látni fogjuk hogy a fordítás nem volt sikeres, kapunk egy errort:

![image](https://user-images.githubusercontent.com/23276031/154686387-7ae9dba6-3567-42b7-89fd-b3b4155d06b1.png)

#### Header guard

Ezen hibák kiküszöbölésére, összetehetjük az eddig megszerzett tudásunkat, hogy egy már beillesztésre került fájl ne kerüljön beillesztésre mégegyszer. Ezt egy un. _header guard_-al fogjuk elérni.

`header.h`:
```lang=c++
#ifndef HEADER_H
#define HEADER_H

Header fájl!

#endif
```

A `header.h` első és utolsó sora által közrefogott szöveg akkor kerül beillesztésre, ha a `HEADER_H` makró **nincs** definiálva (konvenció szerint a makró neve a fájl nevére szokott hasonlítani). Ebben a részben viszont definiáljuk a `HEADER_H` makrót, így ha mégegyszer be szeretnánk illeszteni a fájl tartalmát, akkor az `#ifndef` feltétele nem fog teljesülni, és a benne levő tartalom se kerül beillesztésre.

`preproc_include.cpp`:

```lang=c++
#include "header.h"
#include "header.h"
#include "header.h"
#include "header.h"

Cpp fájl!
```

```lang=bash
$ g++ -E preproc_include.cpp
```

![image](https://user-images.githubusercontent.com/23276031/154690662-a1289847-2d0c-41ec-95fd-5f1fe6a76122.png)

A header guard ideális esetben a beillesztendő fájl teljes tartalmát tartalmazza.

#### Miért írunk `<iostream>`-et, és miért nem `"iostream"`-et? És mi az az `iostream`?

Korábban megneveztük azt a fájl, amelyet be akartunk illeszteni a `#include` direktíva segítségével. Nem kellett a _abszolút_ útvonalat megadni (pl. `C:\Users\Szelethus\Documents\cpp\header.h`, vagy a ceasar szerveren `/afs/elte.hu/user/s/szelethus/home/header.h`), mert a direktívát tartalmazó fájl és a billesztendő fájl egy mappában volt, így elég volt a _relatív_ útvonalat megadni (a jelenlegi mappához képest hol található a fájl). `iostream` nevű fájl azonban nincs itt, mi a trükk?

A trükk az, hogy a `g++` alapértelmezett konfigurációjában meg van adva, hogy ez a fájl hol található. Ezt a következő képen láthatjuk, de ebbe nem célszerű elmerülni, csupán demonstrálja hogy a fájl valahol valóban létezik:
![image](https://user-images.githubusercontent.com/23276031/154692445-e26111b1-bad7-43af-829f-028df9be1660.png)

Többek között ebben a mappában található a _standard könyvtár_ header fájljai (ez sem lényeges hogy hol van, természtesen):
![image](https://user-images.githubusercontent.com/23276031/154692604-01d7b13e-7c36-47dc-af31-54b76cd94604.png)

A standard könyvtárban számos függvény, változó és osztály található, melyeknek köszönhetően nem kell teljesen nulláról kezdenünk egy program megírását. Az `iostream` is ilyen, az "io" az "input/output"-re utal, a "stream" meg azokra az osztályokra és változókra, amik segítségével az adatok ki/be "folynak" a programba/programból. Többek között ebben a könyvtárban található az `std::cout` változó is.

### Változók, típusrendszer

Az előző részben a fordítás első részéről beszéltünk, a processzorrol, ami egy _nyelvfüggetlen_ eszköz. Ezt demonstrálta az, hogy nem is C++ kódot szerkesztettünk össze vele, hanem tetszőleges szövegeket. Innentől kezdve azonban áttérünk C++ra.

#### Változók

Világos, hogy programunkban szükség lesz adatok eltárolására. Példaképp, ha egy algorithmussal meg akarjuk számolni hogy egy szóban hány mássalhangzó van, ezt a számot legalább el kell tárolnunk valahol. Ha ezt számítógép nélkül tesszük, lehet ez az adathordozó a kezünk: szorítsuk ökölbe a kezünket, majd nézzük meg a szó első betűjét, ha az mássalhanzó, nyújtsuk ki az egyik ujjunkat. Ezután nézzük meg a második betűt, stb. Ebben a kis példában a kezünk a változó, melynek az "értéke" változik.

A programunkban ez a változó a számítógép memóriájában lesz kis szelet. Aki programozott már pythonban, annak ismerős lehet hogyan kell ott változókat létrehozni:

```lang=python
counter = 0
```


<!---
### Függvények a C++ban


#### A `main` függvény

C++ban, a lefordított program végrehajtása a `main` függvény első sorával kezdődik, és annak az utolsó sorával fejeződik be (ez nem _teljesen_ igaz, hisz a legelső lépés a globálsi változók inicializációja és a `main` függvény argumentumainak kiértékelése, de ezekről később beszélünk, így első lépésként állapodjunk meg ebben a féligazságban). 
->

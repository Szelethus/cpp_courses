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

1. Látogassunk el a https://info.caesar.elte.hu/ címre, jelentkezzen be, kattintson bal oldalt az alapadatokra, és igényelje meg az interaktív belépést.

![image](https://user-images.githubusercontent.com/23276031/154069432-abb3c2b6-7878-4bcd-8a56-6129779b356e.png)

2. Töltsük le a PuTTy-ot: https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html
3. Indítsuk el, és a "Host Name (or IP address)" részbe írjuk a következőt: `<IIG azonosító>@<caesar.elte.hu>`

![image](https://user-images.githubusercontent.com/23276031/154070081-4dcd44ca-bfd3-4109-868e-167d3a0335e5.png)

4. Kattintsunk az 'Open' gombra, fogadjuk el az figyelmeztető üzenetet, majd írjuk be a jelszavunkat. Akkor a kurzor nem fog mozogni, ettől még a billentyűleütéseket észleli a gép!



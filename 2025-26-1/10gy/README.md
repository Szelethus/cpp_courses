# Nyócadik gyakorlat

## Eddig kimaradt:
### signed, unsigned
### int pi = 3, 14;
#### Memóriacímet is másolni kell
#### Copy elision, By-value optimization
### https://en.cppreference.com/w/cpp/language/operator_precedence
### NULL vs std::nullptr
### Nem konstans char pointer literálra
### nullptr delete

## set
### Piros-fekete fa
### példa: uniquing, rendezés => memóriacím hibalehetőség
### Törlés, beszúrás
### iterátor mindig konstans
### find(), konténer specifikus műveletek
### Point: x szerinti rendezés csapda

-------------------------------
## Funktorok
### Függvény pointerek általánosításai

### Operátorok: X×Y->Z
### Predikátumok: T->Bool (unáris) X×Y->Bool (bináris)
### A == B <=> ~Pred(A, B) and ~Pred(B, A)

### Környezetfüggetlenség

### Unary predicate példa: template find függvény

-------------------------------
#### beszúrás meghiúsul, find mégis visszatér
### String: C++ Java, Haskell, GOD
#### GOD nincs beszúrva, mégis azt mondja van ilyen
#### Ekvivalencia osztály: szimmetrikus, reflexív és tranzitív
#### gyenge rendezés: <=
##### Elvesztjük az ekvivalenciát
### Ekvivalencia != egyenlőség (==)

-------------------------------

### map
#### std::pair
#### uniquing, rendezés
#### operator[]
##### default konstruál
##### nem konstans
#### iterator pair-t ad vissza
#### insert, std::make_pair

-------------------------------

## Algoritmusok
### findSecond(VectIt begin, VectIt end, const int &v)
#### vector<int> második eleme
#### vector<T>
#### tetszőleges iterátor
### Iterátor kategóriák
#### input, forward, bidirectional, random access
##### int-re hogy működik?
#### std::advance
#### List iterátorosítása

### find, find_if
#### ADL
#### speciális függvényeket (pl. set::find) célszerű preferálni
#### EKVIVALENCIA MÁS

## sort
### nem tudjuk előre a végeredményt véletlenül?
### std::set-be rakás
#### vector::assign
### ekvivalens elemek sorrendje
### stable_sort

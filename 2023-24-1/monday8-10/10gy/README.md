# Tízedikedik gyakorlat

### set
#### Egyedi elemek
#### rendezett

-------------------------------

## Funktorok
### Függvény pointerek általánosításai

### Operátorok: X×Y->Z
### Predikátumok: T->Bool (unáris) X×Y->Bool (bináris)
### A == B <=> ~Pred(A, B) and ~Pred(B, A)

### Környezetfüggetlenség

### Unary predicate példa: template printIf függvény

-------------------------------

## set
### Piros-fekete fa
### példa: uniquing, rendezés => memóriacím hibalehetőség
### Törlés, beszúrás
### iterátor mindig konstans
### find(), konténer specifikus műveletek
### Point: x szerinti rendezés csapda
#### beszúrás meghiúsul, find mégis visszatér
### String: C++ Java, Haskell, GOD
#### GOD nincs beszúrva, mégis azt mondja van ilyen
#### Ekvivalencia osztály: szimmetrikus, reflexív és tranzitív
#### gyenge rendezés: <=
##### Elvesztjük az ekvivalenciát
### Ekvivalencia != egyenlőség (==)

## list
### Elmélet vs gyakorlat
### iterátor léptetés -> nem random access
### splice

-------------------------------

### map
#### std::pair
#### uniquing, rendezés
#### operator[]
##### default konstruál
##### nem konstans, helyette find kell
#### iterator pair-t ad vissza

-------------------------------

## Algoritmusok
### findSecond(VectIt begin, VectIt end, const int &v)
#### vector<int> második eleme
#### vector<T>
#### tetszőleges iterátor
### Iterátor kategóriák
#### input, forward, bidirectional, random access
#### std::advance
#### List iterátorosítása

### find, find_if
#### speciális függvényeket célszerű preferálni
#### EKVIVALENCIA MÁS

## sort
### nem tudjuk előre a végeredményt véletlenül?
### std::set-be rakás
#### vector::assign

## partition, stable_partition, partition_point, is_partitioned

## std::remove
### size megnézése
### hasonlít a partitionra

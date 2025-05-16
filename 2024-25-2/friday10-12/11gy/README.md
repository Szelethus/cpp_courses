# 111111111111111111111111111111111111

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
#### beszúrás meghiúsul, find mégis megtalálja
### String: C++ Java, Haskell, GOD
#### GOD nincs beszúrva, mégis azt mondja van ilyen
#### Ekvivalencia osztály: szimmetrikus, reflexív és tranzitív
#### gyenge rendezés: <=
##### Elvesztjük az ekvivalenciát
### Ekvivalencia != egyenlőség (==)

-------------------------------

## Algoritmusok

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

## partition, stable_partition, partition_point, is_partitioned

## std::remove
### size megnézése
### hasonlít a partitionra

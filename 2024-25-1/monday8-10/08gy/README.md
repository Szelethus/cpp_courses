# Nyócadik ekszörszájz

## Fordítás sebessége, iosfwd
### Print -> operator<<

## List -> List <T>
### ConstIterator visszatérési értéke

## STL
### Konténerek: szekvenciális, asszociatív, konténer adapter
### Nincs pontos definíció, de bizonyos követelmények igen

-------------------------------
### vector
#### operator[], iterator, auto, foreach
#### Kapacitás, méret
#### iterátor invalidáció
##### Páratlanok törlése
##### 6 elem, 7 elem

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
##### nem konstans
#### iterator pair-t ad vissza


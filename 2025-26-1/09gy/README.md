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

## Mi az az allocator template paraméter?
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

## list
### Elmélet vs gyakorlat
### iterátor léptetés -> nem random access

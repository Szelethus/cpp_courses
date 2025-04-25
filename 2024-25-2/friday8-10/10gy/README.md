# 10 lekcsör

## Fájlra szétbontás 
## Fordítás sebessége, iosfwd
### Print -> operator<<

## Typedef, using
### detail::iterator

## STL
### Konténerek: szekvenciális, asszociatív, konténer adapter
### Nincs pontos definíció, de bizonyos követelmények igen

## Mi az az allocator template paraméter?
### vector
#### operator[], at(), iterator, auto, foreach
#### Kapacitás, méret
#### iterátor invalidáció
##### Páratlanok törlése
##### 6 elem, 7 elem
#### push_back és ctor elkefélés

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

## list
### Elmélet vs gyakorlat
### iterátor léptetés -> nem random access

# Hétedikedik ekszörszájz

## Fájlra szétbontás (folyt)
## Fordítás sebessége, iosfwd
### Print -> operator<<

## Typedef, using
### detail::iterator

## Template: példányosítás
### Template paraméter fajták
### Fordítási időben ismertnek kell lenni
### Default template paraméter
### Template parameter deduction
#### Array length

## Osztály template
### Templateek lustasága
#### Template template paraméter

## Template specializáció: factorial
### std::vector<bool>
### Factorial

## Dependent scope

## List -> List <T>
### ConstIterator visszatérési értéke

## STL
### Konténerek: szekvenciális, asszociatív, konténer adapter
### Nincs pontos definíció, de bizonyos követelmények igen

### vector
#### Konténer végére rendkívül hatékony
#### Random access
#### operator[], iterator, auto, foreach
#### Kapacitás, méret
#### hátulra beszúrás és törlés amortizált konstans
#### Minden más helyre lassú
#### iterátor invalidáció
##### Páratlanok törlése
##### 6 elem, 7 elem

### dequeue

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
##### nem konstans
#### iterator pair-t ad vissza

-------------------------------

## Algoritmusok
### find átalakítása
### Iterátor kategóriák
#### input, forward, bidirectional, random access
#### std::advance

### find, find_if
#### speciális függvényeket célszerű preferálni
#### EKVIVALENCIA MÁS

### sort és stable_sort
#### std::set-be rakás
#### std::sort


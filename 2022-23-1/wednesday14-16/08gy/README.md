# Nyócadik gyakorlat

## Template List

## STL
### Konténerek: szekvenciális, asszociatív, konténer adapter
### Nincs pontos definíció, de bizonyos követelmények igen
### A google egy fontos skill

### vector
#### Konténer végére rendkívül hatékony
#### Random access
#### operator[], iterator, auto, foreach
#### Kapacitás, méret
#### hátulra beszúrás és törlés amortizált konstans
#### Minden más helyre lassú
#### iterátor invalidáció
##### Páratlanok törlése

### dequeue

### set
#### Egyedi elemek
#### rendezett

-------------------------------

## Funktorok
### Függvény pointerek általánosításai

### Operátorok: X×Y->Z
### Predikátumok: T->Bool (unáris) X×Y->Bool (bináris)

### Környezetfüggetlenség

### template printIf függvény
### template find függvény

-------------------------------

### set
#### Ekvivalencia
#### Piros-fekete fa
#### példa: uniquing, rendezés

================ eddig jutottunk el ========================

#### find(), konténer specifikus műveletek
#### Point: x szerinti rendezés csapda
#### String: C++ Java, Haskell, GOD
##### GOD nincs beszúrva, mégis azt mondja van ilyen
##### Ekvivalencia osztály
##### gyenge rendezés: <=
###### Elvesztjük az ekvivalenciát (count() soha nem tér vissza igazzal)
#### Ekvivalencia != egyenlőség (==)

### list
#### Elmélet vs gyakorlat
#### iterátor léptetés
#### splice

-------------------------------

### map
#### uniquing, rendezés
#### operator[]
##### default konstruál
##### nem konstans
#### iterator pair-t ad vissza

### Iterátor kategóriák
### input, forward, bidirectional, random access

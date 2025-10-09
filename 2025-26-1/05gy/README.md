
### signed, unsigned
### int pi = 3, 14;
### 0,1-enként emelkedő ciklus
#### Memóriacímet is másolni kell
#### Copy elision, By-value optimization
### https://en.cppreference.com/w/cpp/language/operator_precedence
### NULL vs std::nullptr
### Nem konstans char pointer literálra
### nullptr delete
### add "egyszerűsítése"


### Compiler generated methods
#### Konstruktor
##### default konstruktor
##### C++11 explicit default konstruktor hívás

##### Temporálisok
###### Név nélküli temporálisok
###### Temporálisok + const&
###### Literálok is ilyenek, csak nem változók

#### Destruktor
##### RAII
##### Általánosabb megoldás a garbage collectionre, sőt, garbage nem is keletkezik

#### Copy konstruktor (shallow, deep copy)
#### Értékadó operátor
##### Kell egy free is
##### return *this
##### self assignment
##### Miért nem konstans referenciával térünk vissza

### Rule of 3
### Reguláris típus, félig reguláris típus
### Design philosophy: Make it easy to use corrently, and hard to use incorrectly

## Láthatóság
### Head védése
### Node védése (majd vissza)
### free() védelme

## Iterátorok
### Tömböknél pointer
#### ++ -- + - * == !=
### Pointerek általánosítása
### class forward declaration
#### incomplete type
### Prefix++

## Konstans metódusok

## Print átírása, kiemelése
### Konstans referencia paraméter

## Konstans iterátor
### Konstans iterátor <- Iterátor
### Konverziós konstruktor
### Explicit konstruktor: List l = nullptr



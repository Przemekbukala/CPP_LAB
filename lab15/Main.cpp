/*
Tematem zadania sa szablony funkcji. Funkcje szablonowe moga byc metodami i moga byc statyczne. 

W zadaniu nalezy napisac prosta klase Punkt. Klasa ta ma przechowywac dwa skladniki (wsp. punktu typu int).
Posiada metode dostepowa wsp, ktora jest szablonowa i pozwala na dostanie sie
do wsp. x lub y w przy arg szablonowy 0 i 1 odpowiednio.

Dwa obiekty kl. Punkt mozna porownywac <. Najpierw porownywane sa wsp. x a wsp. y tylko gdy x-owe sa rowne.
W sklad klasy wchodza tez metody statyczne min i max. Rzecz jednak polega na tym aby zaprogramowac je w sposob ogolny, tak by dzialaly dla klasy Punkt i dla typow prostych.
Uwaga na poprawnosc const!

Jak można rozszerzyć ten temat o szablon klasy? Chodzi o ogólniejszą wersję klasy Punkt.
Czy można zaproponować klasę szablonową Wektor<T>, która wykorzystuje klasę Punkt<T>?*/



#include <iostream>
#include "Punkt.h" 

int main() { 
const Punkt s1(0, 1); 
const Punkt s2(-5, 2); 

std::cout << "s1: " << s1.wsp<0>() << " " << s1.wsp<1>() << std::endl; 
std::cout << "s2: " << s2.wsp<0>() << " " << s2.wsp<1>() << std::endl; 

std::cout << Punkt::min(s1.wsp<0>(), s2.wsp<0>()) << " " << Punkt::min(s1.wsp<1>(), s2.wsp<1>()) << std::endl; 
std::cout << Punkt::max(s1.wsp<0>(), s2.wsp<0>()) << " " << Punkt::max(s1.wsp<1>(), s2.wsp<1>()) << std::endl; 

std::cout << Punkt::min(s1, s2).wsp<0>() << " " << Punkt::min(s1, s2).wsp<1>() << std::endl; 

std::cout << Punkt::max(s1, s2).wsp<0>() << " " << Punkt::max(s1, s2).wsp<1>() << std::endl; 

std::cout << "porownanie: " << (s1 < s2) << " " << (s2 < s1) << std::endl;

}


/* wynik
s1: 0 1
s2: -5 2
-5 1
0 2
-5 2
0 1
porownanie: 0 1
 */
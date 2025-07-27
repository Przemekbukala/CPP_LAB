/* 
Celem zadania jest napisanie polimorficznej listy przechowujacej dane jako wartosci.
----------------------------------------------------------------------------------------------------------------
Wymagania funkcjonalne i techniczne
    * Należy używać mechanizmu RTTI (typeid, type_info) do implementacji isType<T>().
    * Kod ma działać z różnymi typami (int, float, double, itp.).
    * Należy zadbać o poprawne zarządzanie pamięcią:
      - Destruktor klasy Node usuwa rekurencyjnie kolejne elementy (delete m_next;).
    * Struktura danych powinna umożliwiać dynamiczne sprawdzanie typu (isType<T>()) i rzutowanie (get<T>()).
    * Nie używać dynamic_cast w isType<T>(), ale typeid (to jest jedno z założeń zadania).

Struktura i definicje klas:
----------------------------------------------------------------------------------------------------------------
Node (klasa bazowa — abstrakcyjna)
-----------------------------------
Reprezentuje ogólny węzeł w liście. Przechowuje wskaźnik do następnego węzła i umożliwia dynamiczne sprawdzenie typu.
Wymagania:
    * wirtualny destruktor — musi sprzątać całą listę.
    * metodę next(), zwracającą wskaźnik do następnego węzła.
    * szablonową metodę isType<T>(), która sprawdza, czy typ bieżącego węzła to T, używając mechanizmu RTTI (typeid).
    * czysto wirtualną metodę isTypeRTTI(const std::type_info&) do obsługi dynamicznej identyfikacji typu.

TNode<T> (klasa szablonowa — dziedziczy po Node)
-----------------------------------
Reprezentuje konkretny węzeł przechowujący wartość typu T.
Wymagania:
    * Przechowuje konkretną wartość (T data).
    * Przesłania isTypeRTTI i porównuje typeid(T) z przekazanym typem.
    * Ma metodę get() zwracającą przechowywaną wartość.
    * Może być konstruowany z drugim węzłem (następnym węzłem w liście).

List (właściwa struktura danych — lista jednokierunkowa)
-----------------------------------
Przechowuje wskaźnik do głowy listy i umożliwia dodawanie elementów różnych typów.
Wymagania:
    * Konstruktor inicjuje pustą listę (nullptr).
    * Destruktor sprząta wszystkie węzły (poprzez delete m_head — zadziała dzięki wirtualnemu destruktorowi).
    * Szablonowa metoda add<T>(T v):
        - Dodaje nowy element na początek listy.
        - Może wykorzystywać konstruktor TNode<T>(v, m_head).
    * Szablonowa metoda statyczna get<T>(const Node*):
        - Zakłada, że Node zawiera typ T (sprawdza to przez isType<T>()).
        - Jeśli tak — wykonuje static_cast do TNode<T>* i zwraca wartość.
 */

#include <iostream>
#include "List.h"


int main() {
  using namespace std;
  std::cout << std::boolalpha;

  List al;
  al.add<int>(7);
  al.add<float>(4.56);    // dodaje na poczatku
  al.add<double>(4.566);  // to jest teraz pierwsza

  cout << al.head()->isType<float>()  << endl;
  cout << al.head()->isType<int>()  << endl;

  const TNode<double>* f = dynamic_cast<const TNode<double>*>( al.head() );
  if  ( f ) 
    cout << f->get() << endl;
  else {
    cout << " to nie int "  << endl;
  }
  cout << al.head()->next()->isType<float>()  << endl;
  cout << al.head()->next()->isType<int>()  << endl;
  cout << al.head()->next()->next()->isType<int>()  << endl;

  cout << List::get<double>(al.head()) << std::endl; // pierwszy jest double

  std::cout << std::noboolalpha;
  
}
/* wynik
false
false
4.566
true
false
true
4.566
 */

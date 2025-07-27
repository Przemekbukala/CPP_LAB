/*
Zadanie polega na implementacji serwisu BookingManager, który przechowuje informacje 
na temat rezerwacji: Imie Nazwisko, Data, Liczba noclegów.
W implementacji wykorzystaj std::tuple który jest szablonem klasy w C++, i pozwala przechowywać dowolną liczbę elementów o różnych typach, jako pojedynczy obiekt,
- jest to bardziej ogólny odpowiednik std::pair.
- std::tuple umożliwia budowę struktur danych bez potrzeby deklarowania własnych klas/struktur.

Wymagania:
* BookingManager zawiera atrybut Container m_bookings, gdzie Container jest zdefiniowanay z wykorzstaniem krotki (std::tuple)
* Metoda addBooking dodaje nowy element do m_bookings, ważne by typ parametru formalnego w addBooking był określony za pomocą booking_entry, 
  który z kolei jest zdefiniowany w projekcie za pomocą value_type
* Dodatkowo wykorzystaj w projekcie: std::for_each, std::sort
  https://en.cppreference.com/w/cpp/algorithm/for_each
  https://en.cppreference.com/w/cpp/algorithm/sort
* Do logowania wydruku wykorzystaj ideę typu Logger, który w ramach wzorców projektowych nazywamy singletonem.

Prosze zadbać o dobre zarzadzanie pamiecia.
Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
Struktura propramu powinna być oparta o definicję zawartą w pliku CMakeLists.txt

Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself

Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
ani żadnych innych materiałów

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab12/
* archiwum nie powinno zawierać katalogu build/

*/

#include "BookingManager.h"
#include <iostream>
#include <iomanip>

int main() {
    // Przykład manipulacji szerokością pola wydruku
    std::cout << std::left 
              << std::setw(16) << "John Walk"       
              << std::setw(16) << "2025-06-10"   
              << std::setw(4)  << "5"
              << std::endl;

    BookingManager manager;

    manager.addBooking({"John Doe", "2025-06-10", 3});
    manager.addBooking({"Alice Smith", "2025-06-08", 2});
    manager.addBooking({"Bob Lee", "2025-06-12", 1});

    manager.printBookings();
    manager.sortBookingsByDate();
    manager.printBookings();

    return 0;
}

/*
Oczekiwany wynik działania programu
John, 2025-06-10, 5
[INFO] Added booking for John Doe
[INFO] Added booking for Alice Smith
[INFO] Added booking for Bob Lee
Name: John Doe         Date: 2025-06-10   Nights: 3
Name: Alice Smith      Date: 2025-06-08   Nights: 2
Name: Bob Lee          Date: 2025-06-12   Nights: 1
[INFO] Bookings sorted by date.
Name: Alice Smith      Date: 2025-06-08   Nights: 2
Name: John Doe         Date: 2025-06-10   Nights: 3
Name: Bob Lee          Date: 2025-06-12   Nights: 1

*/

/*
Zadanie polega na rozwinięciu zadania z serwisem BookingManager, który przechowuje informacje 
na temat rezerwacji: Imie Nazwisko, Data, Liczba noclegów.
Rozwinięcie polega na zaimplementowaniu rozwiązania opartego o szablony funkcji w ramach namespace BookingUtils

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
#include "BookingUtils.h"
#include <iostream>
#include <iomanip>

int main() {
    BookingManager manager;

    manager.addBooking({"John Doe", "2025-06-10", 3});
    manager.addBooking({"Alice Smith", "2025-06-08", 2});
    manager.addBooking({"Bob Lee", "2025-06-12", 1});

    manager.printBookings();

    auto firstBooking = manager.getBookings().front();

    auto name = BookingUtils::extractField<0>(firstBooking);
    std::cout << "Name: " << name << "\n";

    auto date = BookingUtils::extractField<1>(firstBooking);
    std::cout << "Date: " << date << "\n";

    int nights = BookingUtils::extractField(firstBooking);
    std::cout << "Nights: " << nights << '\n';

    return 0;
}

/*
Oczekiwany wynik działania programu
[INFO] Added booking for John Doe
[INFO] Added booking for Alice Smith
[INFO] Added booking for Bob Lee
Name: John Doe         Date: 2025-06-10   Nights: 3
Name: Alice Smith      Date: 2025-06-08   Nights: 2
Name: Bob Lee          Date: 2025-06-12   Nights: 1
Name: John Doe
Date: 2025-06-10
Nights: 3
*/

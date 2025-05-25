
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
// Celem zadania jest zaimplementowanie uproszczonego systemu hotelowego.
// Zdefiniowanie odpowiednich klas, w tym klasy czysto wirtualnej IUser, która reprezentuje użytkownika systemu.
// Zbudowanie hierarchii dziedziczenia, w której Guest (gość hotelowy) i Staff (pracownik) dziedziczą z IUser, 
// a HotelMember dziedziczy po obu (tj. po Guest oraz Staff), wg schematu:
//     IUser
//     /     \
// Guest    Staff
//     \     /
// HotelMember

// Klasa HotelMember powinna umożliwiać zarówno rezerwację pokoju (makeReservation), 
// jak i jego obsługę (manageReservation), w zależności od roli użytkownika.
// Przechowywanie nazwy (np. Jan Kowalski) ma zawierać się w klasie IUser.


#include "HotelMember.h"

int main() {
    HotelMember guest("Jan Nowak", Type::GUEST);
    guest.printRole();
    guest.performRoleAction();
    std::cout << guest.getName() << std::endl;


    HotelMember staff("Jan Kowal", Type::STAFF);
    staff.printRole();
    staff.performRoleAction();
    std::cout << staff.getName() << std::endl;
    

    return 0;
}
/* wynik działania programu
[Info]: Jan Nowak (role: Guest)
[Info]: Jan Nowak is making reservation for: Room 401
Jan Nowak
[Info]: Jan Kowal (role: Staff)
[Info]: Jan Kowal is managing reservations.
Jan Kowal
*/
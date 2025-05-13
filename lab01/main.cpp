// 1. Bazową klasę `Shape`:
//    - Zawiera pole `name`, które przechowuje nazwę kształtu.
//    - Zawiera metodę wirtualną `Area()`, która zwraca pole powierzchni.
// 2. Klasy pochodne:
//    - `Rectangle`:
//        - Pola: `width`, `height`.
//        - Implementuje metodę `Area()` (prostokąt: width*height).
//        - Przeciąża operator `*` do skalowania wymiarów prostokąta.
//    - `Circle`:
//        - Pole: `radius`.
//        - Implementuje metodę `Area()` (koło: π * radius²).
//        - Przeciąża operator `+`, który pozwala dodawać promienie dwóch kół
//          i zwraca nowe koło o powiększonym promieniu.


#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

int main() {
    Rectangle rect("Rectangle", 4, 5);
    Circle circle1("Circle1", 3);
    Circle circle2("Circle2", 2);

    // Wypisanie informacji o kształtach
    std::cout << rect << "\n";
    std::cout << circle1 << "\n";
    std::cout << circle2 << "\n";

    // Obliczanie pól powierzchni
    std::cout << "Area of rect: " << rect.Area() << "\n";
    std::cout << "Area of circle1: " << circle1.Area() << "\n";

    // Skalowanie prostokąta
    rect = rect * 2;
    std::cout << "Scaled rect: " << rect << "\n";

    // Dodawanie promieni kół
    Circle circle3 = circle1 + circle2;
    std::cout << "Combined circle: " << circle3 << "\n";

    return 0;
}

/* Wynik działania programu:
Rectangle: Rectangle (width=4, height=5)
Circle: Circle1 (radius=3)
Circle: Circle2 (radius=2)
Area of rect: 20
Area of circle1: 28.2743
Scaled rect: Rectangle: Rectangle (width=8, height=10)
Combined circle: Circle: Combined (radius=5)
*/

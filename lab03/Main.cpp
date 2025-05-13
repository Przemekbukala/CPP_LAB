// Celem zadania jest zdefiniowanie struktury organizacji w firmie:
// Company -> Department -> Employee
// - Company przechowuje tablice Department
// - Department przechowuje tablice Employee
// - odpowiednie interfejsy proszę wywnioskować z treści funkcji main()
// - każda klasa powinna być zdefiniowana w osobnym pliku (.h, .cpp)
// UWAGA: Nie można korzystać z std::vector, std::array
//

#include "Employee.h"
#include "Department.h"
#include "Company.h"
#include <iostream>

int main() {
    // Dla ułatwienia, tworząc nową firmę z góry określamy liczbę działów
    // możliwych w firmie
    Company myCompany("TechCorp", 3);

    // Analogicznie, działy tworzymy określając maksymalną liczbę pracowników
    // możliwych do dodania w każdym z nich
    Department d1("IT",10);
    Department d2("HR",10);
    myCompany.addDepartment(d1);
    myCompany.addDepartment(d2);
    
    Employee e0("Nobody");
    
    // // Albo, pracownicy są przypisani do działu w momencie ich tworzenia
    Employee e1("Alice", &d1);  // Alice jest przypisana do IT
    Employee e2("Bob", &d1);    // Bob jest przypisany do IT
    Employee e3("Charlie", &d2);  // Charlie jest przypisany do HR

    myCompany.printDepartments();

    const Department& constDept = d1;
    constDept[0].printInfo();         // Dostep do pracownika w IT
    d1[0] = Employee("Robert", &d1);  // zastąpienie Alice w IT
    constDept[0].printInfo();

// Flaga zdefiniowana na poziomie CMakeLists.txt
// w celu testowania błędu kompilacji:
// cmake -DENABLE_ERROR_TEST=ON ..
#ifdef ENABLE_ERROR_TEST 
    d2.addEmployee("Anna");
#endif

    return 0;
}

/* Wynik działania programu:
Company: TechCorp departments:
- IT
- HR
Employee: Alice (Department: IT)
Employee: Robert (Department: IT)
*/

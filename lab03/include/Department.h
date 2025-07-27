#pragma once 
#include <string>
class Employee;

/**
 * @class Department
 * @brief Reprezentuje dział w firmie, który przechowuje tablicę wskaźników na pracowników.
 */
class Department{
    public:
    friend class Company;
    friend class Employee;
    /**
     * @brief konstruktor działu.
     * @param name Nazwa działu.
     * @param number Maksymalna liczba pracowników w dziale.
     */
    Department(std::string name="",int number=0):_department_name(name),_number_of_employees(number),_size(0){
        _tab=new Employee*[number];
    }

    /**
     * @brief Destruktor działu, zwalnia pamięć pracowników i tablicy.
     */
    ~Department(){
            for(int j=0;j<_size;j++){
                delete  _tab[j];
            }
            delete _tab;
        } 
     /**
     * @brief Operator indeksowania do odczytu pracownika na pozycji i.
     * @param i Indeks pracownika.
     * @return Referencja do pracownika (const Employee).
     */
    const Employee &operator[](int i)const{
        return *_tab[i];
    }

    /**
     * @brief Operator indeksowania do zapisu pracownika na pozycji i.
     * @param i Indeks pracownika.
     * @return Referencja do pracownika.
     */
    Employee &operator[](int i){
        return *_tab[i];
    }
      /**
     * @brief Dodaje pracownika do działu.
     * @param obj Referencja do obiektu Employee do dodania.
     */
    void addEmployee(Employee &obj);

    private:
    std::string _department_name;
    int _number_of_employees;
    Employee **_tab;
    int _size;
};
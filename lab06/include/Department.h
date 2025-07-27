#pragma once
/**
 * @class Department
 * @brief Abstrakcyjna klasa bazowa reprezentująca dział w uczelni.
 *
 * Klasa definiuje interfejs do wypisywania informacji o dziale.
 * Konstruktor i destruktor wypisują komunikaty o tworzeniu i usuwaniu działu.
 */
class Department{
    public:
        /**
     * @brief Konstruktor klasy Department.
     * Wypisuje informację o utworzeniu działu.
     */
    Department(){
        std::cout<<"Department Science created."<<std::endl;
    }
       /**
     * @brief Wirtualny destruktor klasy Department.
     * Wypisuje informację o usunięciu działu.
     */
    virtual ~Department(){
        std::cout<<"Department Science destroyed."<<std::endl;
    }
    /**
     * @brief Wirtualna metoda do wypisywania informacji o dziale.
     */
    virtual void print_info()const =0;
    private:
};

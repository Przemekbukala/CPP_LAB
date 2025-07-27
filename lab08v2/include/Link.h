#pragma once 
#include "FileSystemElement.h"
#include <string>
#include <iostream>

/**
 * @brief Klasa reprezentująca dowiązanie symboliczne (link).
 */
class Link : public FileSystemElement{
    public:
        /**
     * @brief Konstruktor dowiązania.
     * @param str nazwa linka
     * @param ptr wskaźnik do elementu.
     */
    Link(const char* str,FileSystemElement* ptr):_name(str),_ptr(ptr),_size(1),_date("01.05.2025"){}
        /**
     * @brief Wypisuje informacje o dowiązaniu.
     * @param o strumień wyjściowy
     * @param indent wcięcie
     * @param flaga dodatkowy parametr
     */
    void   printInfo(std::ostream& o, int indent=0,int flaga=0) const;
        /**
     * @brief Zwraca rozmiar dowiązania.
     * @return rozmiar
     */
    unsigned  get_size() const;
        /**
     * @brief Zwraca nazwę dowiązania.
     * @return nazwa
     */
    std::string get_name() const;
    private:
    std::string _name;
    FileSystemElement* _ptr;
    unsigned _size;
    // data utworzenia 
    std::string _date;
};
#pragma once
#include "FileSystemElement.h"
#include <string>
#include <iostream>
/**
 * @brief Klasa reprezentująca zwykły plik.
 */
class File : public FileSystemElement{
    public:
        /**
     * @brief Konstruktor pliku.
     * @param name nazwa pliku
     */
    File(const char* name):_name(name),_size(1),_date("01.05.2025"){}
        /**
     * @brief Wypisuje informacje o pliku.
     * @param o strumień wyjściowy
     * @param indent wcięcie
     * @param flaga dodatkowy parametr
     */
    void printInfo(std::ostream& o, int indent=0,int flaga=0) const;

    /**
     * @brief Zwraca rozmiar pliku.
     * @return rozmiar
     */
    unsigned  get_size() const;
        /**
     * @brief Zwraca nazwę pliku.
     * @return nazwa
     */
    std::string get_name() const;
    private:
    std::string _name;
    unsigned _size;
      // data utworzenia 
      std::string _date;
};
#pragma once
#include "FileSystemElement.h"
#include <string>
#include <iostream>
/**
 * @brief Klasa reprezentująca plik w systemie plików.
 */
class File : public FileSystemElement{
    public:
     /**
     * @brief Konstruktor pliku.
     * @param name nazwa pliku
     */
    File(const char* name):_name(name){}
    /**
     * @brief Wypisuje informacje o pliku.
     * @param o strumień wyjściowy
     * @param indent wcięcie
     */
    void print(std::ostream& o, int indent=0) const;
    private:
    std::string _name;
};
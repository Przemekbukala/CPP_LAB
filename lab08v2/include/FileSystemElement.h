#pragma once
#include <iostream>
#include <string>
/**
 * @brief Abstrakcyjna klasa bazowa reprezentująca dowolny element systemu plików.
 */
class FileSystemElement{
    public:
    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~FileSystemElement(){}
    /**
     * @brief Zwraca rozmiar elementu.
     * @return rozmiar elementu
     */
    unsigned virtual get_size() const=0;
    /**
     * @brief Zwraca nazwę elementu.
     * @return nazwa elementu
     */
    std::string virtual get_name() const=0;
        /**
     * @brief Wypisuje informacje o elemencie systemu plików.
     * @param o strumień wyjściowy
     * @param indent poziom wcięcia
     * @param flaga dodatkowy parametr informacyjny
     */
    void virtual  printInfo(std::ostream& o, int indent=0,int flaga=0) const=0;
};
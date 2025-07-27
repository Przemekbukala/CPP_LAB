#pragma once 
#include <iostream>

/**
 * @brief Klasa bazowa reprezentująca dział uczelni - abstrakcyjna.
 */
class Department{
    public:

    /**
     * @brief Wypisuje informacje o dziale.
     */
    void virtual info() const=0;
};
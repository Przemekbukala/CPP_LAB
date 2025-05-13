#pragma once
#include "FileSystemElement.h"
#include <string>
#include <iostream>
class File : public FileSystemElement{
    public:
    File(const char* name):FileSystemElement(name){}
    //Wypisanie informacje o dnaym obiekcie metoda przyjmuje  std::ostream& o , oraz parametr umożliwiający utowrznie wcięc (indent) 
    void printInfo(std::ostream& o, int indent=0) const;
        //metoda  umożliwijąca wypisanie nazwy 
    std::string  get_name() const;
};
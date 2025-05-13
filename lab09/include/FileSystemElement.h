#pragma once
#include <iostream>
#include <string>
class FileSystemElement{
    public:
    //virutalny destruktor 
    FileSystemElement(const std::string& name) : _name(name) {}
    virtual ~FileSystemElement(){}
    //metoda czysto wirtualna umożliwijąca wypisanie nazwy 
    std::string virtual get_name() const=0;
    //Wypisanie informacje o dnaym obiekcie metoda przyjmuje  std::ostream& o , oraz parametr umożliwiający utowrznie wcięc (indent) 
    void virtual  printInfo(std::ostream& o, int indent=0) const=0;
    protected:
    std::string _name;
};
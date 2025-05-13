#pragma once 
#include "FileSystemElement.h"
#include <string>
#include <iostream>
#include "File.h"
class Link : public File{
    public:
    Link(const char* str,FileSystemElement* ptr):File(str),_ptr(ptr){}
    //Wypisanie informacje o dnaym obiekcie metoda przyjmuje  std::ostream& o , oraz parametr umożliwiający utowrznie wcięc (indent) 
    void   printInfo(std::ostream& o, int indent=0) const;
        //metoda  umożliwijąca wypisanie nazwy 
    std::string get_name() const;
    //metoda umożliwiająca uzysaknie zawartości skladnika _ptr
    FileSystemElement* get_ptr() const;
    private:
    FileSystemElement* _ptr;
};
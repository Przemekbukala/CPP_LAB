#pragma once
#include <string>
#include <memory>
#include <vector>
#include "FileSystemElement.h"
#include "File.h"
class Dir: public FileSystemElement{
    public:
    //Konstruktor 
    Dir(const char* name):FileSystemElement(name){}
    //Przeładowany operator<< umozilwiajacy wypisawnie obiektow
    friend void operator<<(std::ostream &o, const FileSystemElement & obj);
    //Wypisanie informacje o dnaym obiekcie metoda przyjmuje  std::ostream& o , oraz parametr umożliwiający utowrznie wcięc (indent) 
    void  printInfo(std::ostream& o, int indent=0) const;
    // metoda umożliwiajaca dpodanie kolejnych elementów do składnika _tab.
    void add(std::unique_ptr<FileSystemElement> element);
    void printElementsInfo() const;
        //metoda  umożliwijąca wypisanie nazwy 
    std::string get_name() const;
    //metoda rm umozliwiajca usunięcie poszególnych elementów
    void rm(const char *name,bool flaga=false);
    private:
    std::vector <std::unique_ptr<FileSystemElement>> _tab;
};
inline void operator<<(std::ostream &o, const FileSystemElement & obj){
    obj.printInfo(o);
}
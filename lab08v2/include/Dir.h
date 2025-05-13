#pragma once
#include <string>
#include <memory>
#include <vector>
#include "FileSystemElement.h"
#include "File.h"
class Dir: public FileSystemElement{
    public:
        // domyslnie każdy objekt ma rozmier 1
    Dir(const char* name):_name(name),_size(1),_date("01.05.2025"){}
    friend void operator<<(std::ostream &o, const FileSystemElement & obj);
    void  printInfo(std::ostream& o, int indent=0,int flaga=0) const;
    void add(std::unique_ptr<FileSystemElement> element);
    void printElementsInfo() const;
    unsigned  get_size() const;
    std::string get_name() const;
    void ls() const;
    private:
    std::string _name;
    std::vector <std::unique_ptr<FileSystemElement>> _tab;
    unsigned _size;
      // data utworzenia 
      std::string _date;
};
inline void operator<<(std::ostream &o, const FileSystemElement & obj){
    obj.printInfo(o);
}
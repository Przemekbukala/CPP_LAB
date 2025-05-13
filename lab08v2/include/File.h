#pragma once
#include "FileSystemElement.h"
#include <string>
#include <iostream>
class File : public FileSystemElement{
    public:
        // domyslnie każdy objekt ma rozmier 1
    File(const char* name):_name(name),_size(1),_date("01.05.2025"){}
    void printInfo(std::ostream& o, int indent=0,int flaga=0) const;
    unsigned  get_size() const;
    std::string get_name() const;
    private:
    std::string _name;
    unsigned _size;
      // data utworzenia 
      std::string _date;
};
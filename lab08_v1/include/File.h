#pragma once
#include "FileSystemElement.h"
#include <string>
#include <iostream>
class File : public FileSystemElement{
    public:
    File(const char* name):_name(name){}
    void print(std::ostream& o, int indent=0) const;
    private:
    std::string _name;
};
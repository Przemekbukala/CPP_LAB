#pragma once
#include <iostream>
#include <string>
class FileSystemElement{
    public:
    virtual ~FileSystemElement(){}
    unsigned virtual get_size() const=0;
    std::string virtual get_name() const=0;
    void virtual  printInfo(std::ostream& o, int indent=0,int flaga=0) const=0;
};
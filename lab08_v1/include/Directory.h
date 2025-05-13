#pragma once
#include <string>
#include <memory>
#include <vector>
#include "FileSystemElement.h"
#include "File.h"
class Directory: public FileSystemElement{
    public:
    Directory(const char* name):_name(name){}
    void  print(std::ostream& o, int indent=0) const;
    void add(std::unique_ptr<FileSystemElement> element);
    private:
    std::string _name;
    std::vector <std::unique_ptr<FileSystemElement>> _tab;
};
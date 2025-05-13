#pragma once
class FileSystemElement{
    public:
    virtual ~FileSystemElement(){}
    void virtual  print(std::ostream& o, int indent=0) const=0;
};
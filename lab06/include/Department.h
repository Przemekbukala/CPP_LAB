#pragma once
class Department{
    public:
    Department(){
        std::cout<<"Department Science created."<<std::endl;
    }
    virtual ~Department(){
        std::cout<<"Department Science destroyed."<<std::endl;
    }
    virtual void print_info()const =0;
    private:
};

#pragma once 
#include <vector>
#include <functional>
#include <string>
#include <iostream>
class StringProcessor{
    public:
    void operator()(std::string &text){
        std::cout<<"Original string: "<<text<<std::endl;
        int number=0;
        for (auto &i:_int_tab)
        {
            number+=i(text);
        }
        for(auto &i:_void_tab){
            i(text);
        }
        if (_int_tab.size())
        {
            std::cout<<"Result from int algorithms:"<<number<<std::endl; 
        }
        if (_void_tab.size())
        {
            std::cout<<"Result from void algorithms: "<<text<<std::endl; 
        }
    }
    void reset();
    void addVoidAlgorithm(std::function<void(std::string &)>);
    void addIntAlgorithm(std::function<int(std::string&)>);
    void enableAlgorithm(const std::string text);
    private:
    std::vector <std::function<void(std::string &)>> _void_tab;
    std::vector <std::function<int(std::string&)>> _int_tab;
};
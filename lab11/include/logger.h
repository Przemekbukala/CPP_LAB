#pragma once
#include <iostream>
#include <string>
#include "ctime"
void  inline time(){
     std::time_t result = std::time(nullptr);
    std::string date_time = std::asctime(std::localtime(&result));
    date_time.pop_back(); //  Usuń znak nowej linii na końcu
    std::cout << date_time;
}
class Logger{
    public:
    static Logger& get_logger();
    void log(std::string log);
    protected:
    Logger(){}
    ~Logger(){
        std::cout<<"sfaksdafnondsfindsf";
    }
    static Logger first;
};
class Log{
    public:
    static void Advanced(std::string log);
};
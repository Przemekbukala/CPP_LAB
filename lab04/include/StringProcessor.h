#pragma once 
#include <vector>
#include <functional>
#include <string>
#include <iostream>
/**
 * @class StringProcessor
 * @brief Klasa pozwalająca dynamicznie dodawać algorytmy operujące na napisach.
 */
class StringProcessor{
    public:
    /**
     * @brief Uruchamia wszystkie dodane algorytmy na przekazanym napisie.
     * @param text Napis do przetworzenia.
     */
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
     /**
     * @brief Usuwa wszystkie dodane algorytmy z procesora.
     */
    void reset();
      /**
     * @brief Dodaje algorytm void (modyfikujący napis).
     * @param func Funkcja/lambda modyfikująca napis (std::string&).
     */
    void addVoidAlgorithm(std::function<void(std::string &)>);

    /**
     * @brief Dodaje algorytm int (zwracający wartość na podstawie napisu).
     * @param func Funkcja/lambda zwracająca int na podstawie napisu.
     */
    void addIntAlgorithm(std::function<int(std::string&)>);
      /**
     * @brief Aktywuje wbudowany algorytm o podanej nazwie.
     * @param name Nazwa algorytmu do aktywacji.
     */
    void enableAlgorithm(const std::string text);
    private:
    std::vector <std::function<void(std::string &)>> _void_tab;
    std::vector <std::function<int(std::string&)>> _int_tab;
};
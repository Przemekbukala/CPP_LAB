#pragma once
#include <string>
#include <memory>
#include <vector>
#include "FileSystemElement.h"
#include "File.h"
/**
 * @brief Klasa reprezentująca katalog (folder).
 */
class Dir: public FileSystemElement{
    public:
        /**
     * @brief Konstruktor katalogu.
     * @param name nazwa katalogu
     */
    Dir(const char* name):_name(name),_size(1),_date("01.05.2025"){}

    /**
     * @brief Dodaje nowy element do katalogu.
     * @param element unikalny wskaźnik do elementu systemu plików
     */
    friend void operator<<(std::ostream &o, const FileSystemElement & obj);
        /**
     * @brief Wypisuje informacje o katalogu i jego zawartości.
     * @param o strumień wyjściowy
     * @param indent wcięcie
     * @param flaga dodatkowy parametr
     */
    void  printInfo(std::ostream& o, int indent=0,int flaga=0) const;
    void add(std::unique_ptr<FileSystemElement> element);
    /**
     * @brief Iteruje po elementach katalogu i wypisuje specyficzne informacje w zależności od typu (dynamic_cast).
     */
    void printElementsInfo() const;

    /**
     * @brief Zwraca rozmiar katalogu.
     * @return rozmiar
     */
    unsigned  get_size() const;

    /**
     * @brief Zwraca nazwę katalogu.
     * @return nazwa
     */
    std::string get_name() const;

    /**
     * @brief Wypisuje nazwę elementów katalogu oraz ich typ (typeid).
     */
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
#pragma once
#include <string>
#include <memory>
#include <vector>
#include "FileSystemElement.h"
#include "File.h"
/**
 * @brief Klasa reprezentująca katalog w systemie plików.
 */
class Directory: public FileSystemElement{
    public:
    /**
     * @brief Konstruktor katalogu.
     * @param name nazwa katalogu
     */
    Directory(const char* name):_name(name){}
    /**
     * @brief Wypisuje strukturę katalogu i jego zawartość.
     * @param o strumień wyjściowy
     * @param indent ilość spacji do wcięcia
     */
    void  print(std::ostream& o, int indent=0) const;
        /**
     * @brief Dodaje element (plik lub podkatalog) do katalogu.
     * @param element unikalny wskaźnik do elementu systemu plików
     */
    void add(std::unique_ptr<FileSystemElement> element);
    private:
    std::string _name;
    std::vector <std::unique_ptr<FileSystemElement>> _tab;
};
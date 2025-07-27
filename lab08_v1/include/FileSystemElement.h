#pragma once
/**
 * @brief Abstrakcyjna klasa bazowa reprezentująca element systemu plików.
 */
class FileSystemElement{
    public:
        /**
     * @brief Wirtualny destruktor.
     */
    virtual ~FileSystemElement() = default;

    /**
     * @brief Metoda wirtualna do wypisywania zawartości elementu.
     * @param o strumień wyjściowy (np. std::cout)
     * @param indent ilość spacji do wcięcia
     */
    void virtual  print(std::ostream& o, int indent=0) const=0;
};
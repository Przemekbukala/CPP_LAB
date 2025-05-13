#include "include/Directory.h"
#include "include/File.h"
#include "include/FileSystemElement.h"
#include <memory>

int main(void){
    auto root = std::make_unique<Directory>("data");
    root->add(std::make_unique<File>("notes.txt"));
    root->add(std::make_unique<File>("readme.md"));
    auto img = std::make_unique<Directory>("img");
    img->add(std::make_unique<File>("logo.png"));
    img->add(std::make_unique<File>("screenshot.jpg"));
    root->add(std::move(img));
    auto docs = std::make_unique<Directory>("docs");
    docs->add(std::make_unique<File>("manual.pdf"));
    root->add(std::move(docs));
    root->print(std::cout);
    return 0;
}
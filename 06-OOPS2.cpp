#include <iostream>
#include <string>

class Book {
protected:
    std::string author, title;
    int numPages;

    public:
        Book(std::string author, std::string title, int n) 
            : author{author}, title{title}, numPages{n} {}

        bool isHeavy() { return numPages > 200; }
};

class Comic : public Book {
    std::string hero;

    public:
        Comic(std::string a, std::string t, int n, std::string h) 
            : Book{a, t, n}, hero{h} {}

        bool isHeavy() { return numPages > 30; }
};


int main() {
    Comic comic("Stan Lee", "Spide-Man", 40, "Spider-Man");

    std::cout << "Comic: " << comic.title << " by " << comic.author << std::endl;
    std::cout << "Is it heavy? " << (comic.isHeavy() ? "Yes" : "No") << std::endl;
}
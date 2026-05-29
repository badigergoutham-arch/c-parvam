#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int yearPublished;

public:
    // 1. Default Constructor (No arguments)
    Book() {
        title = "Unknown Title";
        author = "Unknown Author";
        yearPublished = 0;
        std::cout << "Default constructor called." << std::endl;
    }

    // 2. Parameterized Constructor (Two arguments)
    Book(std::string bTitle, std::string bAuthor) {
        title = bTitle;
        author = bAuthor;
        yearPublished = 0; // Defaulting the year since it wasn't provided
        std::cout << "Parameterized constructor (2 args) called." << std::endl;
    }

    // 3. Parameterized Constructor (Three arguments)
    Book(std::string bTitle, std::string bAuthor, int bYear) {
        title = bTitle;
        author = bAuthor;
        yearPublished = bYear;
        std::cout << "Parameterized constructor (3 args) called." << std::endl;
    }

    // A method to display the book's details
    void displayDetails() {
        std::cout << "Title: " << title 
                  << " | Author: " << author 
                  << " | Year: " << yearPublished << "\n\n";
    }
};

int main() {
    std::cout << "Creating book1...\n";
    // Calls the Default Constructor
    Book book1; 
    book1.displayDetails();

    std::cout << "Creating book2...\n";
    // Calls the 2-argument Parameterized Constructor
    Book book2("1984", "George Orwell"); 
    book2.displayDetails();

    std::cout << "Creating book3...\n";
    // Calls the 3-argument Parameterized Constructor
    Book book3("The Hobbit", "J.R.R. Tolkien", 1937); 
    book3.displayDetails();

    return 0;
}
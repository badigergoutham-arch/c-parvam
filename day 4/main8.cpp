//copy constructor
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int* score; // Pointer representing dynamically allocated memory

public:
    // 1. Standard Constructor
    Student(std::string studentName, int studentScore)
    {
        name = studentName;
        score = new int(studentScore); // Allocate memory on the heap
        std::cout << "Standard constructor called for " << name << "\n";
    }

    // 2. COPY CONSTRUCTOR
    // It takes a constant reference to an object of the same class
    Student(const Student& source)
    {
        name = source.name;
        
        // DEEP COPY: Allocate completely new memory and copy the value over.
        // If we didn't do this, both objects would point to the exact same memory address.
        score = new int(*source.score); 
        
        std::cout << "Copy constructor called for " << name << " (Deep Copy)\n";
    }

    // 3. Destructor
    ~Student()
    {
        std::cout << "Destructor called for " << name << ". Freeing memory...\n";
        delete score; // Prevent memory leaks
    }

    // Function to display student details and the memory address of the score
    void display() const
    {
        std::cout << "Name: " << name 
                  << " | Score: " << *score 
                  << " | Memory Address of Score: " << score << "\n";
    }

    // Function to change the score
    void setScore(int newScore)
    {
        *score = newScore;
    }
};

int main()
{
    std::cout << "--- Creating obj1 ---\n";
    Student obj1("Alice", 95);
    obj1.display();

    std::cout << "\n--- Creating obj2 as a copy of obj1 ---\n";
    // The Copy Constructor is triggered here!
    Student obj2 = obj1; 
    obj2.display();

    std::cout << "\n--- Modifying obj2's score ---\n";
    obj2.setScore(100);
    
    // Because we used a deep copy in our copy constructor, 
    // changing obj2's score does NOT affect obj1's score.
    std::cout << "After modification:\n";
    std::cout << "obj1: "; obj1.display();
    std::cout << "obj2: "; obj2.display();

    std::cout << "\n--- End of Program ---\n";
    return 0;
}
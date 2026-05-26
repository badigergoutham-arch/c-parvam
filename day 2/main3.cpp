#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout<<"enter your name: ";
    std::getline(std::cin, name);

    std::cout<<"enter your age: ";
    std::cin>>age;
    
    std::cout<<"Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm> // For std::remove_if

struct Student { int id; std::string name; int age; };

class Manager {
    std::vector<Student> db;
public:
    // CREATE
    void create(int id, std::string name, int age) { 
        db.push_back({id, name, age}); 
    }
    
    // READ
    void read() {
        for (const auto& s : db) 
            std::cout << s.id << ": " << s.name << " (" << s.age << ")\n";
    }
    
    // UPDATE
    void update(int id, std::string name, int age) {
        for (auto& s : db) {
            if (s.id == id) { s.name = name; s.age = age; break; }
        }
    }
    
    // DELETE (Using Erase-Remove idiom)
    void del(int id) {
        db.erase(std::remove_if(db.begin(), db.end(), 
                 [id](const Student& s) { return s.id == id; }), db.end());
    }
};

int main() {
    Manager m;
    
    m.create(1, "Alice", 20); // C
    m.create(2, "Bob", 22);   // C
    
    m.update(2, "Rob", 23);   // U
    m.del(1);                 // D
    
    m.read();                 // R (Will only print Rob)
    
    return 0;
}
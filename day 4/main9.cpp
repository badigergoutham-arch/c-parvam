#include <iostream>
#include <memory>

using namespace std;

class MyObject {
public:
    MyObject() {
        cout << "[system] object created.\n";
    }
    ~MyObject() {
        cout << "[system] object deleted.\n";
    }
    void read () {
        cout << "Reading data from the object...\n";
    }
};
void safeRead(const unique_ptr<MyObject>& obj) {
    if (obj != nullptr) {
        obj->read();
    } else {
        cout << "Object is not available to read.\n";
    }
}
int main() {
    std::cout << "--- Step 1: Creating the object ---\n";
    // Create the object using make_unique (best practice)
    std::unique_ptr<MyObject> myObj = std::make_unique<MyObject>();

    std::cout << "\n--- Step 2: Reading the object ---\n";
    // This will succeed because the object exists
    safeRead(myObj);

    std::cout << "\n--- Step 3: Deleting the object ---\n";
    // .reset() safely deletes the object and sets the pointer to nullptr automatically
    myObj.reset(); 

    std::cout << "\n--- Step 4: Trying to read the deleted object ---\n";
    // This will gracefully print your custom message instead of crashing
    safeRead(myObj);

    return 0;
}
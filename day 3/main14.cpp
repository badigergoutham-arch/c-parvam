#include <iostream>
#include <string>
#include <algorithm> // For std::transform
using namespace std;

int main() {
    string gender, name, course, project;
    float grade;

    // Displaying the mandatory note
    cout << "====================================" << endl;
    cout << "      ONLINE JOB APPLICATION        " << endl;
    cout << "==================================\n" << endl;

    std::string area;
    
    std::cout << "Enter the area in which you live: ";
    std::getline(std::cin, area);

    // Create a copy of the input and convert it to lowercase
    // This ensures "Bengaluru", "BENGALURU", and "bengaluru" all work
    std::string areaLower = area;
    std::transform(areaLower.begin(), areaLower.end(), areaLower.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    // Check if the substring "bengaluru" or "bangalore" exists anywhere in the input
    // std::string::npos means "not found", so != means "it was found"
    if (areaLower.find("bengaluru") != std::string::npos || 
        areaLower.find("bangalore") != std::string::npos) {
        
        std::cout << "you are eligible candidate you can proceed" << std::endl;
        
        // Add your code here to proceed
        
    } 
    else {
        std::cout << "you are not a bengalorian so you are not eligible to apply for this job" << std::endl;
        return 0; // Exit the program early if the condition is not met
    }

    // 2. Ask for Name
    cout << "Enter your full name: ";
    getline(cin, name);

    // 3. Ask for Course
    cout << "Enter your completed degree/course (e.g., Computer Science and Engineering): ";
    getline(cin, course);

    if (course.find("Computer Science") == string::npos && course.find("CSE") == string::npos && course.find("cse") == string::npos) {
        cout << "\nApplication Closed: Sorry " << name << ", this role requires a degree in Computer Science and Engineering." << endl;
        return 0;
    }

    // 4. Ask for Grade (in numbers)
    // Assuming a 10-point CGPA scale where 7.5+ is roughly B+ and 8.5+ is A
    cout << "Enter your final grade in numbers (e.g., CGPA out of 10): ";
    cin >> grade;
    cin.ignore(); // Clears the newline character left in the input buffer

    if (grade < 7.5) {
        cout << "\nApplication Closed: Sorry " << name << ", a minimum grade of B+ (approx. 7.5 CGPA) is required." << endl;
        return 0;
    }

    // 5. Ask for Project Details
    cout << "Enter the core technology/domain of your final project: ";
    getline(cin, project);

    // Checking if the project string contains "IOT" or "Internet of Things"
    bool isIotProject = false;
    if (project.find("IOT") != string::npos || project.find("IoT") != string::npos || 
        project.find("iot") != string::npos || project.find("Internet of Things") != string::npos) {
        isIotProject = true;
    }

    if (!isIotProject) {
        cout << "\nApplication Closed: Sorry " << name << ", hands-on project experience with IoT is mandatory for this position." << endl;
        return 0;
    }

    // 1. Check Gender
    cout << "Please confirm your gender (Female/Male): ";
    getline(cin, gender);
    if (gender != "Female" && gender != "female" && gender != "F" && gender != "f") 
    {
        cout << "\nApplication Closed: This specific role is exclusively for female applicants." << endl;
        return 0; // Exit the program early if the condition is not met
    }
    // Success Message if all flow control conditions evaluate to true
    cout << "\n**************************************************" << endl;
    cout << "CONGRATULATIONS, " << name << "!" << endl;
    cout << "You meet all the preliminary technical requirements." << endl;
    cout << "Your profile has been shortlisted for the interview." << endl;
    cout << "****************************************************\n" << endl;
    cin.get();

    return 0;
}
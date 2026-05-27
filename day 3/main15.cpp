#include <iostream>
#include <string>
#include <algorithm> // For std::transform

using namespace std;

int main() {
    string area, gender, name, course, project;
    float grade;

    // Displaying the mandatory note
    cout << "====================================" << endl;
    cout << "        ONLINE JOB APPLICATION      " << endl;
    cout << "====================================\n" << endl;

    // --- PHASE 1: GATHER ALL INPUTS ---
    cout << "Enter the area in which you live: ";
    getline(cin, area);

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your completed degree/course (e.g., Computer Science and Engineering): ";
    getline(cin, course);

    cout << "Enter your final grade in numbers (e.g., CGPA out of 10): ";
    cin >> grade;
    cin.ignore(); // Clears the newline character left in the input buffer so the next getline works

    cout << "Enter the core technology/domain of your final project: ";
    getline(cin, project);

    cout << "Please confirm your gender (Female/Male): ";
    getline(cin, gender);

    // --- PHASE 2: EVALUATE AND SHOW RESULTS ---
    cout << "\n====================================" << endl;
    cout << "        EVALUATION RESULTS          " << endl;
    cout << "====================================\n" << endl;

    // 1. Check Area
    string areaLower = area;
    transform(areaLower.begin(), areaLower.end(), areaLower.begin(),
              [](unsigned char c){ return tolower(c); });

    if (areaLower.find("bengaluru") == string::npos && areaLower.find("bangalore") == string::npos) {
        cout << "Application Closed: You are not a Bengalurian so you are not eligible to apply for this job." << endl;
        return 0; // Exit early if failed
    } else {
        cout << "[+] Location Check: Passed" << endl;
    }

    // 2. Check Course
    if (course.find("Computer Science") == string::npos && course.find("CSE") == string::npos && course.find("cse") == string::npos) {
        cout << "\nApplication Closed: Sorry " << name << ", this role requires a degree in Computer Science and Engineering." << endl;
        return 0;
    } else {
        cout << "[+] Degree Check: Passed" << endl;
    }

    // 3. Check Grade
    if (grade < 7.5) {
        cout << "\nApplication Closed: Sorry " << name << ", a minimum grade of B+ (approx. 7.5 CGPA) is required." << endl;
        return 0;
    } else {
        cout << "[+] Grade Check: Passed" << endl;
    }

    // 4. Check Project
    bool isIotProject = false;
    if (project.find("IOT") != string::npos || project.find("IoT") != string::npos || 
        project.find("iot") != string::npos || project.find("Internet of Things") != string::npos) {
        isIotProject = true;
    }

    if (!isIotProject) {
        cout << "\nApplication Closed: Sorry " << name << ", hands-on project experience with IoT is mandatory for this position." << endl;
        return 0;
    } else {
        cout << "[+] Project Check: Passed" << endl;
    }

    // 5. Check Gender
    if (gender != "Female" && gender != "female" && gender != "F" && gender != "f") {
        cout << "\nApplication Closed: This specific role is exclusively for female applicants." << endl;
        return 0;
    } else {
         cout << "[+] Gender Check: Passed" << endl;
    }

    // --- FINAL SUCCESS MESSAGE ---
    // If the program reaches here, it means all conditions evaluated to true
    cout << "\n**************************************************" << endl;
    cout << "CONGRATULATIONS, " << name << "!" << endl;
    cout << "You meet all the preliminary technical requirements." << endl;
    cout << "Your profile has been shortlisted for the interview." << endl;
    cout << "****************************************************\n" << endl;
    
    cin.get();
    return 0;
}
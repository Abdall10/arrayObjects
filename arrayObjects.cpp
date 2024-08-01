#include <iostream>
#include <set>   //for the set container that keeps track of unique IDs.
#include <string>  //  for the string data type.
#include <limits>  //  for numeric limits used in input validation.
using namespace std;

// Student Data Management System with Unique ID Validation in C++ , use array Objects
class Student {
private:
    int id = 0; 
    string name = "unknown";
    int age = 0;
    int mark = 0;
public:
    // Function to set values for the student
    void setValues(set<int>& usedIds) {
        cout << "Enter your Data: " << endl;

        // Loop until a unique integer ID is entered
        while (true) {
          cout << "Enter your id: " << endl;
          cin >> id;
          if (cin.fail()) { 
              cin.clear(); // clear the error flag
              cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
              cout << "Invalid input. Please enter an integer and unique." << endl;
              continue;
          }
          if (usedIds.find(id) == usedIds.end()) {
              usedIds.insert(id);
              break;
          } else {
              cout << "ID already in use. Please enter a different ID." << endl;
          }
        }

        cout << "Enter your name: " << endl;
        cin >> name;
        cout << "Enter your age: " << endl;
        cin >> age;
        cout << "Enter your mark: " << endl;
        cin >> mark;
    }

    // Function to print the student's data
    void print() {
     cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", Mark: " << mark << endl;
    }
};

int main() {
    Student ob[4];  // Array of 4 Student objects 
    set<int> usedIds;  // Set to keep track of used IDs

    // Loop to set values for each student
    for (int i = 0; i < 4; i++) { 
        ob[i].setValues(usedIds);
    }

    // Loop to print values for each student
    for (int i = 0; i < 4; i++) {
        ob[i].print();
    }

    return 0;
}





// Mohamed Azouz
// 900225230

#ifndef Person_hpp
#define Person_hpp

#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int ID;
    int Age;
public:
    Person(); // Default constructor gives default values to the variables in the class Person
    void setName(string n);// setter for the name
    string getName();// getter for the name
    void setID(int i); // setter for the ID
    int getID(); // getter for the ID
    void setAge(int a); // setter for the age
    int getAge(); // getter for the age
    void printInfo(); // display function to display a person's information
    struct Appointment // struct which contains information about an appointment
    {
        int hours;
        int mins;
    };
};

#endif /* Person_hpp */

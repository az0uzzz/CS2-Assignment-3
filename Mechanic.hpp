



// Mohamed Azouz
// 900225230

#ifndef Mechanic_hpp
#define Mechanic_hpp

#include <stdio.h>
#include <iostream>
#include "Person.hpp"

#endif /* Mechanic_hpp */


class Mechanic : public Person
{
private:
    int counter;
    Appointment *schedule;
public:
    Mechanic();// default constructor which sets the counter to 0 and allocates memory to the dynamic array schedule
    bool isAvailable(Appointment a);// Boolean function which checks whether a mechanic is available for a certain appointment
    void setCounter(int c); // setter for the counter
    int getCounter(); // getter for the counter
    void addApp(int h, int m); // overloaded function to add an appointment to a mechanic's schedule by accepting the hour and minutes
    void addApp(Person::Appointment x); // overloaded function to add an appointment to a mechanic's schedule by accepting the appointment as an object of a struct appointment
    ~Mechanic(); // destructor to deallocate the memory for the schedule dynamic array
    
};

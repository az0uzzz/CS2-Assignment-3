



// Mohamed Azouz
// 900225230

#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <iostream>
#include "Person.hpp"

#endif /* Customer_hpp */

using namespace std;

class Customer : public Person // Class customer inherits from class person publicly
{
private:
    int MechanicID;
    Appointment appointment;
public:
    void setMID(int i); // setter for the Mechanic ID
    int getMID(); // getter for the Mechanic ID
    Appointment getApp(); // getter for the customer's appointment
    void setApp(int h, int m); // setter for the customer's appointment
    bool operator<(Customer a); // Overloaded operators which accept a customer and compares their appointments to see which is earlier.
    bool operator>(Customer a);
    bool operator==(Customer a);
};

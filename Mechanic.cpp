



// Mohamed Azouz
// 900225230

#include "Mechanic.hpp"


Mechanic :: Mechanic() // default constructor which sets the counter to 0 and allocates memory to the dynamic array schedule
{
    counter=0;
    schedule = new Appointment[2400];
}
bool Mechanic :: isAvailable(Appointment a) // Boolean function which checks whether a mechanic is available for a certain appointment
{
    for(int i=0;i<counter;i++)
    {
        if((*(schedule+i)).hours==a.hours&&(*(schedule+i)).mins==a.mins)
            return false;
    }
    return true;
}
void Mechanic :: setCounter(int c) // setter for the counter
{
    counter = c;
}
int Mechanic :: getCounter() // getter for the counter
{
    return counter;
}
void Mechanic :: addApp(int h, int m) // overloaded function to add an appointment to a mechanic's schedule by accepting the hour and minutes
{
    (*(schedule+counter)).hours = h;
    (*(schedule+counter)).mins = m;
    counter++;
}
void Mechanic :: addApp(Appointment x) // overloaded function to add an appointment to a mechanic's schedule by accepting the appointment as an object of a struct appointment
{
    (*(schedule+counter))=x;
    counter++;
}
Mechanic :: ~Mechanic() // destructor to deallocate the memory for the schedule dynamic array
{
    delete [] schedule;
}

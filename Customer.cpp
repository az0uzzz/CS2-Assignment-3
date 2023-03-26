



// Mohamed Azouz
// 900225230

#include "Customer.hpp"


void Customer :: setMID(int i) // setter for the Mechanic ID
{
    MechanicID = i;
}
int Customer :: getMID() // getter for the Mechanic ID
{
    return MechanicID;
}
Customer::Appointment Customer :: getApp() // getter for the customer's appointment
{
    return appointment;
}
void Customer :: setApp(int h, int m) // setter for the customer's appointment
{
    appointment.hours = h;
    appointment.mins = m;
}

// Overloaded operators which accept a customer and compares their appointments to see which is earlier.
bool Customer :: operator<(Customer a)
{
    if(appointment.hours<a.getApp().hours)
        return true;
    else if(appointment.hours==a.getApp().hours&&appointment.mins<a.getApp().mins)
        return true;
    return false;
}
bool Customer :: operator>(Customer a)
{
    if(appointment.hours>a.getApp().hours)
        return true;
    else if(appointment.hours==a.getApp().hours&&appointment.mins>a.getApp().mins)
        return true;
    return false;
}
bool Customer :: operator==(Customer a)
{
    if(appointment.hours==a.getApp().hours&&appointment.mins==a.getApp().mins)
        return true;
    return false;
}

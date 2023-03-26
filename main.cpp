



// Mohamed Azouz
// 900225230

#include <iostream>
#include <fstream>
#include "Person.hpp"
#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queues.hpp"
using namespace std;

int main()
{
    // Open the Mechanics.txt file
    ifstream r;
    r.open("Mechanics.txt");
    
    Mechanic *mech; // Creates a Dynamic Array of type Mechanic to store all the mechanics data.
    int mSize; // creates a variable to store the number of mechanics.
    r>>mSize; // reads the number of mechanics from the top of the file. The file is in the correct format for this code to work.
    mech = new Mechanic[mSize]; // Assigns the correct amount of memory to the dynamic array mech to store the mechanics.
    
    //Creating variables to use in the setters and getters functions when reading from the file.
    string Name;
    int ID, Age, num_appt, h, m;
    
    // the size of the file is known so there is no need to use the eof() function as it does not always work properly.
    for(int i=0;i<mSize;i++)
    {
        r >> Name >> Age >> ID >> num_appt; // the data is read from the file and saved into the corresponding variables.
        (*(mech+i)).setName(Name); // the data from the files is used to set the value of the corresponding variables in the mechanics classes in the array.
        (*(mech+i)).setID(ID);
        (*(mech+i)).setAge(Age);
        
        // A for loop iterates from 0 to the number of appointments that each mechanic has in order to make sure that all of the pre-existing appointments are saved.
        for(int j=0;j<num_appt;j++)
        {
            r >> h >> m;
            (*(mech+i)).addApp(h, m);
        }
    }
    r.close(); // the file is closed.
    
    ifstream r1; // a new ifstream is created to read the second file.
    r1.open("Customers.txt"); // the customers file is opened in order to read the correct information.
    
    Customer *cust; // a pointer of type customer is created in order to create a dynamic array.
    int cSize; // an integer variable is created to store the number of customers in the file.
    r1 >> cSize; // the number of customers is read from the top line of the file and saved into its variable.
    
    int mechanic = 0; // a variable 'mechanic' is created in order to keep track of the next mechanic to be appointed a customer
    bool found = false; // a boolean flag is created in order to keep track of whether a customer has been assigned a mechanic or not.
    
    cust = new Customer[cSize]; // the cust dynamic array is given the memory it needs in order to store all customers.
    for(int i=0;i<cSize;i++) // a for loop is made which iterates from 0 to the number of customers in order to read all customers' data.
    {
        r1 >> Name >> h >> m; // the name and appointment of each customer is read from the file into the corresponding variables and set appropriately using their setters
        (*(cust+i)).setName(Name);
        (*(cust+i)).setApp(h, m);
        for(int j=0;j<mSize;j++) // a for loop iterates through the mechanics array in order to assign a mechanic to each customer.
        {
            if((*(mech+mechanic)).isAvailable((*(cust+j)).getApp())&& !found) // this if statement checks whether the current mechanic is available and whether the customer has been assigned a mechanic.
            {
                (*(cust+i)).setMID((*(mech+mechanic+j)).getID()); // sets the mechanic id variable in the customer object in the array to the ID of the assigned mechanic.
                (*(mech+mechanic+j)).addApp(h,m); // adds the customer to the mechanic's schedule array
                found = true; // sets the found flag to true
                mechanic++; // increments mechanic in order to look at the next mechanic in the array
                mechanic %= mSize; // makes sure mechanic is within the size of the array.
            }
        }
        if(!found)
        {
            (*(cust+i)).setMID(-1); // if there is no available mechanic, the Mechanic ID is set to -1 meaning no mechanic available
        }
        found = false; // the found flag is reset to false for the next iteration.
    }
    
    
    Customer temp; // a variable of type customer is made to allow switching of two customers in the array to sort it.
    
    // The customers array is sorted from earliest to latest appointments.
    for(int i=0;i<cSize;i++)
    {
        for(int j=i+1; j<cSize;j++)
        {
            if((*(cust+i)>(*(cust+j))))
            {
                temp = (*(cust+i));
                (*(cust+i)) = (*(cust+j));
                (*(cust+j)) = temp;
            }
        }
    }
    
    
    
    // A queue holding customers is created
    Queues<Customer> line;
    for(int i=0;i<cSize;i++) // the for loop iterates through the array of customers
    {
        line.Push((*(cust+i))); // Pushes the current customer into the queue.
        
        
        // displays the customer with their mechanic and appointment
        cout<<"Customer:"<<endl;
        (*(cust+i)).printInfo();
        cout<<"Mechanic:"<<endl;
        if((*(cust+i)).getMID()!=-1)
           (*(mech+(*(cust+i)).getMID())).printInfo();
        else
           cout<<"No mechanic is available at this time"<<endl;
        cout<<"Time:"<<endl;
        cout<<(*(cust+i)).getApp().hours<<":"<<(*(cust+i)).getApp().mins<<endl<<endl<<endl;
    }
    
    
    delete [] mech; // the dynamic arrays are deleted to free up the memory
    delete [] cust;
}

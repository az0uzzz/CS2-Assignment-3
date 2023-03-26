



// Mohamed Azouz
// 900225230

#include "Person.hpp"

Person :: Person() // Default constructor gives default values to the variables in the class Person
{
    name = "";
    ID = 0;
    Age = 0;
}
void Person :: setName(string n) // setter for the name
{
    name = n;
}
string Person :: getName() // getter for the name
{
    return name;
}
void Person :: setID(int i) // setter for the ID
{
    ID=i;
}
int Person :: getID() // Getter for the ID
{
    return ID;
}
void Person :: setAge(int a) // setter for the age
{
    Age = a;
}
int Person :: getAge() // getter for the age
{
    return Age;
}
void Person :: printInfo() // print function to display a person's info
{
    cout<<"Name: "<<name<<"\t ID: "<<ID<<"\t Age: "<<Age<<endl;
}

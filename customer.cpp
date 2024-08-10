#include "customer.h"

Customer::Customer()
{
    id = -1;
    
    
}
Customer::Customer(const Customer&)
{

}
Customer::Customer(int cID, string fName, string lName)
{
    this->id = cID;
    this->firstName = fName;
    this->lastName = lName;
}

bool Customer::borrowMovie(Movie* movie, Transaction* transaction)
{ 
    history.push_back(transaction);
    return false;
}

bool Customer::returnMovie(Movie* movie, Transaction* transaction)
{
    history.push_back(transaction);
    return false;
}

void Customer::displayHistory() const
{
    for(int i = 0; i < history.size(); i++)
    {
        //cout << "testing" << endl;
        history[i]->display(); 
    }
}

string Customer::getFName() const
{
    return firstName;
}

string Customer::getLName() const
{
    return lastName;
}
int Customer::getID() const
{
    return id;
}





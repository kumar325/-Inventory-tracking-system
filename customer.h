#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "transaction.h"
#include "borrow.h"
#include <string>
#include <vector>
using namespace std;

class Customer{
    //friend ostream& operator<<(ostream& os, const Customer& customer);
    public:
        Customer();
        Customer(const Customer&);
        Customer(int id, string firstName, string lastName);

        bool borrowMovie(Movie* movie, Transaction* transaction);
        bool returnMovie(Movie* movie, Transaction* transaction);
        void displayHistory() const;
        int getID() const;
        string getFName() const;
        string getLName() const;
        

    private:
        int id;
        string firstName;
        string lastName;
        vector<Transaction*> history; 

};
#endif
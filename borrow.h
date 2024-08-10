#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"
using namespace std;

class Borrow : public Transaction {
    public:
        Borrow();
        Borrow(int cID, char typ, Movie* mov);
        /*
        bool borrowMovie(Movie* movie, Customer* c);
        */
        virtual void display() const;
        //virtual bool doTransaction();
    private: 
        int customer;
        char type;
        Movie* movie;
};
#endif
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include "movie.h"

class Transaction {
    public:
        Transaction();
        Transaction(int cID, char type, Movie* movie);
        Transaction(const Transaction&);
        virtual ~Transaction();
        virtual void display() const =0;
        //virtual bool doTransaction() = 0;


    protected:
        char type;
        int customer;
        Movie* movie;
};
#endif
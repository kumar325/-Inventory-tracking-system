#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"

class Return : public Transaction {
    public:
        Return();
        Return(int cID, char type, Movie* movie);
        bool returnMovie(Movie* movie, int c);
        virtual void display() const;
        //virtual bool doTransaction();
    private: 
        int customer;
        char type;
        Movie* movie;
    

};
#endif
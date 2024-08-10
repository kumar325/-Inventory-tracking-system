#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

class History : public Transaction {
    public:
        History();
        History(int cID, char type, Movie* movie);
        bool showCustomerHistory(int cID);
        virtual void display() const;
};
#endif
#include "transaction.h"

Transaction::Transaction() {
    type = ' ';
    movie = NULL;
}
Transaction::Transaction(const Transaction& t)
{
    
}
Transaction::Transaction(int cID, char t, Movie* m) {
    customer = cID;
    type = t;
    movie = m;
}

Transaction::~Transaction() {
    delete movie;
}

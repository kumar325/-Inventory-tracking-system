#include "history.h"



History::History() : Transaction() {
}

History::History(int cID, char type, Movie* movie) : Transaction(cID, type, movie) {
}

bool History::showCustomerHistory(int cID) {
    return false;
}

void History::display() const
{
    
}
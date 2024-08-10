#include "return.h"

Return::Return() : Transaction() {
}

Return::Return(int cID, char type, Movie* movie) : Transaction(cID, type, movie) {
}

/*
bool Return::returnMovie(Movie* movie, Customer* c) {
    c->returnMovie(movie, *this);
    return false;
}
*/
void Return::display() const
{
    cout << "Returned " << movie->getTitle() << " by " << movie->getDirector() << endl;
}


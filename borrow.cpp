#include "borrow.h"



Borrow::Borrow() : Transaction() {
    cout << "nope" << endl;
}


Borrow::Borrow(int cID, char typ, Movie* mov) : Transaction(cID, typ, mov) {
    customer = cID;
    type = typ;
    movie = mov; 
}

/*
bool Borrow::borrowMovie(Movie* movie, Customer* c) {
    c->borrowMovie(movie, *this);
    return false;
}
*/



void Borrow::display() const
{
    cout << "Borrowed " << movie->getTitle() << " by " << movie->getDirector() << endl;
}
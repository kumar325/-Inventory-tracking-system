#ifndef COMEDY_H
#define COMEDY_H
#include <iostream>
#include "movie.h"
using namespace std;

class Comedy : public Movie {
    public:
        Comedy();
        Comedy(int stock, string director, string title, int year);
        bool operator<(const Movie& rhs) const;
        bool operator==(const Movie& rhs) const;

    protected:
        ostream& print(ostream& os) const;

};
#endif
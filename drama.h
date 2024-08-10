#ifndef DRAMA_H
#define DRAMA_H
#include <iostream>
#include "movie.h"
using namespace std;

class Drama : public Movie {
    public:
        Drama();
        Drama(int stock, string director, string title, int year);
        ~Drama();
        bool buildDrama(int stock, string director, string title, int year, Movie* movie);

        virtual void display() const;
        bool operator<(const Movie& rhs) const;
        bool operator==(const Movie& rhs) const;

    protected:
        ostream& print(ostream& os) const;

};
#endif
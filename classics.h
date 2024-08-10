#ifndef CLASSICS_H
#define CLASSICS_H
#include <iostream>
#include "movie.h"
#include <vector>
#include <string>
using namespace std;

class Classics : public Movie {
    public:
        Classics();
        Classics(int stock, string director, string title, string majorActor, int month, int year);
        bool operator<(const Movie& rhs) const;
        bool operator==(const Movie& rhs) const;

    protected:
        int month;
        string majorActor;
        ostream& print(ostream& os) const;
        

};
#endif
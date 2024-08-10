#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Movie {
    friend ostream& operator<<(ostream& os, const Movie& movie);
    public:
        Movie();
        Movie(int stock, string director, string title, int year);
        virtual ~Movie();
        bool updateStock(int amount);
        virtual bool operator<(const Movie& rhs) const = 0;
        virtual bool operator==(const Movie& rhs) const = 0;
        string getTitle() const;
        string getDirector() const;
        char getGenre() const;
        


    protected:
        virtual ostream& print(ostream& os) const = 0;

        char genre;
        string title;
        string director;
        int stock;
        int year;
};
#endif
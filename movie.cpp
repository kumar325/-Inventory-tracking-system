#include "movie.h"
#include "comedy.h"

Movie::Movie()
{
    stock = 0;
    director = "";
    title = "";
    year = -1;
}

Movie::Movie(int stock, string director, string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

Movie::~Movie() {}

bool Movie::updateStock(int amount)
{
    stock += amount;
    return true;
}

string Movie::getTitle() const
{
    return title;
}

string Movie::getDirector() const
{
    return director;
}

char Movie::getGenre() const
{
    return genre;
}

ostream& operator<<(ostream& os, const Movie& movie)
{
    return movie.print(os);
}

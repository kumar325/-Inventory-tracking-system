#include "drama.h"
#include "movie.h"

Drama::Drama() : Movie()
{}

Drama::Drama(int stock, string director, string title, int year) : Movie(stock, director, title, year)
{


}

Drama::~Drama()
{}

bool Drama::buildDrama(int stock, string director, string title, int year, Movie *movie)
{
    movie = new Drama(stock, director, title, year);
    return true;
}

bool Drama::operator<(const Movie &rhs) const
{
    const Drama& otherDrama = static_cast<const Drama&>(rhs);
    if (director < otherDrama.director)
    {
        return true;
    }
    else if (director == otherDrama.director)
    {
        return title < otherDrama.title;
    }
    return false;
}

bool Drama::operator==(const Movie& rhs) const
{
    const Drama& drama = static_cast<const Drama&>(rhs);
    return director == drama.director && title == drama.title;
}

void Drama::display() const
{
    
}

ostream& Drama::print(ostream& os) const
{
    os << "D       D       " << title;
    for(int i = 0; i < 35 - title.length(); i++)
    {
        cout << " ";
    }
    cout << director;
    for(int i = 0; i < 22- director.length(); i++)
    {
        cout << " ";
    }
    cout << year;
    for(int i = 0; i < 8 - to_string(year).length(); i++)
    {
        cout << " ";
    }
    cout << stock << endl;

    
    return os;
}
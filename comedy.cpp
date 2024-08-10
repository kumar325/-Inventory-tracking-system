#include "comedy.h"

Comedy::Comedy() : Movie() {}

Comedy::Comedy(int stock, string director, string title, int year) : Movie(stock, director, title, year) {}

bool Comedy::operator<(const Movie& rhs) const
{
    const Comedy& otherComedy = static_cast<const Comedy&>(rhs);
    if (title < otherComedy.title)
    {
        return true;
    }
    else if (title == otherComedy.title)
    {
        return year < otherComedy.year;
    }
    return false;
}

bool Comedy::operator==(const Movie& rhs) const
{
    const Comedy& comedy = static_cast<const Comedy&>(rhs);
    return title == comedy.title && year == comedy.year;
}

ostream& Comedy::print(ostream& os) const
{
    os << "F       D       " << title;
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
#include "classics.h"

Classics::Classics() : Movie()
{
    month = -1;
}

Classics::Classics(int stock, string director, string title, string majorActor, int month, int year) : Movie(stock, director, title, year)
{
    this->month = month;
    this->majorActor = majorActor;
}

bool Classics::operator<(const Movie& rhs) const
{
    const Classics& otherClassic = static_cast<const Classics&>(rhs);
    if (year < otherClassic.year)
    {
        return true;
    }
    else if (year == otherClassic.year)
    {
        if (month < otherClassic.month)
        {
            return true;
        }
        else if (month == otherClassic.month)
        {
            return majorActor < otherClassic.majorActor;
        }
    }
    return false;
}

bool Classics::operator==(const Movie& rhs) const
{
    const Classics& classics = static_cast<const Classics&>(rhs);
    return title == classics.title && director == classics.director && month == classics.month && year == classics.year;
}


ostream& Classics::print(ostream& os) const
{
    os << "C       D       " << title;
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


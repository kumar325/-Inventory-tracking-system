#include "store.h"


Store::Store()
{
}

Store::~Store()
{
}

void Store::buildCustomers(ifstream& infile)
{
    int id;
    string firstName;
    string lastName;
    while (infile >> id)
    {
        infile >> firstName;
        infile >> lastName;
        Customer* customer = new Customer(id, firstName, lastName);
        customers.hash(customer);

    }
}

void Store::processTransactions(ifstream& infile)
{
    char type;
    int customerID;
    char mediaType;
    char genre;
    string title;
    string director;
    string actor;
    int month;
    int year;

    Node* store;
    Movie* temp;
    Transaction* transTemp; 

    while (infile >> type)
    {
        infile >> type;
        if (type == 'I')
        {
            displayInventory();
        }
        else if (type == 'H')
        {
            customers.get(customerID)->displayHistory();
            
            //find customer in hashtable and then call displayHistory
        }
        else if (type == 'B')
        {
            infile >> customerID >> mediaType >> genre;

            transTemp = new Borrow(customerID,type, store->movie);

            if(genre == 'C')
            {

                //makes new classics temp movie
                temp = new Classics(0, director, title, actor, month,year);

                //retrieves from the classics BST with the two data points above
                classics.retrieve(*temp, store);

            }
            else if(genre == 'D')
            {
               
                temp= new Drama(0, director, title, year);

                drama.retrieve(*temp, store);

                 
            }
            else if(genre == 'F')
            {
                temp= new Comedy(0, director, title, year);

                comedy.retrieve(*temp, store);
            }

            customers.get(customerID)->borrowMovie(store->movie, transTemp); 
            // have to handle the different types of inputs
        }
        else if (type == 'R')
        {
            infile >> customerID >> mediaType >> genre;

            //makes new classics temp movie
                temp = new Classics(0, director, title, actor, month,year);
                
                //makes new temporary transaction
                transTemp = new Borrow(customerID,type, store->movie);

                //retrieves from the classics BST with the two data points above
                classics.retrieve(*temp, store);
                
                customers.get(customerID)->borrowMovie(store->movie, transTemp); 
        }
        else{
            cout << type << " is an invalid transaction type" << endl;
        }
    }
}

void Store::displayInventory() const 
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Comedy" << endl;
    cout << "Genre   Media   Title                              Director              Year    Stock" << endl;
    comedy.displayTree();
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Drama" << endl;
    cout << "Genre   Media   Title                              Director              Year    Stock" << endl;
    drama.displayTree();
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Classics" << endl;
    cout << "Genre   Media   Title                              Director              Year    Stock" << endl;
    classics.displayTree();
    cout << "----------------------------------------------------------------------------------------------" << endl;

}

void Store::buildInventory(ifstream& infile)
{
    string line;

    while (getline(infile, line))
    {
        string genre;
        string quantity;
        string director;
        string title;
        int year;

        stringstream ss(line);

        getline(ss, genre, ',');

        if(genre == "F")
        {
            ss.ignore(1);
            getline(ss, quantity, ',');
            ss.ignore(1);
            getline(ss, director, ',');
            ss.ignore(1);
            getline(ss, title, ',');
            ss >> year;
            Movie* movie = nullptr;
            ;
            movie = new Comedy(stoi(quantity), director, title, year);
            comedy.insert(movie);
        } 
        else if(genre == "D")
        {
            ss.ignore(1);
            getline(ss, quantity, ',');
            ss.ignore(1);
            getline(ss, director, ',');
            ss.ignore(1);
            getline(ss, title, ',');
            ss >> year;
            Movie* movie = nullptr;
            movie = new Drama(stoi(quantity), director, title, year);
            drama.insert(movie);

        }
        else if(genre == "C")
        {
            string actorfName;
            string actorlName;
            string actor;
            int month;
            ss.ignore(1);
            getline(ss, quantity, ',');
            ss.ignore(1);
            getline(ss, director, ',');
            ss.ignore(1);
            getline(ss, title, ',');
            ss.ignore(1);
            ss >> actorfName >> actorlName >> month >> year;
            actor = actorfName + " " + actorlName;
            Movie* movie = nullptr;
            movie = new Classics(stoi(quantity), director, title, actor, month, year);
            classics.insert(movie);
        }
    }
}

/*
int main()
{
    ifstream infile("testmovies.txt");
    Store store;
    store.buildInventory(infile);
    store.displayInventory();
}
*/
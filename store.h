#ifndef STORE_H_
#define STORE_H_
#include "movie.h"
#include "borrow.h"
#include "transaction.h"
#include "customer.h"
#include "hashtable.h"
#include "bst.h"
#include <fstream>
#include "comedy.h"
#include "drama.h"
#include "classics.h"

class Store{
    public:
        Store();
        ~Store();
        void buildInventory(ifstream& infile);
        void buildCustomers(ifstream& infile);
        void processTransactions(ifstream& infile);
        void displayInventory() const;
    private:
        BST classics;
        BST comedy;
        BST drama;
        HashTable<Customer*> customers;
};
#endif
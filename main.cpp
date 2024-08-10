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
#include <iostream>
#include "store.h"

using namespace std; 
int main()
{
    ifstream infile("testmovies.txt");
    Store store;
    store.buildInventory(infile);
    store.displayInventory();



}
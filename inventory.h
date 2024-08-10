#ifndef INVENTORY_H
#define INVENTORY_H
#include "transaction.h"
#include "bst.h"

class Inventory : public Transaction {
    public:
        Inventory();
        Inventory(int cID, char type, Movie* movie); 
        bool showInventory();
        virtual void display() const;
        

};
#endif
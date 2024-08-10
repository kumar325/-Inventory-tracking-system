#include "inventory.h"



Inventory::Inventory() : Transaction() {
}

Inventory::Inventory(int cID, char type, Movie* movie) : Transaction(cID, type, movie) {
}

bool Inventory::showInventory() {
    return false;
}
void Inventory::display() const
{

}


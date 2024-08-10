#include <iostream>
#include <vector>
#include <string> 
#include "customer.h"
#include "movie.h"
#pragma once
using namespace std;


template <typename T>
class HashTable
{
    public:
       
        HashTable()
        {
            //default size
            size = 100;
        }
        
        //hash function for customer objects
        void hash(Customer* c)
        {
            //based on the ID of the user
            int id = c->getID();
            int collisions = 0; 

            //hash function
            int hashIndex = c->getID() % 100; 
            
            //default customer constructor sets id to -1
            while(table[hashIndex]->getID() != -1)
            {

                //if the first index found is not empty tick a collision
                collisions += 1; 

                //try the next index using quadratic probing
                hashIndex = ((c->getID() % 100)  + (collisions* collisions)) % 100;
            }

            //set index
            table[hashIndex] = c;
        }

        //converts a string to ASCII, includes space in between words
        int stringToASCII(string name)
        {
            int sum = 0;
            for(int i = 0; i < name.length(); i++)
            {
                sum += int(name[i]);
            }
            return sum;
        }
        
        /*
        void hash(Movie m)
        {
            
            //gets ascii of the title of the movie
            int asciiVal = stringToASCII(m.getTitle());
            if(m.getType() == 'C')
            {
                //if the movie is a Classic, also uses the major actor as two classic movies can have the same name, but different actor
                asciiVal += stringToASCII(m.getMajorActor());
            }
            cout << "ASCII " << asciiVal << endl;
            int collisions = 0; 
            int hashIndex = asciiVal % 100; 
            
            while(table[hashIndex].getTitle() != "-1")
            {
                collisions += 1; 
                hashIndex = (asciiVal % 100)  + (collisions* collisions);
            }
            table[hashIndex] = m;
            
        }
        */
        

        Customer* get(int id)
        {

            //reverse quadratic probing
            int index = id % 100;
            int collisions = 0;
            while(table[index]->getID() != id)
            {
                if(table[index]->getID() == -1)
                {
                    cout << "No value found for key." << endl;
                    break;
                }
                collisions += 1; 
                index = ((id % 100)  + (collisions* collisions)) % 100;
            }
            
            return table[index];
        }

        


        /*
        Movie get(string mov, string actor)
        {
            int asciiVal = stringToASCII(mov) + stringToASCII(actor);
            int index = asciiVal % 100;
            cout << index << endl;
            int collisions = 0; 
            while(table[index].getTitle() != mov)
            {
                if(table[index].getTitle() == "-1")
                {
                    cout << "No value found for key." << endl;
                    break;
                }
                collisions += 1; 
                index = (asciiVal % 100)  + (collisions* collisions);
            }
            
            return table[index];
        }
        */

        


        void print()
        {
            for(int i = 0; i < 100; i++)
            {
               if(table[i]->getID() != -1)
               {
                    cout << "Index: " << i << " |" << " ID: " << table[i].getID() << endl;
               }
            }
            
        }

        /*
        void printM()
        {
            for(int i = 0; i < 100; i++)
            {
               if(table[i].getTitle() != "-1")
               {
                    cout << "Index: " << i << " |" << " Movie: " << table[i].getTitle() << ", " << table[i].getDirector();
                    if(table[i].getType() == 'C')
                    {
                        cout << ", " <<  table[i].getMajorActor();
                    }
                    cout << endl;
               }
            }
            
        }
        */


        

    


    private:
        int size;

        vector<T> table = vector<T>(100); 
        
        


        
};
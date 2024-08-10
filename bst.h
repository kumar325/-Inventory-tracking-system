// ------------------------------ bst.h  -------------------------------------

// Rhys Fernandes CSS343 D

// 1/20/2024

// 1/27/2024

// ------------------------------------------------------------------------------------

// Purpose - This program is to implement a binary search tree using nodes.

// The BST will store either strings or numbers but not both in one tree.
// There will not be any duplicate values in the tree.

// The BST will be able to insert, retrieve, print, display, display sideways, 
//  get the height, compare between two trees, convert an array to a BST,
//  convert a BST to an array, copy a tree, and empty a tree.
// **Note: The tree will not be able to remove a node.

// -----------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------

#ifndef BST_H
#define BST_H

#include <iostream> //input and output
#include <sstream> // string stream
#include <string> // string
#include "movie.h" // movie class
using namespace std;

const int ARRAYSIZE = 100;

// BST Node contains pointer for left, right, and data
struct Node {
  Movie* movie;
  Node *left;
  Node *right;
};

class BST {

  // Overloaded << : prints BST in correct structure
  friend ostream &operator<<(ostream &, const BST &);

public:
  // Constructors
  BST();
  BST(const BST &);

  // Desctructor
  ~BST();

  // required public methods
  bool isEmpty() const; // check if tree is empty

  // retrieve the pointer of the node of given data
  bool retrieve(const Movie&, Node *&) const;

  // insert a node to the tree with the string data
  bool insert(Movie* );

  // displays the tree in pre-order, provide prefix (Root, L--, R--)
  void displayTree() const;

  // displays the tree sideways
  void displaySideways() const;

  // get height of a node starting from leaf (= 1)
  int getHeight(const Movie &) const;

  // clears the tree
  void deleteTree();

  // Overload operators
  // -- Assignment Operator
  BST &operator=(const BST &); // this = rhs
  // -- Comparison Operators
  bool operator==(const BST &) const; // this == rhs
  bool operator!=(const BST &) const; // this != rhs

private:
  Node *root; // Points to the root of the BST

  void deleteTreeHelper(Node *&);
  void copyTree(Node *&, Node *);
  void inorderHelper(ostream &os, Node *cur) const;
  void preorderHelper(Node *, int) const;
  void sidewaysHelper(Node *, int) const;
  int getHeightHelper(Node *) const;
  bool equalityHelper(Node *, Node *) const;
  bool insertHelper(Node *&, Movie*);
  bool retrieveHelper(const Movie &, Node*& , Node *&) const;

};
#endif
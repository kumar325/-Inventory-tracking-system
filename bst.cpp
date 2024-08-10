// ------------------------------ BST.cpp  ----------------------------------

// Rhys Fernandes CSS343 D

// 1/20/2024

// 1/27/2024

// ------------------------------------------------------------------------------

// Purpose - This program is to implement a binary search tree using nodes.

// The BST will store either strings or numbers but not both in one tree.
// There will not be any duplicate movies in the tree.

// The BST will be able to insert, retrieve, print, display, display sideways, 
//  get the height, compare between two trees, convert an array to a BST,
//  convert a BST to an array, copy a tree, and empty a tree.
// **Note: The tree will not be able to remove a node.

// -------------------------------------------------------------------------------

// -------------------------------------------------------------------------------

#include "bst.h"

// -----------------------------Constructor BST-------------------------------

// Description

// BST(): constructor that initializes the empty Binary Search Tree.

// preconditions: None

// postconditions: The root of the tree is set to nullptr

// -------------------------------------------------------------------------------
BST::BST()
{
    root = nullptr;
}

// -----------------------------Copy Constructor BST--------------------------

// Description

// BST(const BST &tree): copy constructor that copies the tree

// preconditions: The tree passed in is a valid tree.

// postconditions: The tree passed in is copied to the current tree.

// ------------------------------------------------------------------------------
BST::BST(const BST &tree)
{
    root = new Node;
    root->left = nullptr;
    root->right = nullptr;
    *this = tree;
}

// -----------------------------Destructor BST-------------------------------

// Description

// ~BST(): destructor that deletes the tree

// preconditions: None

// postconditions: The tree is deleted, root is set to nullptr.

// ------------------------------------------------------------------------------
BST::~BST() 
{
    deleteTree();
}

// ---------------------------------insert-------------------------------------

// Description

// insert: Inserts a node into the tree at the correct position.
//  If the movie is already in the tree, it will not be inserted.
//  If the movie is a number, it will be treated as a number, 
//   otherwise it will be treated as a string.

// preconditions: The movie passed in is a valid string. 
//  If the BST already contains strings, the movie passed in 
//   should be a string. If the BST already contains numbers,
//   the movie passed in should be a number.

// postconditions: The movie is inserted into the tree at the correct position.

// --------------------------------------------------------------------------
bool BST::insert(Movie* movie)
{
    return insertHelper(root, movie);
}

// ----------------------------getHeight-------------------------------------

// Description

// getHeight: Gets the height of the node with the given movie.
// The leaf node is of height 1 and the height increases by 1 as it 
//  goes up the tree. If movie is not found, 0 will be returned.

// preconditions: The movie passed in is a valid string.

// postconditions: The height of the node with the given movie is returned.
//  If the movie is not found, 0 is returned.

// -------------------------------------------------------------------------
int BST::getHeight(const Movie &movie) const
{
    Node* from;
    if(retrieve(movie, from))
    {
        return getHeightHelper(from);
    }
    else
    {
        return 0;
    }
    delete from;
}


// -----------------------------operator=----------------------------

// Description

// operator=: Assignment operator that copies the tree passed in to the current tree.

// preconditions: The tree passed in is a valid tree.

// postconditions: The tree passed in is copied to the current tree.

// ------------------------------------------------------------------------------------
BST &BST::operator=(const BST &other)
{
    if(*this != other)
    {
        deleteTree();
        if(other.isEmpty())
        {
            return *this;
        }
        copyTree(root, other.root);
    }
    return *this;
}

// -----------------------------operator==-------------------------------

// Description

// operator==: Comparison operator that compares two trees
//  and returns true if they are equal.

// preconditions: The tree passed in is a valid tree.

// postconditions: Returns true if the trees are equal, false otherwise.

// ----------------------------------------------------------------------
bool BST::operator==(const BST &tree) const
{
    if(root == nullptr && tree.root == nullptr)
    {
        return true;
    }
    else if(root == nullptr || tree.root == nullptr)
    {
        return false;
    }
    else
    {
        return equalityHelper(root, tree.root);
    }
}

// -----------------------------operator!=-------------------------------

// Description

// operator!=: Comparison operator that compares two trees
//  and returns true if they are not equal.

// preconditions: The tree passed in is a valid tree.

// postconditions: Returns true if the trees are not equal, false otherwise.

// ----------------------------------------------------------------------
bool BST::operator!=(const BST &other) const
{
    return !((*this) == other);
}

// -----------------------------displaySideways-------------------------------

// Description

// displaySideways: Displays the tree sideways.

// preconditions: None

// postconditions: The tree is displayed sideways.

// ----------------------------------------------------------------------------
void BST::displaySideways() const
{
    sidewaysHelper(root, 1);
}

// -----------------------------displayTree-------------------------------

// Description

// displayTree: Displays the tree in preorder. (Root, Left, Right)

// preconditions: None

// postconditions: The tree is displayed in preorder. (Root, Left, Right)

// ----------------------------------------------------------------------------
void BST::displayTree() const 
{
    preorderHelper(root, 1);
}

// -----------------------------retrieve-------------------------------

// Description

// retrieve: Retrieves the node with the given movie. The found node is
//  returned through the second parameter.
//  Returns true if found, otherwise false.

// preconditions: The movie passed in is a valid string.

// postconditions: The node with the given movie is returned.

// ----------------------------------------------------------------------------
bool BST::retrieve(const Movie& target, Node *&found) const
{
    if(isEmpty())
    {
        return false;
    }
    else if(*(root->movie) == target)
    {
        found = root;
        return true;
    }
    //if(checkIfNumber(movie) && checkIfNumber(root->movie))
    //{
        if(target < *(root->movie))
        {
            return retrieveHelper(target, root->left, found);
        }
        else
        {
            return retrieveHelper(target, root->right, found);
        }
    //}
    // else
    // {
    //     if(movie < root->movie)
    //     {
    //         return retrieveHelper(movie, root->left, found);
    //     }
    //     else
    //     {
    //         return retrieveHelper(movie, root->right, found);
    //     }
    // }
}

// -----------------------------isEmpty-------------------------------

// Description

// isEmpty: Checks if the tree is empty.

// preconditions: None

// postconditions: Returns true if the tree is empty, false otherwise.

// ----------------------------------------------------------------------------
bool BST::isEmpty() const
{
    return (root == nullptr);
}

// -----------------------------deleteTree-------------------------------

// Description

// empty: Empties the tree.

// preconditions: None

// postconditions: The tree is emptied.

// ----------------------------------------------------------------------------
void BST::deleteTree()
{
    deleteTreeHelper(root);
}

// -----------------------------operator<<-------------------------------

// Description

// operator<<: Overloaded operator that prints the tree inorder to the outstream.
// (Left, Root, Right)

// preconditions: None

// postconditions: The tree is printed in order.

// ----------------------------------------------------------------------------
ostream &operator<<(ostream &os, const BST &tree)
{
    tree.inorderHelper(os, tree.root);
    return os;
}

// -----------------------------insertHelper-------------------------------

// Description

// insertHelper: Helper function for insert that inserts a node into the tree
//  at the correct position.
// If the movie is already in the tree, it will not be inserted.

// preconditions: The movie passed in is a valid string.

// postconditions: The movie is inserted into the tree at the correct position.

// --------------------------------------------------------------------------
bool BST::insertHelper(Node *&root, Movie *movie) {
    if(root == nullptr){
        Node* insertNode = new Node;
        insertNode->movie = (movie);
        insertNode->left = nullptr;
        insertNode->right = nullptr;
        root = insertNode;
        return true;
    }
    // Checks for duplicates and wrong types
    else if(*(movie) == *root->movie)
    {
    }
    // //if(checkIfNumber(movie) && checkIfNumber(root->movie))
    // //{
    //     if(stoi(movie) < stoi(root->movie)){
    //         return insertHelper(root->left, movie);
    //     }
    //     else{
    //         return insertHelper(root->right, movie);
    //     }
    // //}
    //else{
        if(*movie < *root->movie){
            return insertHelper(root->left, movie);
        }
        else{
            return insertHelper(root->right, movie);
        }
    //}
}



// -----------------------------retrieveHelper-------------------------------

// Description

// retrieveHelper: Helper function for retrieve that retrieves the node with the given movie.

// preconditions: The movie passed in is a valid string.

// postconditions: The node with the given movie is returned.

// --------------------------------------------------------------------------
bool BST::retrieveHelper(const Movie &movie, Node *&cur, Node *&found) const
{
    if(cur == nullptr)
    {
        return false;
    }
    else if(*cur->movie == movie)
    {
        found = cur;
        return true;
    }
    // if(checkIfNumber(movie) && checkIfNumber(cur->movie))
    // {
    //     if(stoi(movie) < stoi(cur->movie))
    //     {
    //         return retrieveHelper(movie, cur->left, found);
    //     }
    //     else
    //     {
    //         return retrieveHelper(movie, cur->right, found);
    //     }
    // }
    // else
    // {
        if(movie < *cur->movie)
        {
            return retrieveHelper(movie, cur->left, found);
        }
        else
        {
            return retrieveHelper(movie, cur->right, found);
        }
    //}
}

// -----------------------------deleteTreeHelper-------------------------------

// Description

// deleteTreeHelper: Helper function for empty that empties the tree.

// preconditions: None

// postconditions: The tree is emptied.

// --------------------------------------------------------------------------
void BST::deleteTreeHelper(Node *&cur) 
{
    if(cur != nullptr)
    {
        deleteTreeHelper(cur->left);
        deleteTreeHelper(cur->right);
        delete cur;
        cur = nullptr;
    }
}

// -----------------------------inorderHelper-------------------------------

// Description

// inorderHelper: Helper function for operator<< that prints the tree inorder
//  to the outstream. (Left, Root, Right)

// preconditions: None

// postconditions: The tree is printed in order.

// --------------------------------------------------------------------------
void BST::inorderHelper(ostream& os, Node *cur) const
{
    if(cur != nullptr)
    {
        inorderHelper(os, cur->left);
        os << cur->movie << " ";
        inorderHelper(os, cur->right);
    }
}

// -----------------------------preorderHelper-------------------------------

// Description

// preorderHelper: Helper function for displayTree that displays the tree in preorder.

// preconditions: None

// postconditions: The tree is displayed in preorder. (Root, Left, Right)

// --------------------------------------------------------------------------
void BST::preorderHelper(Node *cur, int level) const
{
    
    if(cur != nullptr)
    {
        if(level == 1)
        {
            cout << *cur->movie << endl;
            preorderHelper(cur->left, level + 1);
            preorderHelper(cur->right, level + 1);
        }
        else if(cur != nullptr)
        {
            for(int i = 0; i < level; i++)
            {
                //cout << "     ";
            }
            cout << *cur->movie << endl;
            preorderHelper(cur->left, level + 1);
            preorderHelper(cur->right, level + 1);
        }
    }
}

// -----------------------------sidewaysHelper-------------------------------

// Description

// sidewaysHelper: Helper function for displaySideways that displays the tree sideways.

// preconditions: None

// postconditions: The tree is displayed sideways.

// --------------------------------------------------------------------------
void BST::sidewaysHelper(Node *cur, int level) const
{
    if(cur != nullptr)
    {
        sidewaysHelper(cur->right, level + 1);
        for(int i = 0; i < level + 1; i++)
        {
            cout << "     ";
        }
        cout << cur->movie << endl;
        sidewaysHelper(cur->left, level + 1);
    }
}

// -----------------------------getHeightHelper-------------------------------

// Description

// getHeightHelper: Helper function for getHeight that gets the height of the node

// preconditions: The movie passed in is a valid string.

// postconditions: The height of the node with the given movie is returned.

// --------------------------------------------------------------------------
int BST::getHeightHelper(Node *cur) const {
    if(cur == nullptr)
    {
        return 0;
    }
    else if(cur->left == nullptr && cur->right == nullptr)
    {
        return 1;
    }
    else
    {
        return 1 + max(getHeightHelper(cur->left), getHeightHelper(cur->right));
    }
}

// -----------------------------equalityHelper-------------------------------

// Description

// equalityHelper: Helper function for operator== that compares two trees

// preconditions: The tree passed in is a valid tree.

// postconditions: Returns true if the trees are equal, false otherwise.

// --------------------------------------------------------------------------
bool BST::equalityHelper(Node *cur, Node *other) const
{
    if(cur == nullptr && other == nullptr)
    {
        return true;
    }
    else if(cur == nullptr || other == nullptr)
    {
        return false;
    }
    else if(cur->movie != other->movie)
    {
        return false;
    }
    else
    {
        return equalityHelper(cur->left, other->left) && equalityHelper(cur->right, other->right);
    }
}

// -----------------------------copyTree-------------------------------

// Description

// copyTree: Helper function for operator= that copies the tree passed in to the current tree.

// preconditions: The tree passed in is a valid tree.

// postconditions: The tree passed in is copied to the current tree.

// --------------------------------------------------------------------------
void BST::copyTree(Node*& cur, Node* other)
{
    if(other == nullptr)
    {
        cur = nullptr;
    }
    else
    {
        cur = new Node;
        cur->movie = other->movie;
        cur->left = nullptr;
        cur->right = nullptr;
        copyTree(cur->left, other->left);
        copyTree(cur->right, other->right);
    }
}

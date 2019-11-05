#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
using std::sort;
using std::get;
using std::vector;
using std::tuple;
using std::make_tuple;

using namespace std;

class MyTree;

class BinaryNode {
public:
  BinaryNode(string s, int m) : myString(s), myInt(m), lchild(0), rchild(0), parent(0) {};
  ~BinaryNode() {};
  int getInt() const {return myInt;};
  string getString() const {return myString;};
private:
  string myString;
  int    myInt;
  BinaryNode *lchild;
  BinaryNode *rchild;
  BinaryNode *parent;
  friend class MyTree;
};


class MyTree {
public:
  MyTree();
  ~MyTree();

  // Insert new node into first available position (to keep the tree almost complete).
  void insert (int x ,string s);

  //Output all strings in pre-order 
  //all the strings will be print in one line separated by spaces
  void preorder() const;
  // helper for having the same clean definitions for preorder
  void preorderHelper(BinaryNode*)const;

  //Returns a pointer to the node with maximum myInt
  BinaryNode *findMax() const;

  // Helper for findMax
  BinaryNode *findMaxHelper(BinaryNode*) const;
  // Converts the binary tree into a binary search tree (BST) with respect to myInt. 
  // That is, move around node values (myString and myInt) to satisfy the BST property.
  void makeBST();


private:
  BinaryNode *root;
  BinaryNode *nextInsertRoot;

  void storeInorder(BinaryNode*, vector<tuple<int, string>> &);
  void resetValuesInorder(vector<tuple<int, string>> &, BinaryNode*);
};


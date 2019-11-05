#include "MyTree.h"

MyTree::MyTree() : root(0), nextInsertRoot(0) {}

MyTree::~MyTree() {}

void MyTree::insert(int x, string s) {
    BinaryNode* to_insert = new BinaryNode(s, x);
    if(!this->root){
        this->root = to_insert;
        this->nextInsertRoot = root;
    }
    else{
        if(!this->nextInsertRoot->lchild){
            this->nextInsertRoot->lchild = to_insert;
            to_insert->parent = this->nextInsertRoot;
        }
        else if(!this->nextInsertRoot->rchild){
            this->nextInsertRoot->rchild = to_insert;
            to_insert->parent = this->nextInsertRoot;
            // if parent is a left child, next location is parent's right child
            if(this->nextInsertRoot->parent && this->nextInsertRoot->parent->lchild == this->nextInsertRoot){
                this->nextInsertRoot = this->nextInsertRoot->parent->rchild;
            }
            // if parent is right child, two scenarios
            else{
                // here we traverse parents until the first left parent is found (if can be found) 
                BinaryNode* temp = this->nextInsertRoot;
                while(temp->parent && temp->parent->lchild != temp)
                    temp = temp->parent;
                // left child parent not found, now temp is root, go to deepest left child
                if(!temp->parent){
                    while(temp->lchild)
                        temp = temp->lchild;
                    this->nextInsertRoot = temp;
                }
                // left child found
                else
                    this->nextInsertRoot = temp->parent->rchild->lchild;
            }
        }
    }
}

void MyTree::preorder() const {
    this->preorderHelper(this->root);
}

void MyTree::preorderHelper(BinaryNode* node) const {
    if(node){
        cout << node->getString() << " ";
        preorderHelper(node->lchild);
        preorderHelper(node->rchild);
    }
}

BinaryNode* MyTree::findMax() const { 
    return findMaxHelper(this->root);
}

BinaryNode* MyTree::findMaxHelper(BinaryNode* node) const { 
    if(node){
        int current = node->myInt;
        BinaryNode* leftMax = findMaxHelper(node->lchild);
        BinaryNode* rightMax = findMaxHelper(node->rchild);
        int lMax = INT16_MIN, rMax = INT16_MIN;
        if (leftMax)
            lMax = leftMax->getInt();
        if (rightMax)
            rMax = rightMax->getInt();
        if (lMax > rMax && lMax > current)
            return leftMax; 
        else if(rMax >= lMax && rMax > current)
            return rightMax;
        return node;
    }
    return nullptr;
}

void MyTree::storeInorder(BinaryNode* node, vector<tuple<int, string>> &curr) {
    if (node){
        this->storeInorder(node->lchild, curr);
        curr.push_back(make_tuple(node->myInt, node->myString));
        this->storeInorder(node->rchild, curr);
    }
}

void MyTree::resetValuesInorder(vector<tuple<int, string>> &tree, int* currIndex, BinaryNode* node){
    if (node){
        this->resetValuesInorder(tree, currIndex, node->lchild);
        node->myInt = get<0>(tree.at(*currIndex));
        node->myString = get<1>(tree.at(*currIndex));
        *currIndex = *currIndex + 1;
        this->resetValuesInorder(tree, currIndex, node->rchild);
    }
}

void MyTree::makeBST() {
    // since inorder traversal of BST is a sorted array, we inorder our BT, sort its nodes and change their values inorder
    // store tree inorder
    vector<tuple<int, string>> tree;
    this->storeInorder(this->root, tree);
    // sort in ascending order
    sort(tree.begin(), tree.end());
    // store it back
    int start_index = 0;
    this->resetValuesInorder(tree, &start_index, this->root);
}

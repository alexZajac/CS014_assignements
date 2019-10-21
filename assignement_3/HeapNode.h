#include <iostream>

using namespace std;

template<class T> 
class HeapNode
{
    private:
        T value;
        HeapNode* parent;
        HeapNode* leftChild;
        HeapNode* rightChild;
        HeapNode* previous;

    public:
        HeapNode(T);
        HeapNode<T>* GetParent();
        void Insert(HeapNode*, HeapNode**, HeapNode**);
        void Remove(HeapNode**, HeapNode**);
        bool IsLeaf();
        void trickleDown(HeapNode*);
        ~HeapNode();
};

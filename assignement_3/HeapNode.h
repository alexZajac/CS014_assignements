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
        T GetValue();
        HeapNode<T>* GetParent();
        HeapNode<T>* GetLeftChild();
        HeapNode<T>* GetRightChild();
        HeapNode<T>* GetPrevious();
        void Insert(HeapNode*, HeapNode**, HeapNode**);
        void DeleteMin(HeapNode**, HeapNode**);
        bool IsLeaf();
        void trickleDown(HeapNode*);
        ~HeapNode();
};

#include <iostream>

using namespace std;

template<class T> 
class PointerHeap
{
    private:
        HeapNode<T>* root;
        HeapNode<T>* last;

    public:
        PointerHeap();
        ~PointerHeap();
        HeapNode<T>* GetRoot();
        HeapNode<T>* GetLast();
        void Insert(T);
        void DeleteMin();

};

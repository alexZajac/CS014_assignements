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
        void Insert(T);
        void Remove();

};

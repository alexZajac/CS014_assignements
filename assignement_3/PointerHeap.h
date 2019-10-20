#include <iostream>

using namespace std;

template<class T> 
class PointerHeap
{
    private:
        T value;
        PointerHeap* parent;
        PointerHeap* leftChild;
        PointerHeap* rightChild;

    public:
        PointerHeap(T);
        PointerHeap<T>* GetParent();
        void Insert(PointerHeap*,PointerHeap*,bool,bool);
        bool IsLeaf(PointerHeap*);
        void trickleDown(PointerHeap*,PointerHeap*);
        ~PointerHeap();
};

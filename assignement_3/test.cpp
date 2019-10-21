#include "Sort.h"
#include "PointerHeap.cpp"
#include "IntCell.h"
#include "gtest/gtest.h"
using std::string;

TEST(PointerHeap, EmptyHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    EXPECT_EQ(heap->GetLast(), nullptr);
    EXPECT_EQ(heap->GetRoot(), nullptr);
}

TEST(PointerHeap, OneNodeHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(0));
    EXPECT_EQ(heap->GetLast(), heap->GetRoot());
}

TEST(PointerHeap, TwoNodeLastHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(0));
    heap->Insert(*new IntCell(1));
    EXPECT_EQ(heap->GetLast()->GetPrevious(), heap->GetRoot());
}

TEST(PointerHeap, ThreeNodeParentHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(0));
    heap->Insert(*new IntCell(1));
    heap->Insert(*new IntCell(2));
    EXPECT_EQ(heap->GetLast()->GetParent(), heap->GetRoot());
    EXPECT_EQ(heap->GetLast()->GetPrevious()->GetParent(), heap->GetRoot());
}


TEST(PointerHeap, RootChildHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(0));
    heap->Insert(*new IntCell(1));
    heap->Insert(*new IntCell(2));
    heap->Insert(*new IntCell(3));
    heap->Insert(*new IntCell(4));
    heap->Insert(*new IntCell(5));
    heap->Insert(*new IntCell(6));
    heap->Insert(*new IntCell(7));
    heap->Insert(*new IntCell(8));
    EXPECT_EQ(heap->GetRoot()->GetLeftChild()->GetLeftChild()->GetRightChild(), heap->GetLast());
}

TEST(PointerHeap, RootValueHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(10));
    heap->Insert(*new IntCell(24));
    heap->Insert(*new IntCell(2));
    heap->Insert(*new IntCell(7));
    heap->Insert(*new IntCell(1));
    heap->Insert(*new IntCell(8));
    heap->Insert(*new IntCell(14));
    heap->Insert(*new IntCell(69));
    heap->Insert(*new IntCell(9));
    heap->Insert(*new IntCell(24));
    heap->Insert(*new IntCell(32));
    heap->Insert(*new IntCell(16));
    heap->Insert(*new IntCell(8));
    heap->Insert(*new IntCell(29));
    heap->Insert(*new IntCell(5));
    heap->Insert(*new IntCell(4));
    IntCell* foo = new IntCell(0);
    heap->Insert(*foo);
    heap->Insert(*new IntCell(28));
    EXPECT_EQ(heap->GetRoot()->GetValue().getValue(),foo->getValue());
}

TEST(PointerHeap, RootValueWithRemoveHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(10));
    heap->Insert(*new IntCell(24));
    IntCell* foo = new IntCell(2);
    heap->Insert(*foo);
    heap->Insert(*new IntCell(2));
    heap->Insert(*new IntCell(7));
    heap->Insert(*new IntCell(1));
    heap->Insert(*new IntCell(8));
    heap->Insert(*new IntCell(14));
    heap->Insert(*new IntCell(69));
    heap->Insert(*new IntCell(9));
    heap->Insert(*new IntCell(24));
    heap->Insert(*new IntCell(32));
    heap->Insert(*new IntCell(16));
    heap->Insert(*new IntCell(8));
    heap->Insert(*new IntCell(29));
    heap->Insert(*new IntCell(5));
    heap->Insert(*new IntCell(4));
    heap->Insert(*new IntCell(0));
    heap->Insert(*new IntCell(28));
    heap->DeleteMin();
    heap->DeleteMin();
    EXPECT_EQ(heap->GetRoot()->GetValue().getValue(),foo->getValue());
}


TEST(PointerHeap, InsertRemoveHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->Insert(*new IntCell(10));
    heap->Insert(*new IntCell(24));
    heap->Insert(*new IntCell(2));
    heap->DeleteMin();
    heap->DeleteMin();
    heap->DeleteMin();
    EXPECT_EQ(heap->GetLast(), nullptr);
    EXPECT_EQ(heap->GetRoot(), nullptr);
}

TEST(PointerHeap, RemoveEmptyHeap)
{
    PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
    heap->DeleteMin();
    heap->DeleteMin();
    heap->DeleteMin();
    heap->DeleteMin();
    heap->DeleteMin();
    heap->DeleteMin();
    EXPECT_EQ(heap->GetLast(), nullptr);
    EXPECT_EQ(heap->GetRoot(), nullptr);
}

TEST(Sorting, CheckIfSortingMergeSort)
{
    int count = 0;
    while (count < 10)
    {    
        int startSize = 1000000;
        int* arr = generateRandomArray(startSize);
        arr = mergeSort(arr, startSize);
        for (int i = 0; i < startSize-1; i++)
        {
            ASSERT_LE(arr[i], arr[i+1]);
        }
        delete[] arr;
        count++;
    }
}

TEST(Sorting, SortingOneMergeSort)
{
    int startSize = 1;
    int* arr = generateRandomArray(startSize);
    arr = mergeSort(arr, startSize);
    delete[] arr;
}

TEST(Sorting, SortingOddMergeSort)
{
    int startSize = 111111;
    int* arr = generateRandomArray(startSize);
    arr = mergeSort(arr, startSize);
    delete[] arr;
}

TEST(Sorting, SortingEvenMergeSort)
{
    int startSize = 111110;
    int* arr = generateRandomArray(startSize);
    arr = mergeSort(arr, startSize);
    delete[] arr;
}

TEST(Sorting, CheckIfSortingQuickSort)
{    
    int count = 0;
    while (count < 10)
    {    
        int startSize = 1000000;
        int* arr = generateRandomArray(startSize);
        quickSort(arr, 0, startSize-1);
        for (int i = 0; i < startSize-1; i++)
        {
            ASSERT_LE(arr[i], arr[i+1]);
        }
        delete[] arr;
        count++;
    }
    
}

TEST(Sorting, CheckIfSortingHeapSort)
{
    int count = 0;
    while (count < 10)
    {    
        int startSize = 1000000;
        int* arr = generateRandomArray(startSize);
        heapSort(arr,startSize);
        for (int i = 0; i < startSize-1; i++)
        {
            ASSERT_LE(arr[i], arr[i+1]);
        }
        delete[] arr;
        count++;
    }
    
}

TEST(Sorting, CheckIfSortingInsertionSort)
{
    int count = 0;
    while (count < 10)
    {    
        int startSize = 10000;
        int* arr = generateRandomArray(startSize);
        insertionSort(arr, startSize);
        for (int i = 0; i < startSize-1; i++)
        {
            ASSERT_LE(arr[i], arr[i+1]);
        }
        delete[] arr;
        count++;
    }
    
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
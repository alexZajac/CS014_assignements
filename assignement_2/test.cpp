#include "PriorityQueue.h"
#include "DoubleStack.h";
#include "gtest/gtest.h";
using std::string;

TEST(PriorityQueueTest, EnqueueEmpty)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    PriorityQueue *newNode = new PriorityQueue(12);
    dummyHead->Enqueue(newNode);
    EXPECT_EQ(dummyHead->GetNext(), newNode);
}

TEST(PriorityQueueTest, DequeueEmpty)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    testing::internal::CaptureStdout();
    dummyHead->Dequeue();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is empty.\n");
}

TEST(PriorityQueueTest, HasPriority)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    PriorityQueue *newNode1 = new PriorityQueue(1);
    PriorityQueue *newNode2 = new PriorityQueue(2);
    PriorityQueue *newNode3 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode1);
    dummyHead->Enqueue(newNode2);
    dummyHead->Enqueue(newNode3);
    const PriorityQueue *toTest = dummyHead->GetNext();
    EXPECT_EQ(toTest, newNode3);
}

TEST(PriorityQueueTest, DequeueNotEmpty)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    PriorityQueue *newNode1 = new PriorityQueue(1);
    PriorityQueue *newNode2 = new PriorityQueue(2);
    PriorityQueue *newNode3 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode1);
    dummyHead->Enqueue(newNode2);
    dummyHead->Enqueue(newNode3);
    dummyHead->Dequeue();
    EXPECT_EQ(dummyHead->GetNext(), newNode1);
}

TEST(PriorityQueueTest, EnqueueTenthNext)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    PriorityQueue *newNode1 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode1);
    PriorityQueue *newNode2 = new PriorityQueue(2);
    dummyHead->Enqueue(newNode2);
    PriorityQueue *newNode3 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode3);
    PriorityQueue *newNode4 = new PriorityQueue(4);
    dummyHead->Enqueue(newNode4);
    PriorityQueue *newNode5 = new PriorityQueue(5);
    dummyHead->Enqueue(newNode5);
    PriorityQueue *newNode6 = new PriorityQueue(6);
    dummyHead->Enqueue(newNode6);
    PriorityQueue *newNode7 = new PriorityQueue(7);
    dummyHead->Enqueue(newNode7);
    PriorityQueue *newNode8 = new PriorityQueue(8);
    dummyHead->Enqueue(newNode8);
    PriorityQueue *newNode9 = new PriorityQueue(9);
    dummyHead->Enqueue(newNode9);
    PriorityQueue *newNode10 = new PriorityQueue(10);
    dummyHead->Enqueue(newNode10);
    PriorityQueue *newNode11 = new PriorityQueue(11);
    dummyHead->Enqueue(newNode11);
    const PriorityQueue *toTest = dummyHead->GetNext();
    EXPECT_EQ(toTest->GetTenthNext(), newNode11);
}

TEST(PriorityQueueTest, EnqueueHighPriorityTenthNext)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    PriorityQueue *newNode1 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode1);
    PriorityQueue *newNode2 = new PriorityQueue(2);
    dummyHead->Enqueue(newNode2);
    PriorityQueue *newNode3 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode3);
    PriorityQueue *newNode4 = new PriorityQueue(4);
    dummyHead->Enqueue(newNode4);
    PriorityQueue *newNode5 = new PriorityQueue(5);
    dummyHead->Enqueue(newNode5);
    PriorityQueue *newNode6 = new PriorityQueue(6);
    dummyHead->Enqueue(newNode6);
    PriorityQueue *newNode7 = new PriorityQueue(7);
    dummyHead->Enqueue(newNode7);
    PriorityQueue *newNode8 = new PriorityQueue(8);
    dummyHead->Enqueue(newNode8);
    PriorityQueue *newNode9 = new PriorityQueue(9);
    dummyHead->Enqueue(newNode9);
    PriorityQueue *newNode10 = new PriorityQueue(10);
    dummyHead->Enqueue(newNode10);
    PriorityQueue *newNode11 = new PriorityQueue(11);
    dummyHead->Enqueue(newNode11);
    PriorityQueue *newNode12 = new PriorityQueue(4);
    dummyHead->Enqueue(newNode12);
    const PriorityQueue *toTest = dummyHead->GetNext();
    EXPECT_EQ(toTest->GetTenthNext(), newNode10);
}

TEST(PriorityQueueTest, DequeueTenthNext)
{
    PriorityQueue *dummyHead = new PriorityQueue(-1);
    PriorityQueue *newNode1 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode1);
    PriorityQueue *newNode2 = new PriorityQueue(2);
    dummyHead->Enqueue(newNode2);
    PriorityQueue *newNode3 = new PriorityQueue(1);
    dummyHead->Enqueue(newNode3);
    PriorityQueue *newNode4 = new PriorityQueue(4);
    dummyHead->Enqueue(newNode4);
    PriorityQueue *newNode5 = new PriorityQueue(5);
    dummyHead->Enqueue(newNode5);
    PriorityQueue *newNode6 = new PriorityQueue(6);
    dummyHead->Enqueue(newNode6);
    PriorityQueue *newNode7 = new PriorityQueue(7);
    dummyHead->Enqueue(newNode7);
    PriorityQueue *newNode8 = new PriorityQueue(8);
    dummyHead->Enqueue(newNode8);
    PriorityQueue *newNode9 = new PriorityQueue(9);
    dummyHead->Enqueue(newNode9);
    PriorityQueue *newNode10 = new PriorityQueue(10);
    dummyHead->Enqueue(newNode10);
    PriorityQueue *newNode11 = new PriorityQueue(11);
    dummyHead->Enqueue(newNode11);
    PriorityQueue *newNode12 = new PriorityQueue(4);
    dummyHead->Enqueue(newNode12);
    dummyHead->Dequeue();
    const PriorityQueue *toTest = dummyHead->GetNext();
    EXPECT_EQ(toTest->GetTenthNext(), newNode11);
}

TEST(DoubleStackTest, EmptyFirstStack)
{
    DoubleStack<int> dStack;
    dStack.pushSecond(2);
    EXPECT_EQ(dStack.emptyFirst(), true);
}

TEST(DoubleStackTest, EmptySecondStack)
{
    DoubleStack<int> dStack;
    dStack.pushFirst(2);
    EXPECT_EQ(dStack.emptySecond(), true);
}

TEST(DoubleStackTest, PeekFirstStack)
{
    DoubleStack<int> dStack;
    dStack.pushSecond(2);
    dStack.pushFirst(2);
    dStack.pushFirst(7);
    EXPECT_EQ(dStack.peekFirst(), 7);
}

TEST(DoubleStackTest, PeekDefaultSecondStack)
{
    DoubleStack<int> dStack;
    dStack.pushFirst(2);
    dStack.pushFirst(7);
    EXPECT_EQ(dStack.peekSecond(), int());
}

TEST(DoubleStackTest, DoubleArrayFirstElt)
{
    DoubleStack<int> dStack;
    dStack.pushSecond(2);
    EXPECT_EQ(dStack.GetSize(), 3);
}

TEST(DoubleStackTest, DoubleArray)
{
    DoubleStack<int> dStack;
    dStack.pushFirst(2);
    dStack.pushSecond(2);
    EXPECT_EQ(dStack.GetSize(), 6);
}

TEST(DoubleStackTest, PushFirst)
{
    DoubleStack<int> dStack;
    dStack.pushFirst(2);
    dStack.pushFirst(4);
    dStack.pushSecond(7);
    const int *toTest = dStack.GetData();
    int defaultInt = int();
    int arrayCompare[6] = {2, 4, defaultInt, defaultInt, defaultInt, 7};
    int *toCompare = arrayCompare;
    EXPECT_EQ(dStack.GetSize(), 6);
    for (int i = 0; i < 6; ++i)
    {
        EXPECT_EQ(*(toTest + i), *(toCompare + i));
    }
}

TEST(DoubleStackTest, PushSecond)
{
    DoubleStack<char> dStack;
    dStack.pushFirst('2');
    dStack.pushFirst('3');
    dStack.pushFirst('4');
    dStack.pushSecond('4');
    dStack.pushSecond('7');
    dStack.pushSecond('8');
    dStack.pushSecond('9');
    char defaultChar = char();
    const char *toTest = dStack.GetData();
    int arrayCompare[12] = {'2', '3', '4', defaultChar, defaultChar, defaultChar, defaultChar, defaultChar, '9', '8', '7', '4'};
    int *toCompare = arrayCompare;
    EXPECT_EQ(dStack.GetSize(), 12);
    for (int i = 0; i < 12; ++i)
    {
        EXPECT_EQ(*(toTest + i), *(toCompare + i));
    }
}

TEST(DoubleStackTest, PopFirst)
{
    DoubleStack<int> dStack;
    dStack.pushFirst(2);
    dStack.pushSecond(2);
    dStack.popFirst();
    EXPECT_EQ(dStack.GetFirstSize(), 0);
}

TEST(DoubleStackTest, PopSecond)
{
    DoubleStack<int> dStack;
    dStack.pushFirst(2);
    dStack.pushSecond(2);
    dStack.pushSecond(4);
    dStack.popSecond();
    EXPECT_EQ(dStack.GetSecondSize(), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
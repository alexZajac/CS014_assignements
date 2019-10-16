#include "PriorityQueue.h"
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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
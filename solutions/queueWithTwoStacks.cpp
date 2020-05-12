#include <iostream>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// fill in the definitions for enqueue() and dequeue()

//MY CODE
//Time Complexity O(n)
//Space Complexity O(n)
class QueueTwoStacks
{
private:
    stack<int> inStack_;
    stack<int> outStack_;

public:
    void enqueue(int item)
    {
        //either enqueue or dequeue needs to be O(n)
        //chose dequeue to be O(n)
        //and made enqueue a simple push
        inStack_.push(item);
    }

    int dequeue()
    {
        //to dequeue correctly, we will use the other stack to change from LIFO to FIFO
        //check if outstack is empty
        if(outStack_.empty()){
            //if it is empty and instack is NOT empty
            while(!inStack_.empty()){
                //we push that item to outstack
                //to do that we get the item from top and pop from instack
                //then push to outstack
                int item = inStack_.top();
                inStack_.pop();
                outStack_.push(item);
            }
        }  
        //we then check if it is still empty we throw an exception since we cannot dequeue
        if(outStack_.empty()) throw "Stack is empty! Cannot dequeue.";

        //then we delete from the outstack using top and pop
        int del = outStack_.top();
        outStack_.pop();
        return del;
    }
};


















// tests

const lest::test tests[] = {
    {CASE("basic queue operations") {
        QueueTwoStacks q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        EXPECT(q.dequeue() == 1);
        EXPECT(q.dequeue() == 2);
        q.enqueue(4);
        EXPECT(q.dequeue() == 3);
        EXPECT(q.dequeue() == 4);
    }},
    {CASE("exception when dequeue from new queue") {
        QueueTwoStacks q;
        EXPECT_THROWS(q.dequeue());
    }},
    {CASE("exception when dequeue from empty queue") {
        QueueTwoStacks q;
        q.enqueue(1);
        q.enqueue(2);
        q.dequeue();
        q.dequeue();
        EXPECT_THROWS(q.dequeue());
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
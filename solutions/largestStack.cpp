#include <iostream>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// fill in the definitions for push(), pop(), and getMax()

//MY CODE
//Time Complexity O(1) for all
//Space Complexity O(1) for all
class MaxStack
{
public:
    void push(int item)
    {
        //check is max stack is empty or the item is larger than the top item in stack
        //if it is them put it in stack (this will now be largest)
        if(maxS.empty() || item >= maxS.top()) maxS.push(item);
        
        //always push to normal stack
        s.push(item);
    }

    int pop()
    {
        //we want to always pop fron normal stack
        //get top to get variable
        //pop fron stack
        int temp = s.top();
        s.pop();

        //check is the top from regular stack is same as maxstack
        //if they are the same then we should pop both (otherwise that item was never in maxstack)
        if(temp == maxS.top()) maxS.pop();
        return temp;
    }

    int getMax() const
    {
        //the max item should be the top of the maxstack
        return maxS.top();
    }
    
private:
    //use two stacks
    //one for regular use, the other for keeping track of the max
    stack<int> s;
    stack<int> maxS;
};


















// tests

const lest::test tests[] = {
    {CASE("MaxStack test") {
        MaxStack s;
        s.push(5);
        EXPECT(s.getMax() == 5);
        s.push(4);
        s.push(7);
        s.push(7);
        s.push(8);
        EXPECT(s.getMax() == 8);
        EXPECT(s.pop() == 8);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 5);
        EXPECT(s.pop() == 4);
        EXPECT(s.getMax() == 5);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
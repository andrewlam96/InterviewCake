#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    // check if we're serving orders first-come, first-served

    //These if statements check if either vector are empty
    //if they are then we directly compare the other vector
    if(takeOutOrders.empty()) return servedOrders == dineInOrders;
    if(dineInOrders.empty()) return servedOrders == takeOutOrders;
    
    int takeOutIndex = 0, dineInIndex = 0; //indices for the takeout and dinein vectors
    //want to loop through all values in served Orders vector
    for(int s : servedOrders){
        //first check if the index of takeout is less than the vector size
        //then it checks if that value is the same as the current value of s
        if(takeOutIndex < takeOutOrders.size() && s == takeOutOrders[takeOutIndex])
            ++takeOutIndex; //if it is, increase the index
        //similarly do the same thing for dinein index / vector
        else if(dineInIndex < dineInOrders.size() && s == dineInOrders[dineInIndex])
            ++dineInIndex; //increment the index if it is the same as s
        //it has to be one of those two cases, so if it isn't we will return false
        else return false; 
    }
    
    //this statement checks if either vector still has any remaining values that have not been checked
    //if they do, we return false since that means there was not enough values in servedOrders
    //otherwise we return true
    return takeOutIndex < takeOutOrders.size() || dineInIndex < dineInOrders.size() ? false : true;
}


















// tests

const lest::test tests[] = {
    {CASE("both registers have same number of orders") {
        const vector<int> takeOutOrders {1, 4, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 4, 5, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("registers have different lengths") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register is empty") {
        const vector<int> takeOutOrders;
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {2, 3, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("served orders is missing orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("served orders has extra orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 5, 6, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has extra orders") {
        const vector<int> takeOutOrders {1, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has unserved orders") {
        const vector<int> takeOutOrders {55, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8, 9};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
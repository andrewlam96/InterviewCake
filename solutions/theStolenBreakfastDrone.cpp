#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
int findUniqueDeliveryId(const vector<int>& deliveryIds)
{
    // find the one unique ID in the vector
    int uniqueId = 0;
    //since we want to find the one id different
    //and all other id have 2 that are the same
    //we can use XOR since a pair will cancel out to be 0
    //leaving the uniqueID as our solution
    for(auto &i : deliveryIds){
        uniqueId ^= i;
    }
    return uniqueId;

    return 0;
}


















// tests

const lest::test tests[] = {
    {CASE("one drone") {
        const int expected = 1;
        const int actual = findUniqueDeliveryId(vector<int> {1});
        EXPECT(actual == expected);
    }},
    {CASE("unique ID comes first") {
        const int expected = 1;
        const int actual = findUniqueDeliveryId(vector<int> {1, 2, 2});
        EXPECT(actual == expected);
    }},
    {CASE("unique ID comes last") {
        const int expected = 1;
        const int actual = findUniqueDeliveryId(vector<int> {3, 3, 2, 2, 1});
        EXPECT(actual == expected);
    }},
    {CASE("unique ID in middle") {
        const int expected = 1;
        const int actual = findUniqueDeliveryId(vector<int> {3, 2, 1, 2, 3});
        EXPECT(actual == expected);
    }},
    {CASE("many drones") {
        const int expected = 8;
        const int actual = findUniqueDeliveryId(
            vector<int> {2, 5, 4, 8, 6, 3, 1, 4, 2, 3, 6, 5, 1});
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
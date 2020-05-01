#include <iostream>
#include <string>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(log n)
//Space Complexity O(1)
size_t findRotationPoint(const vector<string>& words)
{
    // find the rotation point in the array
    int pivot, left = 0, right = words.size() - 1;
    
    //only want to keep looping when left < right
    while(left < right){
        pivot = left + (right - left) / 2; //get pivot
        //if the word is >= the first word we want to check right half (means in order)
        if(words[pivot] >= words[0]) left = pivot;
        //otherwise check left half
        else right = pivot;
        //if the left + 1 is equal to the right index we break
        if(left + 1 == right) break;
    }
    //want right index since left index should be 1 before the rotation point
    return right;
}


















// tests

const lest::test tests[] = {
    {CASE("small array") {
        const vector<string> words {"cape", "cake"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 1;
        EXPECT(actual == expected);
    }},
    {CASE("medium array") {
        const vector<string> words {"grape", "orange", "plum", "radish", "apple"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 4;
        EXPECT(actual == expected);
    }},
    {CASE("large array") {
        const vector<string> words {"ptolemaic", "retrograde", "supplant", "undulate",
            "xenoepist", "asymptote", "babka", "banoffee", "engender", "karpatka",
            "othellolagkage"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 5;
        EXPECT(actual == expected);
    }},
    {CASE("possibly missing edge case") {
        // are we missing any edge cases?

    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
//idea is to store the highest, lowest, highest product of 2, lowest product of 2, and highest product of 3
int highestProductOf3(const vector<int>& vectorOfInts)
{
    // calculate the highest product of three numbers
    if(vectorOfInts.size() < 3) throw "Size is not large enough"
    
    //These are the highest and lowest numbers initially
    //Note we don't need to check index 2 because we will start there anyways in loop
    int highest = max(vectorOfInts[0], vectorOfInts[1]);
    int lowest = min(vectorOfInts[0], vectorOfInts[1]);
    
    //the highest and lowest product will be the same initially
    int highestProduct2 = vectorOfInts[0] * vectorOfInts[1];
    int lowestProduct2 = vectorOfInts[0] * vectorOfInts[1];
    
    //this will be our base case for highest product of 3
    int highestProduct3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];
    
    //we want to start at index 2 and loop until the end
    for(int i = 2; i < vectorOfInts.size(); ++i){
        int current = vectorOfInts[i]; //variabale to store current value (not neccesarily needed)

        //we want to start from largest to smallest since the numbers depend on smaller things
        //i.e. productof3 might depend of productof2 so we don't want to change it first
        //highestproductof3 we just check what is largest max of itself vs current * highestproductof2 then the max of that vs lowestproductof2 * current
        highestProduct3 = max(max(highestProduct3, current * highestProduct2), current * lowestProduct2);
        
        //same idea here where it's the max of itself vs highest * current and the max of that vs current * lowest
        highestProduct2 = max(max(highestProduct2, current * highest), current * lowest);

        //again same idea except it's min
        lowestProduct2 = min(min(lowestProduct2, current * lowest), current * highest);

        //finally, to find highest and lowest we just compare max/min of itself to current
        highest = max(highest, current);
        lowest = min(lowest, current);
    }
    return highestProduct3;
}


















// tests

const lest::test tests[] = {
    {CASE("short vector") {
        const int actual = highestProductOf3({1, 2, 3, 4});
        const int expected = 24;
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const int actual = highestProductOf3({6, 1, 3, 5, 7, 8, 2});
        const int expected = 336;
        EXPECT(actual == expected);
    }},

    {CASE("vector has one negative") {
        const int actual = highestProductOf3({-5, 4, 8, 2, 3});
        const int expected = 96;
        EXPECT(actual == expected);
    }},

    {CASE("vector has two negatives") {
        const int actual = highestProductOf3({-10, 1, 3, 2, -10});
        const int expected = 300;
        EXPECT(actual == expected);
    }},

    {CASE("vector is all negatives") {
        const int actual = highestProductOf3({-5, -1, -3, -2});
        const int expected = -6;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty vector") {
        EXPECT_THROWS(highestProductOf3({}));
    }},

    {CASE("exception with one number") {
        EXPECT_THROWS(highestProductOf3({1}));
    }},

    {CASE("exception with two numbers") {
        EXPECT_THROWS(highestProductOf3({1, 1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
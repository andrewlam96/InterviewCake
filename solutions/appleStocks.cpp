#include <iostream>
#include <vector>
#include <limits>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
int getMaxProfit(const vector<int>& stockPrices)
{
    // calculate the max profit

    //if the size is 0 or 1 throw an exception
    if(stockPrices.size() == 0 || stockPrices.size() == 1) throw ("Size not large enough");

    //assuming there's at least 2 numbers now (otherwise exception is throw)
    //set min to whatever is smaller from index 0 and 1
    int min = stockPrices[0] < stockPrices[1] ? stockPrices[0] : stockPrices[1];

    //similarily set max profit to value from index 1 - value of index 0 
    //NOTE that this problem can have negative max profits
    int maxProfit = stockPrices[1] - stockPrices[0];
    for(int i = 2; i < stockPrices.size(); ++i){
        //if the difference between the current stock and min is larger than max profit update max profit
        if(stockPrices[i] - min > maxProfit) maxProfit = stockPrices[i] - min; 

        //then check to see if current value is smaller than min and update accordingly
        if(stockPrices[i] < min) min = stockPrices[i];
    }
    return maxProfit;
}


















// tests

const lest::test tests[] = {
    {CASE("price goes up then down") {
        const int actual = getMaxProfit({1, 5, 3, 2});
        const int expected = 4;
        EXPECT(actual == expected);
    }},

    {CASE("price goes down then up") {
        const int actual = getMaxProfit({7, 2, 8, 9});
        const int expected = 7;
        EXPECT(actual == expected);
    }},

    {CASE("price goes up all day") {
        const int actual = getMaxProfit({1, 6, 7, 9});
        const int expected = 8;
        EXPECT(actual == expected);
    }},

    {CASE("price goes down all day") {
        const int actual = getMaxProfit({9, 7, 4, 1});
        const int expected = -2;
        EXPECT(actual == expected);
    }},

    {CASE("price stays the same all day") {
        const int actual = getMaxProfit({1, 1, 1, 1});
        const int expected = 0;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty prices") {
        EXPECT_THROWS(getMaxProfit({}));
    }},

    {CASE("exception with one price") {
        EXPECT_THROWS(getMaxProfit({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
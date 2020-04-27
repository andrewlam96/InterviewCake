#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Solution 1: Brute Force
//Time Complexity O(n^2)
//Space Complexity O(n)
vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    // make a vector with the products
    //This is a brute force solution
    if(intVector.size() < 2) throw "not enough ints";
    vector<int> solution;
    //go through the vector
    for(int i = 0; i < intVector.size(); ++i){
        //we will find the product of every other number
        int product = 1;
        //again, go through the vector
        for(int j = 0; j < intVector.size(); ++j){
            //if the indices are the same don't multiple that number to the product
            //otherwise multiple number to product
            if(i == j) continue;
            product *= intVector[j];
        }
        solution.push_back(product); //add that number to the solution vector
    }

    return solution;
}

//Solution 2: Adding before/after index
//Time Complexity O(n)
//Space Complexity O(n)
vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    // make a vector with the products
    if(intVector.size() < 2) throw "not enough ints";
    //make solution vector with same size as input vector
    vector<int> solution(intVector.size()); 
    int product = 1;
    //idea is to get numbers before index / after index and add them
    //i.e. 1 2 3 so after index is 1 1 2 (start with 1 then multiply each index)
    //before index (start at end) (6 3 1) (same logic but we reversed it)
    //then solution is multiple each index = (6 3 2) 
    for(int i = 0; i < intVector.size(); ++i){
        //initially set the index value to the product
        solution[i] = product;
        //update the product by multiplying by the current value
        product *= intVector[i];
    }
    
    product = 1; //reset product
    //now we want to go in reverse order
    for(int i = solution.size() - 1; i >= 0; --i){
        //we still want product but it is going to be in reverse order
        //we also want to multiply that with the first index we got
        solution[i] *= product;
        //then we update the product
        product *= intVector[i];
    }
    return solution;
}

//Solution 3: division
//Time Complexity O(n)
//Space Complexity O(n)
vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    // make a vector with the products
    if(intVector.size() < 2) throw "not enough ints";
    //make vector and set all values to 0
    vector<int> solution(intVector.size(), 0);

    //we want to keep track of how many zeros there are
    //because the solution will be different if there are 1 zero or multiple zeros
    int product = 1, countZeros = 0;
    for(auto &i : intVector){
        if(i == 0) ++countZeros; //if value iss zero increment the counter
        else product *= i; //otherwise multiply product by value
    }
    //if there are multiple zeros all the answers are 0 so just return the solution we made initially
    if(countZeros > 1) return solution;
    //otherwise there is 1 or less zeros
    else{
        for(int i = 0; i < solution.size(); ++i){
            //if there are no zeros we will just get the value by dividing the product by the value at that index (make sure to not update product)
            if(!countZeros) solution[i] = product / intVector[i];
            //otherwise it will get to this case where the value is not zero (but there was a zero somewhere)
            //so the update product must be 0 by definition (anything multiply by 0 is 0)
            else if(intVector[i]) solution[i] = 0;
            //otherwise the value is 0 so we want it to just be the product off every other number
            else solution[i] = product;
        }
    }
    return solution;
}













// tests

const lest::test tests[] = {
    {CASE("small vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({1, 2, 3});
        const auto expected = vector<int> {6, 3, 2};
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
        const auto expected = vector<int> {120, 480, 240, 320, 960, 192};
        EXPECT(actual == expected);
    }},

    {CASE("vector has one zero") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
        const auto expected = vector<int> {0, 0, 36, 0};
        EXPECT(actual == expected);
    }},

    {CASE("vector has two zeros") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
        const auto expected = vector<int> {0, 0, 0, 0, 0};
        EXPECT(actual == expected);
    }},

    {CASE("one negative number") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-3, 8, 4});
        const auto expected = vector<int> {32, -12, -24};
        EXPECT(actual == expected);
    }},

    {CASE("all negative numbers") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
        const auto expected = vector<int> {-8, -56, -14, -28};
        EXPECT(actual == expected);
    }},

    {CASE("error with empty vector") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({}));
    }},

    {CASE("error with one number") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
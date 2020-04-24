#include <iostream>
#include <string>
#include <unordered_set>
// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(n)
//Space Complexity O(n)
bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    //idea is that a palindrome will have at most 1 character that is not an even amount
    //i.e assa 0 odd number characters
    //i.e. asdsa 1 odd number characters

    //use set (or map) to keep track of number of character occurances
    //map can have values to keep track
    //or set can just erase every time it occurs even number of times
    unordered_set<int> mySet; 
    //go through string
    for(auto &s : str){ 
        //if character is in set, delete it
        //this means this is an "even" number of times it has been seen
        if(mySet.find(s) != mySet.end()) mySet.erase(s);
        //otherwise we will insert into set
        else mySet.insert(s);
    }
    //compare and return if size of set is less than 2 (true) otherwise it is false
    return mySet.size() < 2;
}


















// tests

const lest::test tests[] = {
    {CASE("permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcbcd");
        EXPECT(result == true);
    }},
    {CASE("permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabccbdd");
        EXPECT(result == true);
    }},
    {CASE("no permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcd");
        EXPECT(result == false);
    }},
    {CASE("no permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabbcd");
        EXPECT(result == false);
    }},
    {CASE("empty string") {
        const auto result = hasPalindromePermutation("");
        EXPECT(result == true);
    }},
    {CASE("one character string") {
        const auto result = hasPalindromePermutation("a");
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
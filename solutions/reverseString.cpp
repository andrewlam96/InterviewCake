#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
void reverse(string& str)
{
    // reverse the input string in place
    if(str.empty()) return;
    
    //use two ints to keep track of the beginning and end indices
    int i = 0;
    int j = str.size() - 1;
    
    while(i < j){
        swap(str[i], str[j]);
        //or use own swap
        //int temp = str[i];
        //str[i] = str[j];
        //str[j] = temp;
        ++i;
        --j;
    }
}


















// tests

const lest::test tests[] = {
    {CASE("empty string") {
        const string expected;
        string actual;
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("single character string") {
        const string expected("A");
        string actual("A");
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("longer string") {
        const string expected("EDCBA");
        string actual("ABCDE");
        reverse(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
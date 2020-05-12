#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
size_t getClosingParen(const string& sentence, size_t openingParenIndex)
{
    // find the position of the matching closing parenthesis
    size_t count = 0;
    //start after the opening parenthesis index and go to end
    for(int i = openingParenIndex + 1; i < sentence.size(); ++i){
        char c = sentence[i]; //get character
        //if it is an open parenthesis add to count
        if(c == '(') ++count;
        else if(c == ')'){
            //otherwise we check if count is 0
            //if it is then that means it matches (since we did not count the opening parenthesis we looking for)
            //and return the index of it
            if(count == 0) return i;
            //otherwise decrement count
            else --count;
        }
    }
    //othwerwise there is no solution so we throw error message
    throw "No closing parenthesis";
}


















// tests

const lest::test tests[] = {
    {CASE("All openers then closers") {
        const size_t expected = 7;
        const size_t actual = getClosingParen("((((()))))", 2);
        EXPECT(actual == expected);
    }},
    {CASE("mixed openers and closers") {
        const size_t expected = 10;
        const size_t actual = getClosingParen("()()((()()))", 5);
        EXPECT(actual == expected);
    }},
    {CASE("no matching closer") {
        EXPECT_THROWS(getClosingParen("()(()", 2));
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
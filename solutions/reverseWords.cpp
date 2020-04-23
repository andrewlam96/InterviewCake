#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
//first step is we want to make a helper function to reverse all characters
//look at reverseString.cpp for comments on this
void reverseLetters(string& str, int leftIndex, int rightIndex){
    while(leftIndex < rightIndex){
        swap(str[leftIndex], str[rightIndex]);
        ++leftIndex;
        --rightIndex;
    } 
}

//Idea is to reverse every character so that everything in backwards
//Next we want to reverse all the characters of each "word" 
//i.e. Hello World -> dlroW olleH -> World Hello
void reverseWords(string& message)
{
    // decode the message by reversing the words
    
    //reverse all characters in string
    reverseLetters(message, 0, message.size() - 1);
    
    int tempIndex = 0; //temp index so we can use it for start of separate words
    //go through entire string
    for(int i = 0; i <= message.size(); ++i){
        //want to exit if it is the end or if there is a whitespace
        if(message[i] == ' ' || i == message.size()){
            //reverse the words
            //temp index is left index and right index will be i - 1 (since i is whitespace)
            reverseLetters(message, tempIndex, i - 1);
            tempIndex = i + 1; //change tempindex to start of next word (1 after i (whitespace))
        }
    }
}


















// tests

const lest::test tests[] = {
    {CASE("one word") {
        const string expected = "vault";
        string actual = "vault";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("two words") {
        const string expected = "cake thief";
        string actual = "thief cake";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("three words") {
        const string expected = "get another one";
        string actual = "one another get";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("multiple words same length") {
        const string expected = "the cat ate the rat";
        string actual = "rat the ate cat the";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("multiple words different lengths") {
        const string expected = "chocolate bundt cake is yummy";
        string actual = "yummy is cake bundt chocolate";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("empty string") {
        const string expected;
        string actual;
        reverseWords(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
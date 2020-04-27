#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

//MY CODE
//Time Complexity O(n)
//Space Complexity O(n)
vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // sort the scores in O(n) time
    //first vector uses index as numbers and count as values
    vector<int> scoreCount(highestPossibleScore + 1);
    //second vector will be used to store the sorted order
    vector<int> sortedScores;
    //we go through the unsorted numbers
    //and at that number index, add 1
    for(auto &i : unorderedScores){
        ++scoreCount[i];
    }
    
    //we then go through the first vector we made from end to beginning (100-0)
    for(int i = scoreCount.size() - 1; i >= 0; --i){
        int count = scoreCount[i]; //make a variable to store count
        if(count > 0){ //if it is greater than 0 we want that number
            //loop used to add number multiple times if need be
            for(int j = 0; j < count; ++j){ 
                sortedScores.push_back(i); //add number to our sorted vector
            }
        }
    }
    return sortedScores;
}


















// tests

const lest::test tests[] = {
    {CASE("no scores") {
        const vector<int> scores;
        const vector<int> expected;
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("one score") {
        const vector<int> scores {55};
        const vector<int> expected {55};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("two scores") {
        const vector<int> scores {30, 60};
        const vector<int> expected {60, 30};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("many scores") {
        const vector<int> scores {37, 89, 41, 65, 91, 53};
        const vector<int> expected {91, 89, 65, 53, 41, 37};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("repeated scores") {
        const vector<int> scores {20, 10, 30, 30, 10, 20};
        const vector<int> expected {30, 30, 20, 20, 10, 10};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
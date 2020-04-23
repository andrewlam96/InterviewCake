#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Solution 1: nested for loops
//Time Complexity O(n^2)
//Space Complexity O(1)
bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // determine if two movies add up to the flight length
    if(movieLengths.size() < 2) return false; //want 2 movies so if less than that, return false

    //go through all movies
    for(int i = 0; i < movieLengths.size(); ++i){
        //also start second index 1 after i
        for(int j = i + 1; j < movieLengths.size(); ++j){
            //if any combination of movie lengths equal flight length return true
            if(movieLengths[i] + movieLengths[j] == flightLength) return true;
        }
    }
    return false;
}

//Solution 2: using an unordered_set
//Time Complexity O(n)
//Space Complexity O(n)
bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // determine if two movies add up to the flight length
    if(movieLengths.size() < 2) return false; //want 2 movies so if less than that, return false
    unordered_set<int> mySet; //create set

    //go through all movies
    for(auto &m : movieLengths){
        //find the difference
        int diff = flightLength - m;
        //if the difference is in the set return true
        if(mySet.find(diff) != mySet.end()) return true;
        mySet.insert(m); //always insert movielength to set
    }
    return false;
}















// tests

const lest::test tests[] = {
    {CASE("short flight") {
        const vector<int> movieLengths {2, 4};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 1) == false);
    }},
    {CASE("long flight") {
        const vector<int> movieLengths {2, 4};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == true);
    }},
    {CASE("only one movie half flight length") {
        const vector<int> movieLengths {3, 8};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }},
    {CASE("two movies half flight length") {
        const vector<int> movieLengths {3, 8, 3};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == true);
    }},
    {CASE("lots of possible pairs") {
        const vector<int> movieLengths {1, 2, 3, 4, 5, 6};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 7) == true);
    }},
    {CASE("not using first movie") {
        const vector<int> movieLengths {4, 3, 2};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 5) == true);
    }},
    {CASE("only one movie") {
        const vector<int> movieLengths {6};
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }},
    {CASE("no movies") {
        const vector<int> movieLengths;
        EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
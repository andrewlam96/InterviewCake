#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
//MY CODE
//Time Complexity O(n)
//Space Complexity O(n)
vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    // combine the sorted vectors into one large sorted vector
    vector<int> solution; //use another vector to store solution
    int i = 0, j = 0; //use two variables as indices for the vectors
    //want to keep looping until 1 vector reaches the end
    while(i < myVector.size() && j < alicesVector.size()){
        //if the value from 1st vector is smaller
        if(myVector[i] <= alicesVector[j]){
            solution.push_back(myVector[i]); //put that value in our solution vector
            ++i; //increment 1st vector index
        }
        else{
            solution.push_back(alicesVector[j]); //otherwise put value of 2nd vector into solution
            ++j; //and increment index of 2nd vector
        }
    }

    //at this point one of the vectors has reached the end
    //we will run while loops for both cases 
    //since we don't know which vector has reached end, we write loops for both cases
    while(j < alicesVector.size()){
        solution.push_back(alicesVector[j]);
        ++j;
    }

    while(i < myVector.size()){
        solution.push_back(myVector[i]);
        ++i;
    }


    return solution;
}


















// tests

const lest::test tests[] = {
    {CASE("both vectors are empty") {
        const vector<int> myVector;
        const vector<int> alicesVector;
        const vector<int> expected;
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("first vector is empty") {
        const vector<int> myVector;
        const vector<int> alicesVector {1, 2, 3};
        const vector<int> expected {1, 2, 3};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("second vector is empty") {
        const vector<int> myVector {5, 6, 7};
        const vector<int> alicesVector;
        const vector<int> expected {5, 6, 7};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("both vectors have some numbers") {
        const vector<int> myVector {2, 4, 6};
        const vector<int> alicesVector {1, 3, 7};
        const vector<int> expected {1, 2, 3, 4, 6, 7};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("vectors are different lengths") {
        const vector<int> myVector {2, 4, 6, 8};
        const vector<int> alicesVector {1, 7};
        const vector<int> expected {1, 2, 4, 6, 7, 8};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
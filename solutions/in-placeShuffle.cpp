#include <iostream>
#include <random>
#include <vector>

using namespace std;

size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}

//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
void shuffle(vector<int>& theVector)
{
    // shuffle the input in place
    if(theVector.size() < 2) return; //if not at least 2 return

    //go through input vector
    for(int i = 0; i < theVector.size(); ++i){
        //get some random index from function given
        //we don't want to move our value too many times so we set the floor to i instead of 0
        int random = getRandom(i, theVector.size() - 1);

        //if the index of the current and random are not the same then we will swap them
        if(random != i){
            swap(theVector[i], theVector[random]);
        }
    }

}

void printVector(const char* title, const vector<int>& theVector)
{
    cout << title << ": [";
    bool isFirst = true;
    for (int value: theVector) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ", ";
        }
        cout << value;
    }
    cout << ']' << endl;
}

int main(int argc, char** argv)
{
    const vector<int> initial {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> shuffled(initial);
    shuffle(shuffled);
    printVector("initial vector", initial);
    printVector("shuffled vector", shuffled);
    return 0;
}
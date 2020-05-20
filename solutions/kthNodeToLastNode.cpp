#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

//MY CODE
//Time Complexity O(n)
//Space Complexity O(1)
LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
    // return the kth to last node in the linked list
    if(k == 0) throw "cannot return if k is 0";
    
    //want to go through linked list and use a counter 
    //to see how many nodes are in it
    LinkedListNode* curr = head;
    int total = 0;
    while(curr){
        curr = curr->next_;
        ++total;
    }
    
    //if k is greater then we throw an error
    if(k > total) throw "k is greater than the length of the linked list!";
    
    //we reset our pointer to the head
    curr = head;

    //our position we want to stop at is the total - k
    int stop = total - k;

    //we thrn traverse until we reach that point
    //NOTE i went from stop to 0 but it can also be done from 0 to stop as well
    while(stop > 0){
        curr = curr->next_;
        --stop;
    }

    //return the position of the node we want
    return curr;
}


















// tests

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values);
void freeLinkedListNodes(vector<LinkedListNode*>& nodes);

const lest::test tests[] = {
    {CASE("first to last node") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 1;
        auto actual = kthToLastNode(k, listNodes[0]);
        auto result = (actual == listNodes[listNodes.size() - k]);
        EXPECT(result == true);
        freeLinkedListNodes(listNodes);
    }},
    {CASE("second to last node") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 2;
        auto actual = kthToLastNode(k, listNodes[0]);
        auto result = (actual == listNodes[listNodes.size() - k]);
        EXPECT(result == true);
        freeLinkedListNodes(listNodes);
    }},
    {CASE("first node") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 4;
        auto actual = kthToLastNode(k, listNodes[0]);
        auto result = (actual == listNodes[listNodes.size() - k]);
        EXPECT(result == true);
        freeLinkedListNodes(listNodes);
    }},
    {CASE("k is greater than linked list length") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 5;
        EXPECT_THROWS(kthToLastNode(k, listNodes[0]));
        freeLinkedListNodes(listNodes);
    }},
    {CASE("k is zero") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 0;
        EXPECT_THROWS(kthToLastNode(k, listNodes[0]));
        freeLinkedListNodes(listNodes);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values)
{
    vector<LinkedListNode*> nodes;
    for (int value: values) {
        auto node = new LinkedListNode(value);
        if (!nodes.empty()) {
            nodes.back()->next_ = node;
        }
        nodes.push_back(node);
    }
    return nodes;
}

void freeLinkedListNodes(vector<LinkedListNode*>& nodes)
{
    for (auto node: nodes) {
        delete node;
    }
    nodes.clear();
}
#include <iostream>
#include <sstream>
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
//Time Complexity O(1)
//Space Complexity O(1)
//want to delete node but we are only given the node we are going to delete
void deleteNode(LinkedListNode* nodeToDelete)
{
    // delete the input node from the linked list
    //get the node after the node we want to delete
    LinkedListNode* nextNode = nodeToDelete->next_; 
    if(nextNode){ //check to make sure it is not the end (errors can occur if it is)
        //copy the value and next pointer of the next node
        nodeToDelete->intValue_ = nextNode->intValue_; 
        nodeToDelete->next_ = nextNode->next_;
        delete nextNode; //delete next node instead
    }
    else throw invalid_argument("Cannot delete Node");
}
//i.e. 1 -> 2 -> 3 -> 4 delete 2
//1 -> 3 -> 3 -> 4 delete the original 3
//1 -> 3 -> 4

















// tests

LinkedListNode* appendToList(LinkedListNode* head, int value);
void freeList(LinkedListNode* head);

const lest::test tests[] = {
    {CASE("node at beginning") {
        LinkedListNode* head = new LinkedListNode(1);
        appendToList(head, 2);
        appendToList(head, 3);
        appendToList(head, 4);

        deleteNode(head);

        LinkedListNode* node = head;
        EXPECT(node->intValue_ == 2);

        node = node->next_;
        EXPECT(node->intValue_ == 3);

        node = node->next_;
        EXPECT(node->intValue_ == 4);

        EXPECT(node->next_ == nullptr);

        freeList(head);
    }},
    {CASE("node in middle") {
        LinkedListNode* head = new LinkedListNode(1);
        LinkedListNode* nodeToDelete = appendToList(head, 2);
        appendToList(head, 3);
        appendToList(head, 4);

        deleteNode(nodeToDelete);

        LinkedListNode* node = head;
        EXPECT(node->intValue_ == 1);

        node = node->next_;
        EXPECT(node->intValue_ == 3);

        node = node->next_;
        EXPECT(node->intValue_ == 4);

        EXPECT(node->next_ == nullptr);

        freeList(head);
    }},
    {CASE("node at the end") {
        LinkedListNode* head = new LinkedListNode(1);
        appendToList(head, 2);
        appendToList(head, 3);
        LinkedListNode* nodeToDelete = appendToList(head, 4);

        EXPECT_THROWS(deleteNode(nodeToDelete));

        freeList(head);
    }},
    {CASE("one node in list") {
        auto head = new LinkedListNode(1);
        EXPECT_THROWS(deleteNode(head));
        delete head;
    }}
};

LinkedListNode* appendToList(LinkedListNode* head, int value)
{
    auto current = head;
    while (current->next_) {
        current = current->next_;
    }
    current->next_ = new LinkedListNode(value);
    return current->next_;
}

void freeList(LinkedListNode* head)
{
    auto current = head;
    while (current) {
        auto next = current->next_;
        delete current;
        current = next;
    }
}

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
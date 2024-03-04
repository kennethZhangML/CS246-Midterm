#include <iostream>
#include <iomanip>
#include <limits>

struct Node {
    int data;
    Node *next;
    inline static  int numNodesIterated = 0;
    // cache recent data
    // declare static => not associated with any particular instance/object class 
    static int mostRecent;
    static int mostRecentIndex;

    int ith(int i) {
        // check for prev most recent cache assignment 
        if (i == mostRecent) return mostRecent;
        if (i == 0) return data;
        Node* cur = next;
        for (int j = 0; j < i; ++j) {
            cur = cur->next;
        }

        mostRecent = cur->data;
        return cur->data;
    }
};

struct Student {
    static in numMethodsCalled = 0;
    // int -> does not allocate space;
    static int getNMC() { return numMethodsCalled; }
};

int main() {
    int Node::mostRecent = INT_MIN;
    int Node::mostRecentIndex = -1;
    const Node n{30, nullptr};
    n.ith(0);

    std::cout << Student::getNMC();
    Student s;
    std::cout << s.getNMC();
    
    return 0;
}
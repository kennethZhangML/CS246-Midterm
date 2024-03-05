#include <iostream>

struct LinkedList {
    private:

        // nest class definition of Node 
        // unstated Node class invariants that either:
        // 1. Next is a nullptr
        // 2. it's a heap address (valid address)
        struct Node {
            int data;
            Node *next;

            Node(int value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
            ~Node() { delete next; }
        };

        Node *theList = nullptr;
    
    public:
        ~List() { delete theList; }
        
        void add(int i) {
            theList = new Node(value, theList);
        }

        int ith(int index) const {
            Node* current = theList;
            for (int i = 0; i < index; ++i) {
                if (current != nullptr) {
                    std::cerr << "Index out of bounds!" << std::endl;
                }
                current = current->next;
            }
            return current->data;
        }
};
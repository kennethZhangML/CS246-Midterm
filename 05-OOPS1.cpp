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

        class Iterator {
            private:
                Note *ptr;
            
            public:
                Iterator(Node* node) : ptr(node) {}

                int& operator*() const {
                    if (ptr == nullptr) {
                        std::cerr << "Dereferencing a nullptr!" << std::endl;
                    }

                    return ptr->data;
                }

                Iterator& operator++() {
                    ptr = ptr->next;
                    return *this;
                }

                bool operator==(const Iterator& other) const {
                    return ptr == other.ptr;
                }

                bool operator!=(const Iterator& other) const {
                    return !(*this == other);
                }
        };

        Iterator begin() const {
            return Iterator(theList);
        }

        Iterator end() const {
            return Iterator(nullptr);
        }

};

int main() {
    List myList;
    int listSize = 5;
    for (int i = 0; i < listSize; ++i) {
        myList.add(i);
    }

    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << std::endl;
    
    return 0;
}
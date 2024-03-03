#include <iostream>
#include <iomanip>

/*
Copy Constructor
- Create copies of objects
- Compiler generates implicit copy constructor 
- try to call copy constructors on its fields => ONLY does shallow copies 

Copy Assignment Operator
- Cop
*/


struct Node {
    int data;
    Node* next;

    // Default Constructor 
    Node(int data = 0, Node *next = nullptr) : data(data), next(next) {}

    // Copy Constructor 
    // Syntax: className(const className& oother)

    // Recursively calls cconstructor to construct node 
    Node(const Node& other) : data(other.data), next(nullptr) {

        // alternatively
        /*
        data = other.data;
        or 
        this->data = other.data;

        next = nullptr;
        this->next = nullptr;
        */
        if (other.next != nullptr) {
            // Deep copy 
            next = new Node(*other.next);
        }
    }

    ~Node() {
        delete next; // recursive deletion of all next nodes;
    }

    /*
    3 Things for Copy Assignment Operator
    1. Self Assignment
    2. Non-Nullptr Assignment 
    3. Nullptr Assignment 
    */
    Node& operator=(const Node& other) {
        if (this == &other) return *this;

        data = other.data;
        // free before overwrite => prevent memory leak 
        delete next;

        if (other.next != nullptr) {
            next = new Node(*other.next); // deep copy
        } else { 
            next = nullptr;
        }
        
        return *this;
    }
};


int main() {
    Node* n = new Node(1, new Node(2, new Node(3)));
    // Copy constructor 
    Node m = *n;

    // Copy assignment 
    Node p;
    p = *n;

    std::cout << "Copied List m: ";
    Node *temp = &m;
    while (temp != nullptr) {
        std::cout << temp->data << " "; 
        temp = temp->next;
    }

    std::cout << std::endl;

    std::cout << "Copied List p: ";
    temp = &p;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;

    delete n;
    return 0;
}

#include <iostream>
#include <iomanip>

class DynamicArray {
    private:
        int *data;
        size_t capacity;
        size_t size;

    public:
        DynamicArray(size_t initialCapacity = 10) : capacity(initialCapacity), size(0) {
            data = new int[capacity];
        }

        ~DynamicArray() {
            delete[] data;
        }

        // Copy Constructor 
        /*
        - Copy constructor consumes binded const. reference "other"
        - className(const className& other);
        - compiler copy constructor -> does shallow copy => pointers are not objects => shallow copies

        3 things to check for Copy Ctor:
        - declare object => initialize it with object same type
        - Pass by Value
        - Pass by Reference 
        */
        DynamicArray(const DynamicArray& other): capacity(other.capacity), size(other.size) {
            data = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i]; // deep copy 
            }
        } 
        
        // Copy Assignment Operator 
        /*
        - Compiler generates implicit copy assignment operator
        - called on all object data fields
        */
        DynamicArray& operator=(const DynamicArray& other) {
            // Check for self-assignment
            if (this != &other) {
                // prevent overwriting data from this dynamic array
                delete[] data;
                // write to assignment lvalue
                capacity = other.capacity;
                size = other.size;
                data = new int[capacity];
                for (size_t i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            }
            
            // otherwise; return same
            return *this;
        }

        // Move Constructor
        DynamicArray(DynamicArray& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
            other.data = nullptr; // double deletion prevention
            other.capacity = 0;
            other.size = 0;
        }

        // Move Assignment Operator 
        /*
        - self assignment check 
        - compiler optimizes away move or copy ctors calls 
        - returns rvalue with (assignment operator takes rvalue as well)
        */
        DynamicArray& operator=(const DynamicArray& other) {
            if (this != &other) { // self assignment check 
                DynamicArray temp(other); // copy constructor 
                swap(std::move(temp)); // swap with temp
            }
        }
        
        // Alternative Move Assignment Operator 
        DynamicArray& operator=(DynamicArray&& other) {
            if (this != &other) {
                delete[] data; // prevent overwriting 

                // explicit usage of this operator 
                this->data = other.data;
                this->capacity = other.capacity;
                this->size = other.size;

                other.data = nullptr;
                other.capacity = 0;
                other.size = 0;
            }

            return *this;
        }

        // Helper function: push back value 
        void push_back(int value) {
            if (size == capacity) {
                size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
                int *newData = new int[newCapacity];

                for (size_t i = 0; i < size; ++i) {
                    newData[i] = data[i];
                }

                delete[] data;
                data = newData;
                capacity = newCapacity;

            }

            data[size++] = value;
        }

        int& operator[](size_t index) {
            return data[index];
        }

        size_t getSize() const {
            return size;
        }

    private:
        // Copy/Idiom to swap contents with other 
        void swap(DynamicArray&& other) noexcept {
            std::swap(data, other.data);
            std::swap(capacity, other.capacity);
            std::swap(size, other.size);
        }
};

int main() {
    DynamicArray arr1;
    for (int i = 0; i < 5; ++i) {
        arr1.push_back(i);
    }

    // 1. Creating copy
    DynamicArray arr2 = arr1; // Copy Constructor called 

    std::cout << "Array Size (arr2): " << arr2.getSize() << std::endl;
    std::cout << "Array Elements (arr2): ";
    for (size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << arr2[i] << " ";
    }

    std::cout << std::endl;

    // 2. Move Semantics
    DynamicArray arr3 = DynamicArray(10); // Move constructor called 
    // arr3 now owns resources of the temp object

    std::cout << "Array Size (arr3): " << arr3.getSize() << std::endl;
    std::cout << "Array Elements (arr3): ";
    for (size_t i = 0; i < arr3.getSize(); ++i) {
        std::cout << arr3[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
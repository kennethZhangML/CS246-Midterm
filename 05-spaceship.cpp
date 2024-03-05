#include <iostream>
#include <compare>

struct Vec {
    int x, y;

    auto operator<=>(const Vec& rhs) const {
        auto n = x <=> rhs.x;
        if (n != 0) return n;

        n = y <=> rhs.y;
        return n;
    }
};

// when <=> not sufficient 
// Consider Node example
// no point comparing next pointer (comparing heap addresses) 
//      - no point comparing heap addresses for ordering 
struct Node {
    int data;
    Node *next;

    auto operator<=>(const Node& other) { // lvalue consumption
        auto n = data <=> other.data;
        if (n != 0) return n;

        if (next == nullptr && other.next == nullptr) {
            return n;
        }
        
        // must be comparing 2 non-empty lists since:
        //      - comparing node objects 
        //      - no equivalent to null objects 
        if (next == nullptr) return std::strong_ordering::less;
        if (other.next == nullptr) return std::strong_order::greater;
        
        // <=> recursively calls on 2 nodes 
        return next <=> other.next;
    }
};


int main() {
    Vec v1{1, 2};
    Vec v2{1, 3};
    Vec v3{2, 2};

    auto res1 = v1 <=> v2;
    auto res2 = v2 <=> v3;

    std::cout << "v1 <=> v2: " << res1 << std::endl;
    std::cout << "v2 <=> v2: " << res2 << std::endl;

    return 0;
}
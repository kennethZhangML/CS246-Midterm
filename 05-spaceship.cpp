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
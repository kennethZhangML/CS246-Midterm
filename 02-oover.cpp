#include <iostream>
#include <iomanip>
#include <sstream>

struct Vector {
    int x;
    int y;
};

Vector operator*(const Vector &v1, const Vector &v2) {
    Vector v{v1.x + v2.x, v1.y + v2.y};
    return v; 
}

Vector operator*(const int &s, const Vector &v) {
    return Vector{v.x * s, v.y * s};
}

Vector operator*(const vector &v, const int &s) {
    return (s * v); // calls previous definition
}

struct Grade {
    int value;
};

std::istream& operator>>(std::istream& in, Grade &g) {
    in >> g.value;
    
    if (g.value < 0) {
        g.value = 0;
    } else if (g.value > 100) {
        g.value = 100;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Grade& g) {
    out << g.value << '%';
    return out;
}

// Overloading, multiple functions with same name
//  - as long as # of parameters and/or types of parameters are different
//  - functions cannot be overloaded bassed on return type alone 

// Modules
// file: vec.cc
export module vec;
export struct Vec {
    int x, y;
};

export Vec operator*(const int& s, const Vec& v) {
    return Vec{v1.x * s, v2.y * s};
}





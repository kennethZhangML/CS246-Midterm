#include <iostream>
#include <iomanip>
#include <sstream>

/* 
Class terminology:

1. class => type definition, part of class or standalone
            => has data fields + methods (called Members)
2. Instance of a class => object
3. struct is a class

Note: '::' is a scope resolution operator => LHS is a namespace or class name 
*/

// -----------------------------------------------------------------------------

// student.cc
export module Student;
export struct Student {
    int assns, mt, final;
    float grade();

    Student (int assns = 0, int mt = 0, int final = 0);
};


// student-impl.cc
module student;
float Student::grade() {
    return this->assns * 0.4 + this->mt * 0.2 + this->final * 0.4;
}

// Constructor 
Student::Student(int assns, int mt, int final) {
    this->assns = assns;
    this->mt = mt;
    this->final = final;
}

// MIL-Constructor Definition
Student::Student(int assns, int mt, int final)
    : assns{assns}, mt{mt}, final{final} {}

// Note: Default Constructor is given by compiler (has 0 arguments)
// class can only have one default constructor 

// -----------------------------------------------------------------------------

class Complex {
    private:
        int real, imag;;

    public:
        Complex(double real = 0, double imag = 0);

        ~Complex();
        double getReal() const; 
        double getImag() const;
        void setReal() const;
        void setImag() const;
        ~Complex();

        void init(double real, double imag);

        Complex operator+(const Complex& other) const;
};

Complex::Complex(double real, double imag) :
    real{real}, imag{imag} {}

Complex::

double Complex::getImag() const {
    return imag;
}

double Complex::getReal() const {
    return real;
}

void Complex::setReal() {
    this->real = real;
}

void Complex::setImag() {
    this->imag = imag;
}

void Complex::init(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}




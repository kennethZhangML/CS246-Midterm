#include <iostream>

void inc(int n) {
	++n;
}

void fixed_inc(int *n) {
	++(*n);
}

int main() {
	// References
	/*
	Lvalue: appear on LHS of assignment 
		- accessed by name, derefencing pointer to it, or thru reference
		- not always temporary  

	Rvalue: appear on RHS of assignment 
		- bound to lvalue? 
		- compiler creates temporary memory location, copies rvalue into it;
			- then lvalue is bound to that location
	*/

	// Increment function 
	int i = 5;
	int *ptr = &i;
	inc(i); // only changed copy, then discarded it;
			// fixed via passing by address (pass by pointer)
	int v = 5; // fixed;
	int(&i);

	// Successfully reading in cin >> i
	std::istream operator>>(std::istream &in, int *i); 
	// works because C++ passed them both by reference 

	// & is part of type var/param, it's reference
	// otherwise, takes address of something


	/* Illegal Reference Operation
	1. int &g; -> Uninitialized
	2. int & *g; reference to reference (pointer to reference)
	3. int * & g = ...; // ok!
	4/ *arr[0] -> array of references 
	*/

	// Dynamic memory alloc
	int *p1, *p2, *p3;
	p1 = new int; *p1 = 3;
	delete p1;

	p1 = new int[5];
	p2 = new int[5]{0};
	delete []p2; // need to delete array 

	p2 = nullptr;
	delete p2; // deleting nullptr is ok!

	for (int i = 0; i < 5; ++i) {
		p3[i] = new int[10][1];
	}

	for (int i = 0; i < 5; ++i) {
		delete[] p3[i];
	}

	delete []p3;

	return 0;
}
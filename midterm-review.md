#### CS 246 midterm review
#### Agenda
- Go through the most important topics
- Q&A
---

#### Standard input/output/error
`cin, cout, cerr`

---
#### Useful functions for `cin`
- `cin.ignore()`
- `cin.eof()`
- `cin.clear()`
- `cin.fail()`

What do they do?
Check documentation! https://en.cppreference.com/w/cpp/header/iostream
*NEW*: these functions are also available for other input streams, e.g., `istringstream`

---
#### Example
```C++
#include <iostream>

int main() {
	for ( unsigned int i = 0; i < 10; i++ ) {
		if ( i % 2 == 0 )
			std::cout << i << ' ';
		else
			std::cerr << i << ' ';
	}
	std::cout << std::endl;
	std::cerr << std::endl;
}
```

`./prog 2>&1`

---
#### Other input/output streams
`istringstream, ostringstream, stringstream`
- `stringstream` is inherited from both `istream` and `ostream`. Therefore it has both input and output capabilities.
- We can use both `>>` and `<<` with `stringstream`
Exercise: write a program that uses stringstream to convert between integers and strings

---
#### Overloading
We can have multiple functions with the same name
- as long as the number of parameters and/or the types of parameters are different.
- **Functions cannot be overloaded based on return type *alone*.**

---
#### Example
- `int foo(char c, int n);`
- `int foo(int n);` 
- `int foo(char& c, int n)` 
- `int foo(const char& c, int n);`

---
#### Default Parameters
- Parameters of a function can be given default values.

Suppose we have a function declaration` void foo(int n = 75);`
- We can call the function with both `foo(15)` and `foo()`. 
- The latter indicates to the compiler to call `foo(75)`

Default parameters *must* come last when defining a function with default parameters

---
#### Question
Which of the following is not a valid overload of `bool foo(int x, char c)`?
1. `int foo();`

2. `char foo(char x, int c);

3. `bool foo(int c);`

4. `int foo(int x, char c, int y = 10);`

5. `None of the above.`

---
#### IO manip
- `#include <iomanip>`
- `setbase()`, `setfill()`, `setw()`

---
#### References
Syntax:
```C++
int x = 42;
int &rx = x;
```

- A reference is basically an automatically-dereferenced constant pointer to data

**What does this mean?**

---
#### References

- Constant pointer to data: the data that a reference is referring to cannot be changed after initialization.
- Dereferenced: When working with pointers, the pointer must be dereferenced in order to access the data.

---
#### References

- References don’t need to be dereferenced and cannot be dereferenced (unless they’re a reference to a pointer).

---
#### References: Example
```C++
int x = 10, y = 5;
int &rx = x;
int &ry = y;
int *px = &x;
int *py = &y;
int res1 = (*px + *py) * (*px - *py);
int res2 = (rx + ry) * (rx - ry);
```

---
#### References
- A reference is an “alias” to data; the reference and the data share the address of what they are referring to in memory.

```C++
int x = 17;
int &rx = x;

// these two lines print the same address
cout << &x << endl;
cout << &rx << endl;
```

---
#### References
- **Note**: references cannot “point” to nothing—**they must always be initialized, and you can’t directly initialize them to nullptr.**

---
#### Pass-by-reference
- **Pass-by-value**: makes a copy of the parameter passed for use during the function. Changes to the parameter do not persist outside of the scope of the function.
- **Pass-by-reference**: creates an alias to the parameter.
---
#### Examples
```C++
void inc(int n) {++n;}
int x = 5;
inc(x);
cout << x; // 5
void inc(int &n) {++n;}
int x = 5;
inc(x);
cout << x; // 6
```

---
#### Pass-by-reference
- Creates alias to the parameter
- Since there's no copying, it is usually faster than copying the parameter
---
#### Pass-by-reference
- A literal cannot be passed by reference since it is not an *lvalue* (something that has an address).
- However, we can bind const lvalue references to literals
---
### Pass-by-const-reference
- Creates a const alias of the parameter
	- We can't change the parameter in the function
	- We can pass in literal values
---
#### Example
```C++
int foo(int &x, const int &y) { ... }

int main() {
	int a = 42;
	foo(a, a);
	foo(a, 43);
	foo(43, a); // invalid, what does it mean to change a literal?
	foo(43, 43); // as above
}
```

---
#### Dynamic Memory Management
- In C++, we use `new` instead of `malloc`, and `delete` instead of `free`. 
- `new` allocates enough space on the heap for the requested data and returns a pointer to the allocated memory. 
- `delete` frees the memory pointed at by the address the variable holds.
---
#### Dynamic Memory Management
- Make sure to use `new` and `delete` together. Do not mix `new` with `malloc`.
---
#### Structure and Classes
- A structure is a collection of data and methods.
---
#### Example
```C++
 struct Complex {
  private:
	double real;
	double imag;

  public:
	Complex(double real, double imag): real{real}, imag{imag} {}
//                           |<------- MIL ------->|
    double getReal() const;
    double getImaginary() const;
};
```

---
#### Struct/Classes
- Fields and methods are called **members**.
- To access the fields of an object: objectName.fieldName
- Methods are called using `objectName.method()`
---
#### Struct/Classes
- There is a pointer , `this` that points to the object upon which the method was invoked.
- Methods have access to the members of the object, and members can be accessed directly by the member name. 
- We can also access them through `this` but that is usually redundant.
---
#### When is it not redundant to use `this`?
- If need to disambiguate a data field from a parameter that both have the same name. 
- For example,
```C++
void Complex::init(double real, double imag) {
    this->real = real;
    this->imag = imag;
}
```
---
#### Struct/classes
- To access members through a pointer, the pointer must be dereferenced
- `objectName->memberName`
- *Note*: the above is equivalent to `(*objectName).memberName` but the arrow notation is much cleaner and more readable (especially for code like `a->b->c`).
---
#### Constructors
- When working with C, when you wanted to program using a structure, you would typically write a separate function to allocate memory for the object and initialize the fields to be logical default values.
- In C++, we will instead write constructors. A *constructor* is a special method that allocates the memory for an instance of a class and initializes the fields of the object.
---
#### Constructors
```C++
 struct Complex {
  private:
	double real;
	double imag;

  public:
	Complex(double real, double imag): real{real}, imag{imag} {}
//                           |<------- MIL ------->|
    double getReal() const;
    double getImaginary() const;
};
```
---
#### Constructors
- A constructor will always be defined as `ClassName(parameters) {...}`
- Constructors can be overloaded.
---
#### Constructors
```C++
Complex(double real = 0, double imag = 0): real{real}, imag{imag} {}
```
---
#### Constructors
- A constructor that can be called with no arguments is the **default constructor** for the class.
- A class can only have one default constructor. 
- A constructor with all parameters defaulted is still a default constructor.
---
#### Constructors
-  A constructor’s return type is **implicit** (the constructor always returns the object constructed)
- If we do not write a constructor, the compiler produces a default constructor and allows C-style struct initialization.
---
#### Constructors
- The default constructor calls the default constructor for any non-primitive fields and leaves primitive fields uninitialized.
- If we define our own constructor(s), we **lose** both the implicitly-declared (i.e. compiler- provided) default constructor and list initialization (for aggregates).
---
#### Constructors
- There are other cases where the implicitly-declared default constructor is lost; can you think of any?
- Hint: when the default value doesn't make sense

---
#### Constructors: MIL
- Member-initialization-lists can be used to initialize members of a class/struct
- Some types of members can *only* be initialized by MIL
	- `const` members
	- `reference` members
	- object members where the object class doesn't have a default constructor
---
#### Constructors
- Uniform initialization syntax can be used to initialize most objects. For example, `Complex complex{1,2}` initialize a complex 
---
#### Destructors
- In C, you wrote a function that you always had to call when you were finished using an item. This is cumbersome and easy to forget to call. C++ has a better way!
- The **destructor** is a method that is called when a object is destroyed. This is either when it is heap-allocated and delete is called on it, or when it *goes out of scope*.
---
#### Destructors
- A **default destructor** is provided for us by the compiler. This destructor calls the destructors for all data fields that are objects. Note that it will not call delete on data fields that are pointers, because pointers are not objects.
- The format of the destructor will always be `~ClassName()`.
- **Destructors do not have a return type.**
---
#### Lvalues and Rvalues
- An **lvalue** is any entity which has an address accessible from code. They get their name because an lvalue is originally defined to be a value that can occur on the left-hand side of an assignment expression.
	- An lvalue reference is denoted by &.
- An rvalue is any entity that is not an lvalue. They get their name because an rvalue can only occur on the right-hand side of an assignment expression.
	- An rvalue reference is denoted by &&.

---
#### Big Five
- Copy constructor
- Copy assignment operator
- Move constructor
- Move assignment operator
- Destructor
---
#### Copy constructor
- Used to create copies of objects 
- The compiler always generates an implicit copy constructor for us.
	- This copy constructor would try to call copy constructors on its fields
	- However, because pointers are not objects, the compiler would only make shallow copies.
---
#### Copy constructor
- Syntax: `ClassName(const ClassName & other)`
---
#### Copy constructor
```C++
struct Node{
	int value; 
	Node* next = nullptr;
	Node* prev = nullptr;
};
```
What would the copy constructor of this class look like?

---
### Copy constructor
```C++
Node::Node( const Node & n ) : value{n.value}, next{n.next ? new Node{*(n.next)} : nullptr} { 
	if ( next != nullptr ) { next->prev = this; }
}
```
- In this example, the copy constructor is called recursively to construct the node.
- This copy constructor creates a deep copy of `Node`
---
#### Copy assignment operator
- Supports assigning an exiting object to another existing object.
- For example, suppose we have nodes `n` and `m`, we can have `n = m`. 
- This is not a copy constructor, because `n` is already constructed.
---
#### Copy assignment operator
- The compiler also generates an implicit copy assignment operator, but just as in the case of copy constructors, there are cases where this is not enough, 
- e.g., when dealing with pointers
#### Copy assignment operator
```C++
Node & Node::operator=(const Node & other) {
	if ( this == &other ) return *this; //check for self-assignment 
	Node * copy = next ? new Node{*other.next} : nullptr;
	delete next; next = copy; copy = nullptr; value = other.value; 
	if ( next != nullptr ) next->prev = this; 
	return *this;
}
```
---
#### Copy/swap idiom
- Assuming destructor is correctly implemented, this idiom leverages the destructor to do our work for us!
---
#### Copy/swap idiom
```C++
struct Node { 
	...
	void swap(Node & other) { 
	std::swap(value, other.value); std::swap(next, other.next); // don't touch prev!

	} 
};

Node & Node::operator=(const Node & other){ 
	Node copy{other}; swap(copy); 
	if ( next != nullptr ) next->prev = this; 
	return *this; 
}
```

---
#### Move constructor
- Move constructor allows us to construct an object from an rvalue
- Examples of rvalue: value returned from a function/operators, literals
- By having a move constructor, we avoid copying of the object into the function parameter, when the object is *expiring* (i.e., if not assigned to another variable, will go out of scope)
---
#### Move constructor
```C++
Node::Node( Node && o ): value{o.value}, next{o.next} { 
	if ( next != nullptr ) next->prev = this; 
	o.next = nullptr; 
}
```
---
#### Move constructor
- If a copy constructor (i.e. constructor with argument of const lvalue reference) and a move constructor are both present in a class deﬁnition, the compiler will decide which constructor to call based on the value category.
- If a move constructor is not available, the copy constructor will always be called regardless of what kind of value you pass into the constructor call.
---
#### Move constructor
- When deﬁning a move constructor, we must set all pointers that will be deleted by the destructor to `nullptr`, or the destructor will delete the data we transferred when the object goes out of scope.

---
#### Move Assignment Operator
- Similar to copy assignment operator, we want to have to following
```C++
Node n1{3}, n2{1};
n2 = plus(n1, 2);
```
- The return value of `plus` is an rvalue, and we want an assignment operator to take an rvalue as well.

---
#### Move Assignment Operator
```C++
Node & Node::operator=( Node && rhs ) { swap(rhs); //use our previous swap function

// ensure next nodes in both lists point to new "previous" nodes 
	if ( rhs.next != nullptr ) rhs.next->prev = &rhs; 
	if ( next != nullptr ) next->prev = this; 
	return *this;
}
```
---
#### Rules of Big Five
- If we have to write any of the following
	- Copy constructor
	- Move constructor
	- Copy assignment operator
	- Move assignment operator
	- Destructor
- Then most of the time you should write all five
- When shallow copies are "good enough", you can omit some of the big five.
---
#### Constant objects
- Like with any other data type, we might want to have struct instances which are const, i.e. their ﬁelds are all `const`.
- But a `const` object becomes a bit useless; see what happens when we try running methods:
```C++
struct Node { 
	int data; 
	Node* next; 
	int ith(int i) {
		Node* cur = this;
		for (int j = 0; j < i; ++j)
			cur = cur->next;
		return cur->data;
	} 
}; 
const Node n{30,nullptr};
n.ith(0); // Compile error!
```

- Why this gives us a compile error? How can we fix this?
---
#### Const modifier
- Given a `const` object, we can only call `const` methods on it.
- Our `ith` method doesn’t actually modify the Node
- By adding `const` to the end of its signature, it allows the compiler to verify that our method indeed does not modify fields of the object.
---
#### Const modifier
```C++
struct Node { 
	int data; 
	Node* next; 
	int ith(int i) const {
		if (i == 0) return data;
		Node *cur = next;
		for (int j = 0; j < i; ++j)
			cur = cur->next;
		return cur->data;
	} 
}; 
const Node n{30,nullptr};
n.ith(0); // now compiles!
```
---
#### Const modifier
- Suppose we want to save a piece of information when we access the nodes
- For example, we want to cache "the most recently accessed data".
---
#### Const modifier
```C++
struct Node { 
	int data; 
	Node* next;
	int mostRecent = data;
	int mostRecentIndex = 0;
	
	int ith(int i) const {
		if (i == mostRecent) return mostRecent;
		if (i == 0) return data;
		Node *cur = next;
		for (int j = 1; j < i; ++j)
			cur = cur->next;
		mostRecent = cur->data;
		return cur->data;
	} 
}; 
const Node n{30,nullptr};
n.ith(0); // doesn't compile anymore!
```
---
#### Const modifier
- We can't declare `ith` as const anymore because `ith` modifies its fields.
- However, we can bypass this restriction by declaring `mostRecent` and `mostRecentIdx` mutable.
- In this way, we can still declare the method `ith` as const, even though it modifies its fields.
- However, this weakens `const` guarantees.
---
#### Static modifier
- What if we want to cache the most recently accessed nodes across all objects?
- We can declare a member of a class as `static`, which indicates that it is not associated with any particular object of the class, rather, they are stored globally and independently.
- A non-`const` static variable must be initialize outside of a class.
---
#### Static modifier
```C++
struct Node { 
	int data; 
	Node* next;
	static int mostRecent;
	static int mostRecentIndex;
	
	int ith(int i) const {
		if (i == mostRecent) return mostRecent;
		if (i == 0) return data;
		Node *cur = next;
		for (int j = 1; j < i; ++j)
			cur = cur->next;p
		mostRecent = cur->data;
		return cur->data;
	} 
};
int Node::mostRecent = INT_MIN;
int Node::mostRecent = -1;

const Node n{30,nullptr};
n.ith(0); // compiles!
```
---
#### Static member function
- A member function can also be declared `static`
- Since `static` members are not associated with any object instances of the class, it doesn't come with a `this` pointer, and thus it cannot access any non-static fields.
- To invoke a `static` function use `ClassName::f()`
---
#### Comparing Objects
- In C, we can use `strcmp(str1, str2)` to compare two strings.
- In `C++`, thanks to operator overloading, we can use `>`, `<`, `>=`, `<=`, `==`  on strings as if we are comparing two integers.'
- Even better, comparison operator can be automatically derived by compiler.
---
#### Comparing Objects
- `bool operator<(const C&) const = default;` 
- Writing `= default` after the declaration will allow the compiler to generate a comparison operator that compares all the fields in lexicographical order.
- It will try to recursively call `operator<` on all the fields, provided that `operator<` is defined on their types.
- Any of the `<`, `>`, `<=`, `>=`, `==`, `!=` can be defaulted.
---
#### Spaceship operator
- The spaceship operator `<=>` supports three-way comparison.
- It can have either `std::strong_ordering`, `std::weak_ordering`, `std::partial_ordering` as return types.
- The valid values for the type `std::strong_ordering` are `std::strong_ordering::less`, `std::strong_ordering::greater`, `std::strong_ordering::equal`.
- But sometimes comparison does not make sense, in which case we can use `std::partial_ordering`, which has an additional outcome `std::partial_ordering::unordered`.
---
#### Spaceship operator
- In a lot of cases we can use `auto operator<=>(const C&, const C&) = default` for compiler to automatically generate a lexicographical spaceship comparison operator for us.
- It will also decide for us which return type makes the most sense.
---
#### Accessibility modifiers
- For structs, everything is by-default public. This means that any member function/variable can be accessed outside of the class.
- This is convenient, but has the drawback that the uses of the class can change it in a way that breaks its internal structure/invariants.
- We can restrict what someone outside of the class can see using the `private` and `public` keywords:
```C++
struct Node{ 
	int val;
  private:
	Node* next; 
};
```
---
#### Accessibility modifiers
- Everything after `private:` and before `public:` will only be accessible within the class, i.e. within methods. 
- Everything that is `public` will be accessible to everyone as before.
---
#### Nested classes
- We may want to create a class that doesn't make sense to exist on its own. 
- An example is implementing a “wrapper” class for some structure to restrict others’ ability to alter the class.
---
#### Nested classes
```C++
class LinkedList {
	struct Node { 
		int val; 
		Node* next;
    };

	int numNodes;
	Node *head;
	Node *tail;
  public:
	LinkedList(); 
	LinkedList(int amount, int what); // fill constructor
	void insertHead(int value); void insertTail(int value);
	void remove(int index);
};
```
---
#### Nested classes
- Since `Node` is declared within LinkedList, when we refer to the `Node` struct in our source code, we will refer to it as `LinkedList::Node`. This states that we are using the `Node` struct that is part of the `LinkedList` class.
- Note that since the Node struct is private within the `LinkedList` class, we will not be able to create instances of `Node`s outside of the `LinkedList` class. Our nodes are safe from others tampering with our `LinkedList` Nodes.
---
#### Iterators
- Iterators are used to traverse containers in some order.
- The order can be speciﬁed by the deﬁnition of the iterator, or not speciﬁed to be in any order.
- In C++, iterators are usually implemented with the following functions with in the container class (`Container`) and the nested iterator class (`Container::Iterator`):
---
#### Iterators
- `Container::begin()` — returns the iterator that represents the beginning of the iteration sequence.
- `Container::end()` — returns the iterator that represents the end of the iteration sequence (which is NOT included in the elements being iterated).
- `Container::Iterator::operator++()` (preﬁx) — increment the iterator by one, and return the incremented iterator.
- `Container::Iterator::operator!=(const Iterator &other)` — returns true if two iterators does not represent the same element, false otherwise.
- `Container::Iterator::operator*()` (unary) — return a reference of the element being represented by the iterator. It could also be a const reference, but what would you lose?
---
#### Class relationships
- There are three types of relationships between classes that we typically discuss:
	- **Composition(owns-a)**: class A owns an instance of class B. This means that class A is responsible for deleting the instance of class B when an object of class A is destroyed.
		- Under composition, instances of B cannot be shared once bound to an A.
	- **Aggregation(has-a)**: class A has an instance of class B. This means that class A is not responsible for deleting the instance of class B.
		- If an object of class A is deleted, the instance of class B associated with it lives on.
		- Multiple objects of class A can share the same instance of class B.
	- **Inheritance (is-a)**: class B is a class A. This means that an instance of class B can be used in any situation where an instance of class A can be used.
---
#### Class relationships
- **Inheritance (is-a)**: class B is a class A. This means that an instance of class B can be used in any situation where an instance of class A can be used.
	- The converse is not true. That is, an instance of class A cannot always be used where an instance of class B can be used.
	- In this course, we are mainly concerned with **public** inheritances.
---
#### Class relationships
- If a class A has a pointer to an instance of class B, you cannot know if the relationship is composition or aggregation without looking at documentation or code.
---
#### Class relationships
```C++
class B { ... };

class A { 
	B b1; // This is composition 
	B *b2; // This could be composition or aggregation 
};
```
---
#### Inheritance
```C++
class A {
	int a;
  public:
	explicit A(int a) : a{a} {}
};

class B : public A {
	int b;
  public:
    B(int a, intb): a{a}, b{b} {}	
};
```
---
#### Encapsulation and Inheritance
- If A has ﬁelds that are private, B cannot access these ﬁelds (as they are private within A).
- What are some beneﬁts of an inherited class not having direct access to the ﬁelds of the superclass?
---
#### Encapsulation and inheritance
- What are some beneﬁts of an inherited class not having direct access to the ﬁelds of the superclass?
	- Other people may inherit from our classes and this means they’d have access to the ﬁelds of the superclass in their implementation of their class, and this breaks encapsulation.
---
#### Encapsulation and Inheritance
- What are some beneﬁts of an inherited class not having direct access to the ﬁelds of the superclass?
	- Other people may inherit from our classes and this means they’d have access to the ﬁelds of the superclass in their implementation of their class, and this breaks encapsulation.
- However, we often want to give subclasses “special access” to the class.
	- For instance, we might want to have some accessor methods so that subclasses can access ﬁelds in a way that we choose, but we don’t want to let everyone have access to these members.
---
#### Encapsulation and Inheritance
- For this purpose, we can use the third type of accessibility: `protected`.
- Members that are protected can be accessed directly by subclasses but cannot be accessed by the public.
- **Note**: Most of the time you should not make ﬁelds `protected` as this also breaks encapsulation.
---
#### `virtual` and `override`
- When working with inherited classes, we will often want to deﬁne the methods so that it will work diﬀerently for separate subclasses.
---
#### Example
```C++
struct Animal {
	virtual bool fly() const {
		return false;
	} 
};

struct Bird : public Animal { 
	bool fly() const override { return true; } 
};

struct Goose : public Bird { 
	bool fly() const override { 
		cout << "THANK MR. GOOSE" << endl; 
		return true;
	} 
};
```
---
#### `virtual` and `override`
- Note that we have declared `fly()` as a virtual method.
	- Declaring a method virtual means if we override it in a subclass, the subclass version of the method will be called through polymorphic pointers or reference.
	- If we do not override the method, the deﬁnition in the closest related ancestor will be used. For instance, calling `fly()` on a `Cat` will return false.
---
#### Object slicing
- The virtual method will only be called when dealing with objects through **pointers/references**. 
	- This does *not* work when using objects directly:
```C++
Animal a = Bird{};
a.fly();
```
- Creates an rvalue of type `Bird`,  which is then object-sliced into an `Animal` object, a. 
- Calls the `Animal::fly()` method, so returns `false`.
---
#### `virtual` and  `override`
- Using the keyword override tells the compiler to check that the method is actually overriding a virtual method in a superclass. This causes a compiler error if it can’t ﬁnd a virtual function of the same signature.
---
#### `virtual` and  `override`
- Using the keyword `override` tells the compiler to check that the method is actually overriding a virtual method in a superclass. This causes a compiler error if it can’t ﬁnd a virtual function of the same signature.
	- This is in fact not required, but strongly recommended.
---

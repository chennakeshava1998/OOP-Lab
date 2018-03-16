#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	// A class is abstract if it has aleast one pure virtual function
	// Pure virtual functions are those, for which we donot know the definition in the base class

	virtual void pure_virtual_func() = 0;
	// What happens if I comment the definition of pure virtual function in base class ??
	// It returns an error saying there is no member called pure_virtual_func() in the base class A

	virtual void func()
	{
		cout << "Calling Virtual function in base class\n";
	}
};

class B : public A
{
	/* This program works even if this function is private - Run-time polymorphism
	* Compiler check for  types only at compile time
	* But virtual functions are resolved only at run-time
	* Accesssing Virtual functions using pointers: The virtual functions to be called depends on what is being pointed to by the pointer, not the declaration of the pointer itself.
	*/


	void func()
	{
		cout << "Calling Virtual function in derived class\n";
	}

	void pure_virtual_func()
	{
		cout << "This is a pure virtual function in the child class\n"; 
	}
};

int main()
{
	A *obj;
	// Can't create an object for class-A now, A is an abstract class
	// I wrote the below code to show the definition of virtual classes in base and child class
	// obj = &obj_A; // You can't call the member function of parent class with only a pointer, you need to have an object
	// obj->func();
	
	B obj_B;
	obj = &obj_B;
	obj->func(); // You can't use obj.func(); - This syntax refers to the base class members only !! There is a difference between '.' operator and -> operator
	obj->pure_virtual_func();

	/* Interesting stuff from https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
	1. A class wirth atleast one pure virtual function is an abstract class
	2. You cannot create objects for an abstract class
	3. You can declare and use pointers and references for an abstract class
	!!! What is the difference between pointers and references??
	4. If we donot override the pure virtual function in the derived class, the the derived class also becomes abstract.
	Basically all derived classes which donot override the pure virtual function becomes abstract classes. Because
	the derived class will inherit the pure virtual function from the base abstract class.
	5. Abstract classes can have constructors. These constructors can be used in the constructors of child classes, for initialising the variables of child classes.  
	6. Interface in Java can be simulated with a collection of pure virtual functions in c++. Basically, an
	interface only has declaration of functions, and not any of their implementation
	*/
	
	return 0;
} 
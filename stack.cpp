#include<iostream>
using namespace std;
#define size 5

template<typename T>
class stack
{
private:
	int head;
	T arr[size];
public:
	stack()
	{
		// size = 100;
		head = -1; // using head = 0. causes a lot of problems
		cout << "Initialising a stack object. Constructing an array of size " << size << "\n";
	}

	void push(T value);

	T pop();
	
	// function for debugging purposes
	void disp()
	{
		int tmp = head;
		cout << "\nStack\n";
		while(tmp >= 0)
		{
			cout << arr[tmp] << " ";
			--tmp;
		}

		cout << "\n";
	}
};

// catch the overflow possibilitites
template<typename T> void stack<T>::push(T value)
{
	try
	{
		if(head == size)
			throw; // we need not throw any specific object also

		++head;
		arr[head] = value;
		
	}
	catch(...)
	{
		cout << "Overflow Exception!\n";
	}

	cout << value << " is pushed\n";
}

// catch underflow possibility
template<typename T> T stack<T>::pop()
{
	T tmp;
	try
	{
		if(head < 0)
			throw 10; // we can throw a specific value/object, for ease of catching them

		tmp = arr[head];
		--head;
	}
	catch(int n)
	{
		cout << "Underflow Exception!.Exception Number = " << n << "\nGarbage Value is returned\n";
	}

	return tmp;
}

int main()
{
	// I have created 3 types of stacks of different types to illustrate templates
	stack<int>obj;
	obj.push(100);
	// obj.disp();
	obj.push(200);
	// obj.disp();
	obj.push(300);
	// obj.disp();
	obj.push(400);
	// obj.disp();

	cout << "Popping all the elements\n";
	cout << obj.pop() << "\n";
	cout << obj.pop() << "\n";
	cout << obj.pop() << "\n";
	cout << obj.pop() << "\n";
	cout << obj.pop() << "\n";


	cout << "\n\nCreating another stack of type char\n";
	stack<char>a;
	a.push('a');
	a.push('b');
	a.push('c');
	a.push('d');
	cout << "Popping all the elements\n";
	cout << a.pop() << "\n";
	cout << a.pop() << "\n";
	cout << a.pop() << "\n";
	cout << a.pop() << "\n";
	cout << a.pop() << "\n";

	cout << "\n\nCreating another stack of type double\n";
	stack<double>b;
	b.push(1.1);
	b.push(2.2);
	b.push(3.3);
	b.push(4.4);
	cout << "Popping all the elements\n";
	cout << b.pop() << "\n";
	cout << b.pop() << "\n";
	cout << b.pop() << "\n";
	cout << b.pop() << "\n";
	cout << b.pop() << "\n";

	return 0;
}
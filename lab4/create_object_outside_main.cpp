#include<bits/stdc++.h>
using namespace std;
// creating the constructor inside the private space rules out the possibility of creating objects from main
// or other functions.
class A
{
	private:
	int a;
	A()
	{
		a = 10;
	}

// defining disp() in private causes error. If friend function can access private space, why is the error caused?? 
// If the object is further used, will it be destroyed after exiting the scope of the friend function?? - For objects created with friend function
public:
	friend A creator();
	void disp()
	{
		cout<<"a = "<<a<<endl;
	}

	
};

A creator()
{
	A obj;
	return obj;
}

int main()
{
	creator().disp();
}
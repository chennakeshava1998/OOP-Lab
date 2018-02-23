#include<bits/stdc++.h>
using namespace std;

class animal
{
protected:               // private members cannot be accessed by child classes, hence make this section (containing variables as protected)
	bool mammal;
	int legs;
	string name;

public:
	void disp()
	{
		cout<<"Entered info:\n" << endl;
		cout << "Animal's name :\t" << name << endl;
		cout << "No. of legs :\t" << legs << endl;
		cout << "Mammal? :\t" << mammal << endl;
	}
};


class dog : public animal  // a child class calls the constructors of all its parent classes,
// if it's object is created
{
public:
	void get(string s)  // setting parents proetected data member variables from the child class
	{
		name = s;
		bool f;
		cout << "Creating a constructor for " << name<<"\n";

		cout << " Enter the number of legs" << "\n";
		cin >> legs;

		cout << "Is "<<name<<" a mammal??? Enter 1(True) or 0(False)" << "\n";
		cin >> mammal;
	} 
};


int main()
{
	dog obj;
	string ani;
	cout << "Enter the name of the animal\n";
	cin >> ani;
	obj.get(ani);
	obj.disp();   // calling member function of parent class from the child class
	return 0;
}

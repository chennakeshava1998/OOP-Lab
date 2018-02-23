#include<bits/stdc++.h>
using namespace std;
// In multi-level inheritance, if B < A, and C < b ===> creating an object in C will call constructors of
// A, B and C in this particular order only.
// Desctructors are called in reverse order. IMP!!
class a
{
public:
	a() {cout<<"Constructor of a is called\n";}
};

class b : public a
{
public:
	b(){cout<<"Constructor of b is called\n";}
};

class c : public b {
	public:
		c() {cout << "Constructir of C is called\n";}
};
int main()
{
	c obj;
	return 0;
}
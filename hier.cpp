#include<bits/stdc++.h>
using namespace std;
// the order of caaling constructors is the same as in multi-level inheritance
class a
{
public:
	a() {cout<<"Constructor of a is called\n";}
};

class b : virtual public a {
public:
	b(int x) {cout<<"Constructor of b is called\n" << x << " has been passed as a parameters to this constructor\n\n";}
};

class c : virtual public a {
public:
	c(int x) {cout<<"Constructor of c is called\n"<< x << " has been passed as a parameters to this constructor\n\n";}
};

int main()
{
	c obj(10);
	c obj1(100);
	return 0;
}
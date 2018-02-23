#include<bits/stdc++.h>
using namespace std;

class a
{
public:
	a() {cout<<"Constructor of a is called\n";}
};

class b
{
public:
	b(){cout<<"Constructor of b is called\n";}
};

class c : public b, public a {};

int main()
{
	c obj;
	return 0;
}
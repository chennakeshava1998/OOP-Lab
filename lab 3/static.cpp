#include<bits/stdc++.h>
using namespace std;

class C
{
private:
	
public:
	static int count;
	void incre()
	{
		count++;
	}

};

int C::count = 0;

int main()
{
	cout << "Initial value of static variable count = " <<C::count<<"\n";
	C a;
	C b;
	C c;
	cout << "Initial value of static variable count = " <<C::count<<"\nThe initial value is persistent across objects of that class\n\n";
	for(int i=0;i<12;++i)
	{
		a.incre();
		b.incre();
		c.incre();
		cout << "Value of staic variable count after iteration "<<i<<" = "<<C::count<<"\n\n";
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;

class C
{
private:
	double real, imag;
	

public:
	C operator+(C c);
	friend void disp(C c);
	C(double x, double y)
	{
		real = x;
		imag = y;
	}

	C()
	{
		real = 0;
		imag = 0;
	}
};

void disp(C c)
{
	cout << "Real Part of the Complex Number = " << c.real << "\n\n";
	cout << "Imaginary Part of the Complex Number = " << c.imag << "\n\n";

}

C C::operator+(C c)
{
	C r;
	r.real = this->real + c.real;
	r.imag = this->imag + c.imag;

	return r;
}

int main()
{
	cout << "Program to perform addition of complex numbers\n\n";
	double x, y;
	cout<<"Enter the real and imaginary parts of the first complex nnumber\n";
	cin >> x >> y;

	C a(x, y);

	cout<<"Enter the real and imaginary parts of the second complex nnumber\n";
	cin >> x >> y;

	C b(x, y);

	C ans;
	ans = a + b;

	cout << "Answer after addition:\n";
	disp(ans);


	cout << "Program to perform addition of multiple complex numbers\n\n";

	C c(1.2, 4.6);
	C d(4, 5);
	C e(4.6, 4.5);

	cout << "Series of Numbers that are added are:\n";
	disp(a);disp(b);disp(c);disp(d);disp(e);

	ans = a + b + c + d + e;
	cout << "Result after adding multiple numbers\n";
	disp(ans);





	return 0;
}
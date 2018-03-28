#include<iostream>
using namespace std;

template<typename A, typename B> void hello(A *arr, B *brr, int size)
{
	int i;
	for(i=0;i<size;++i)
		*(brr + i) = *(B*)(arr + i);
}

int main()
{
	int i, arr[10];
	char brr[10];
	
	for(i=0;i<10;++i)
		arr[i] = i + 97; // interpretable characters

	cout << "before function call\n";
	for(i=0;i<10;++i)
		cout << brr[i] << " ";
	cout << "\n";

	hello<int, char>(arr, brr, 10);

	cout << "after function call\n";
	for(i=0;i<10;++i)
		cout << brr[i] << " ";
	cout << "\n";

	return 0;
}
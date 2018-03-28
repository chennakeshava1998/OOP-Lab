// file input output
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
	ofstream out_file("output.txt", ios::binary | ios::out); // opening a file using constructor
	cout << "Enter a line of text\n";
	char s[300];
	cin.get(s, 300);
	out_file << s << "\n";
	cout << "The text stored has been stored in " << "output.txt" << ". The length of the written data is = " << strlen(s) << "\n";

	ifstream is; // initialising the ifstream object with the input file
	is.open("output.txt", ios::binary | ios::in);
	char c;
	
	is >> s;
	cout << s << "\n";
	


	// opening multiple files using the same handle - works, even if I have not closed this file handle before
	out_file.open("another_file.txt", ios::binary | ios::out);
	out_file << "I have opened another file using out_file handle\n";
	ofstream of("another_file.txt", ios::binary | ios::app);
	of << "I have appended to this file\n";
	out_file.close();
	of.close();
	is.close();


	return 0;
}
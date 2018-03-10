#include<iostream>
#include<fstream>
#include<cmath>

# define MAX_ROW_SIZE 100000

using namespace std;

class Img
{
	ifstream in;
	ofstream of;

public:
	Img(char* path)
	{
		in.open(path, ios::binary);
	}
	
	void conv2gray(char* output);
};

void Img::conv2gray(char* file)
{
	cout << "Entered the conversion function\n";
	of.open(file, ios::binary);
	char info[54]; // headers are 54 bytes long in bmp files
	int i;

	in.read(info, 54);
	of.write(info, 54); // retaining the header of the files

	

	int width = *(int *)(&info[18]);
	int height = *(int *)(&info[22]);

	
	int row_size = 4 * ceil((width * 3)/4);

	unsigned char tmp[row_size], to_write[row_size];

	for(int i=0;i<height;++i)
	{
		in.read((char*)tmp, row_size);
		for(int j=0;j<width*3;j+=3)
		{
			int avg = (int)tmp[j] + (int)tmp[j+1] + (int)tmp[j+2];
			avg /= 3;

			to_write[j] = avg;
			to_write[j + 1] = avg;
			to_write[j + 2] = avg;
		}	
		
		of.write((char*)to_write, row_size);
	}

	cout << "Completed transformation\n";

	in.close();
	of.close();
}

int main()
{
	char* in = "cat.bmp";
	char* out = "ans.bmp";
	Img a(in);
	a.conv2gray(out);
}
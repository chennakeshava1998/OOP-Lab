#include<iostream>
#include<fstream>
#include<cmath>

# define MAX_ROW_SIZE 100000

using namespace std;

class Img
{
	ifstream in;
	ofstream of, neg;
	int intensity[256]; // stores the number of pixels having an intensity intensity[i]

public:
	Img(char* path)
	{
		in.open(path, ios::binary);

		for(int i=0;i<256;++i)
			intensity[i] = 0;
	}
	
	void conv2gray(char* file_gray, char* file_neg);
};

void Img::conv2gray(char* file_gray, char* file_neg)
{
	
	of.open(file_gray, ios::binary);
	neg.open(file_neg, ios::binary);
	char info[54]; // headers are 54 bytes long in bmp files
	int i;

	in.read(info, 54);
	of.write(info, 54); // retaining the header of the files
	neg.write(info, 54);
	

	int width = *(int *)(&info[18]);
	int height = *(int *)(&info[22]);

	
	int row_size = 4 * ceil((width * 3)/4);

	unsigned char tmp[row_size], to_write[row_size], to_write_negative[row_size];

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

			
			++intensity[avg];

			to_write_negative[j] = 255 - tmp[j];
			to_write_negative[j + 1] = 255 - tmp[j + 1];
			to_write_negative[j + 2] = 255 - tmp[j + 2];
		}	
		
		of.write((char*)to_write, row_size);

		neg.write((char*)to_write_negative, row_size);
	}

	in.close();
	of.close();
	neg.close();

	cout << "Histogram of intensities\n";
	cout << "Index\tIntensity\tHistogram\n";

	for(int i=0;i<256;i += 16)
	{		
		int sum = 0;

		for(int j=i;j<i+16;++j)
			sum += intensity[j];

		cout << i << "-" << i+16 << "\t" << sum << "\t\t";

		int j = sum;
		
		while(j > 0)
		{
			j -= 100;
			cout << "*";
		}
		cout << "\n";
	}
}

int main()
{
	char* in = "cat.bmp";
	char* file_gray = "out_gray.bmp";
	char* file_neg = "out_negative.bmp";
	Img a(in);
	a.conv2gray(file_gray, file_neg);
}
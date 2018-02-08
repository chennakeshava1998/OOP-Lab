#include<bits/stdc++.h>
using namespace std;

class Perceptron
{
private: float w[3], alpha;int num_iter, t;//threshold 
public: // these functions and data are used by subclasses
	void train();
	void test();
	int hyp(int x, int y);
	int X[4][3], y[4];

	Perceptron()
	{
		X[0][0] = 0;
		X[0][1] = 0;
		X[1][0] = 0;
		X[1][1] = 1;
		X[2][0] = 1;
		X[2][1] = 0;
		X[3][0] = 1;
		X[3][1] = 1;
		alpha=0.1;
		num_iter=1000;
		t = 1.5;

		for(int i=0;i<4;++i) 
		{
			y[i] = X[i][0] | X[i][1];
			X[i][2] = 1;
		}

		w[0] = rand()%3;
		w[1] = rand()%4;
		w[2] = rand()%2;

		cout<<"Learning rate = "<<alpha<<"\nNumber of iterations = "<<num_iter<<"\n\n";
	}

	friend void display(Perceptron p); // displays training data
};

void display(Perceptron p)
{
	cout<<"Training data in Perceptron class\n";
	for(int i=0;i<4;++i)
	{
		cout<<p.X[i][0]<<" AND "<<p.X[i][1]<<" = "<<p.y[i]<<" bias = "<<p.X[i][2]<<"\n";
	}
}

int Perceptron::hyp(int x, int y)
{
	double sum = (w[2] + w[1]*x + w[0]*y);
	if(sum >= t) return 1;
	else return 0;
}


void Perceptron::test()
{
	for(int i=0;i<4;++i)
	{
		cout<<"Inputs: "<<X[i][0]<<" \t"<<X[i][1]<<" \tAnswer: "<<hyp(X[i][0], X[i][1])<<"\n";
	}
}


void Perceptron::train()
{
	int i=0;
	double error=0, upd[3];

	

	cout<<"Weights before training are: Constant = "<<w[2]<<" and "<<w[1]<<" "<<w[0]<<"\n";

	

	int count = 0;
	double gerror = 0,rerror;
	do{
		count++;
		gerror = 0;
		for(i=0;i<4;++i)
		{
			error = y[i]-hyp(X[i][0], X[i][1]) ;
			//cout<<"Error = "<<error<<"\n";	
			for(int j=0;j<3;++j)
			{
				w[j] = w[j] + error * alpha * X[i][j];
				//cout<<w[j]<<" ";
			}
			//cout<<endl;
			gerror += error*error;
		}
		rerror = sqrt((double)gerror/4);
		
	}while(rerror!=0 && count<=num_iter);

		
			
	
	cout<<"Weights after training are: Constant/bias = "<<w[2]<<" and "<<w[1]<<" "<<w[0]<<"\n\n"<<"Test Data : \n";
}




int main()
{
	cout<<"Program to Train a Neural Network to learn OR Gate function\n\n";
	srand(100);
	Perceptron p;

	display(p);
	cout<<"\n";
	
	
	
	p.train();
	p.test();



	return 0;
}
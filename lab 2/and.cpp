#include<bits/stdc++.h>
using namespace std;

class Perceptron
{
private: float w[3], alpha=0.1;int num_iter=10, t = 1.5;//threshold 
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

		for(int i=0;i<4;++i) 
		{
			y[i] = X[i][0] & X[i][1];
			X[i][2] = 1;
		}

	 //    w[0] = (float)rand()/RAND_MAX;
		// w[1] = (float)rand()/RAND_MAX;
		// w[2] = (float)rand()/RAND_MAX;
		w[0] = rand()%3;
		w[1] = rand()%3;
		w[2] = rand()%3;

		cout<<"learning rate = "<<alpha<<" number of iterations = "<<num_iter<<"\n";
	}

	void display(); // displays training data
};

void Perceptron::display()
{
	cout<<"training data in Perceptron class\n";
	for(int i=0;i<4;++i)
	{
		cout<<X[i][0]<<" AND "<<X[i][1]<<" = "<<y[i]<<" bias = "<<X[i][2]<<"\n";
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

	// for(int k=0;k<num_iter;++k)
	// {
		
		
		
	// 	for(i=0;i<4;++i)
	// 	{
	// 		error = hyp(X[i][0], X[i][1]) - y[i];
	// 		for(int j=0;j<3;++j)
	// 		{
	// 			w[j] = w[j] + error * alpha * X[i][j];
	// 			cout<<w[j]<<" ";
	// 		}
	// 		cout<<endl;
		
	// 	}

		

	

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

		
			
	
	cout<<"Weights after training are: Constant/bias = "<<w[2]<<" and "<<w[1]<<" "<<w[0]<<"\n";
}




int main()
{
	srand(0);
	Perceptron p;

	p.display();
	
	
	
	p.train();
	p.test();



	return 0;
}
#include <iostream>
#include <armadillo>
#define pi 3.14159

using namespace arma;
using namespace std;

int main()
{
	mat A,B,C;

	float d1=0.0,d2=0.0,d3=0.0;




	for(float i=0;i<=0.75;i+=0.01)
	{
		cout << i << endl;
		for(float p=0;p<=0.5;p+=0.01)
		{
			for(float o=0;o<=0.5;o+=0.01)
			{
				d1 = o;
				d2 = p*sin(pi/2);
				d3 = i*sin(pi/2);
				
				A << d1 << d2 << d3 << endr;

				B = join_cols(B,A);


			}
		}
	}


	B.print("");
	B.save("test1.txt",raw_ascii);


	return 0;
}
#include <iostream>
#include <armadillo>
#define pi 3.14159

using namespace arma;
using namespace std;

int main()
{
	mat A,B,C;

	double d1=0.0,d2=0.0,l3=360;
	double phi = 0.0;
	double x=0.0,y=0.0;

	for(double fi1=0.0;fi1<=pi/4;fi1+=0.1)
	{
		cout << fi1 << endl;
		for(double d1=153;d1<=210;d1+=1)
		{
			for(double d2=153;d2<=210;d2+=1)
			{
				for(double fi2=0.0;fi2<=pi/4;fi2+=0.1)
				{
					for(double fi3=0.0;fi3<=pi/4;fi3+=0.1)
					{
						x = d1*cos(fi1)+d2*cos(fi1+fi2)+l3*cos(fi1+fi2+fi3);
						y = d1*sin(fi1)+d2*sin(fi1+fi2)+l3*cos(fi1+fi2+fi3);  
				
						A << x << y << endr;

						B = join_cols(B,A);
					}
				}
			}
		}
	}


	B.print("");
	B.save("trabajoa.txt",raw_ascii);


	return 0;
}

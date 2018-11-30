#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

int main()
{
	mat A,B,C;
	mat W1(3,1),W2(3,1),W3(3,1),W4(3,1),W5(3,1),Valfa(3,1);
	A.zeros(),B.zeros(),C.zeros();
	int Rm = 100, Ralfa=50, Km=2, Kalfa=5, x2=0, y2=0, xi=0, yi=0, xm=25, ym=50;
	double Vm = 0.0;
	double Vv=0.0;
	double Vo1 = 0.0, Vo2 = 0.0, Vo3=0.0, Vo4 =0.0, Vo5=0.0; 
	float xo1=18.0, yo1=30.0, xo2=0.5, yo2 = 5.0, xo3=9.0, yo3=20.0, xo4=1.0, yo4=60.0, xo5=15.0, yo5=60.0;
	//double di[];


	for(int y=0;y<=100;y++)
	{
		
		for(int x=0;x<=100;x++)
		{
			A.zeros();
			x2 = pow((xm-x),2);
			y2 = pow((ym-y),2);
			Vo1=0.0, Vo2=0.0, Vo3=0.0, Vo4=0.0, Vo5=0.0;

			A << x << endr
			  << y << endr
			  << 1 << endr
			  << 0 << endr;

			Vm = (-Km*exp((sqrt(x2+y2))/Rm))/(Rm*sqrt(x2+y2));

			if((abs(xo1-x) <= Ralfa) or (abs(yo1-y) <= Ralfa))
				Vo1 = (Kalfa*exp(-sqrt(pow((xo1-x),2.0)+pow((yo1-y),2.0))/Ralfa))/(Ralfa*sqrt(pow((xo1-x),2.0)+pow((yo1-y),2.0)));

			if((abs(xo2-x) <= Ralfa) or (abs(yo2-y) <= Ralfa))
				Vo2 = (Kalfa*exp(-sqrt(pow((xo2-x),2.0)+pow((yo2-y),2.0))/Ralfa))/(Ralfa*sqrt(pow((xo2-x),2.0)+pow((yo2-y),2.0)));

			if((abs(xo3-x) <= Ralfa) or (abs(yo3-y) <= Ralfa))
				Vo3 = (Kalfa*exp(-sqrt(pow((xo3-x),2.0)+pow((yo3-y),2.0))/Ralfa))/(Ralfa*sqrt(pow((xo3-x),2.0)+pow((yo3-y),2.0)));

			if((abs(xo4-x) <= Ralfa) or (abs(yo4-y) <= Ralfa))
				Vo4 = (Kalfa*exp(-sqrt(pow((xo4-x),2.0)+pow((yo4-y),2.0))/Ralfa))/(Ralfa*sqrt(pow((xo4-x),2.0)+pow((yo4-y),2.0)));

			if((abs(xo5-x) <= Ralfa) or (abs(yo5-y) <= Ralfa))
				Vo5 = (Kalfa*exp(-sqrt(pow((xo5-x),2.0)+pow((yo5-y),2.0))/Ralfa))/(Ralfa*sqrt(pow((xo5-x),2.0)+pow((yo5-y),2.0)));

				//Vo1 = (Kalfa*exp(-sqrt(pow((xo1-x),2)+pow((yo1-y),2))/Ralfa))/(Ralfa*sqrt(pow((xo1-x,2)+pow((yo1-y),2)));

			Vv=Vo1+Vo2+Vo3+Vo4+Vo5;

			A(2,0) = Vm;
			A(3,0) = 0.02+(Vv+Vm);
			A = trans(A);
			B = join_cols(B,A); 
		}

	}

	B.print("Matriz");
	B.save("test.txt", arma_ascii);

	return 0;
}

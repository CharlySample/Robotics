#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x=0.0,y=0.0;

	for(x=0.1;x<=10;x+=0.1)
	{
		y = sin(x);
		cout << y << "\t" << atan(y/x) << "\t" << sqrt(pow(x,2) + pow(y,2)) << endl;
	}


	return 0;
}
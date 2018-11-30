#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main()
{
	int eta=0;
	double vel=0.0,vel1=0.0,vel2=0.0;
	ofstream fp("servo1.txt");
	ofstream fp1("servo2.txt");
	ofstream fp2("servo3.txt");

	for(int dato=0;dato<=100;dato++)
	{
		vel =    0.000053340+0.21475*dato-0.000099040*pow(dato,2)-0.000025995*pow(dato,3);
		vel1 =  -0.00022017+0.21870*dato-0.00019559*pow(dato,2)-0.000025174*pow(dato,3);
		vel2 = 0.00011750+0.23312*dato-0.00045829*pow(dato,2)-0.000024176*pow(dato,3);
		cout << dato << ", servo1: " << vel << " servo2: " << vel1 << " servo3: " << vel2 << endl;
		fp << dato << ", " << vel << endl;
		fp1 << dato << ", " << vel1 << endl;
		fp2 << dato << ", " << vel2 << endl;
	}

fp.close();
fp1.close();
fp2.close();

	return 0;
}
#include <armadillo>
#include <cmath>
#include <iostream>

using namespace std;
using namespace arma;

int main()
{
	mat j,pref,p, phi, phi1, p1,A,B;
	double error=100.0;

	pref << 0.4 << endr << 0.2 << endr;
	phi << 0 << endr << 0.35 << endr;
	phi1 << 0 << endr << 0 << endr;
	p1 << 0 << endr << 0 << endr;
	p << 0.35 << endr << 0 << endr;
	j << -phi(0,0)*sin(phi(1,0)) << cos(phi(1,0)) << endr << phi(0,0)*cos(phi(1,0)) << sin(phi(1,0)) << endr;

       A << 0.35  << 0 << endr;
       B << 0 << 0.35 << endr;

	while(error >= 0.0001)
	{
		phi1 = phi + pinv(j) * 0.25*(pref-p);
		p1 = p + j * 0.90*(phi1 - phi);

		error = sqrt(pow((pref(0,0) - p(0,0)),2) + (pow((pref(1,0) - p(1,0)),2)) ); 
		phi = phi1;
		p= p1;
		j << -phi(1,0)*sin(phi(0,0)) << cos(phi(0,0)) << endr << phi(1,0)*cos(phi(0,0)) << sin(phi(0,0)) << endr;

		A = join_cols(A,trans(p));
		B = join_cols(B, trans(phi));

		cout << error << endl;


	}

	A.print("");
	A.save("control.txt", raw_ascii);
        B.save("mover.txt", raw_ascii);

	return 0;
}

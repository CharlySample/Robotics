#include <armadillo>
#include <cmath>
#include <iostream>

using namespace std;
using namespace arma;

int main()
{
	mat j,pref,p, phi, phi1, p1,A,B;
	double error=100.0;
        double fi0 = 0, fi1 = 0, fi2 = 0, fi3 = 0, l3 = 360, d1= 153, d2 = 153;
        double c0, c1, c12, c123, s0, s1, s12, s123;

	phi << fi1 << d1 << fi2 << d2 << fi3 << endr;
        phi = trans(phi);

        c1 = cos(phi(0,0));
        c12 = cos(phi(0,0)+phi(2,0));
        c123 = cos(phi(0,0)+phi(2,0)+phi(4,0));
        s1 = sin(phi(0,0));
        s12 = sin(phi(0,0)+phi(2,0));
        s123 = sin(phi(0,0)+phi(2,0)+phi(4,0));
        d1 = phi(1,0);
        d2 = phi(3,0);

	pref << 500 << 400 << endr;
        pref = trans(pref);
	phi1 << 0 << 0 << 0 << 0 << 0 << endr;
        phi1 = trans(phi1);
	p1 << 0 << 0 << endr;
        p1 = trans(p1);
	p << 1050 << 0 << endr;
        p = trans(p);
	j << -(d1*s1)-(d2*s12)-(l3*s123) << c1 << -(d2*s12)-(l3*s123) << c12 << -(l3*s123) << endr
          << (d1*c1+d2*c12+l3*c123) << s1 << (d2*c12)-(l3*c123) << s12 << (l3*c123) << endr;

       A << 1050 << 0 << endr;
       B << fi1 << d1 << fi2 << d2 << fi3 << endr;

	while(error >= 0.0001)
	{
		phi1 = phi + pinv(j) * 0.25*(pref-p);
		p1 = p + j * 0.90*(phi1 - phi);

		error = sqrt(pow((pref(0,0) - p(0,0)),2) + (pow((pref(1,0) - p(1,0)),2)) ); 
		phi = phi1;
		p= p1;

        	c1 = cos(phi(0,0));
        	c12 = cos(phi(0,0)+phi(2,0));
        	c123 = cos(phi(0,0)+phi(2,0)+phi(4,0));
        	s1 = sin(phi(0,0));
        	s12 = sin(phi(0,0)+phi(2,0));
        	s123 = sin(phi(0,0)+phi(2,0)+phi(4,0));
        	d1 = phi(1,0);
        	d2 = phi(3,0);

		j << -(d1*s1)-(d2*s12)-(l3*s123) << c1 << -(d2*s12)-(l3*s123) << c12 << -(l3*s123) << endr
          	<< (d1*c1+d2*c12+l3*c123) << s1 << (d2*c12)-(l3*c123) << s12 << (l3*c123) << endr;

		A = join_cols(A,trans(p));
		B = join_cols(B, trans(phi));

		cout << error << endl;
	}

	A.print("");
	A.save("controla.txt", raw_ascii);
        B.save("movera.txt", raw_ascii);

	return 0;
}

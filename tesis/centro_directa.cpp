#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	float r=0.15,a=2,b=1;
	float x=0.0,y=0.0,vmax=1.5,xz=0.0,yz=0.0;
	mat phi, J, u,dummy,cordi,dums;

	phi << 0 << endr << 0 << endr << 0 << endr << 0 << endr;
	u << 0 << endr << 0 << endr << 0 << endr << 0 << endr;
	dummy << 0 << 0 << 0 << 0 << endr;
	cordi << 0 << 0 << 0 << 0 << endr;


	for(int i=0;i<=2000;i++)
	{
		J << r/4 << r/4 << r/4 << r/4 << endr
		  << (b*r)/(2*(pow(a,2)+pow(b,2))) << (b*r)/(2*(pow(a,2)+pow(b,2))) << -(b*r)/(2*(pow(a,2)+pow(b,2))) << -(b*r)/(2*(pow(a,2)+pow(b,2))) << endr
		  << (b*r)/(vmax) << -(b*r)/(vmax) << -(b*r)/(vmax) << (b*r)/(vmax) << endr
		  << -(a*r)/(vmax) << (a*r)/(vmax) << -(a*r)/(vmax) << (a*r)/(vmax) << endr;
     
        if(i<1000)
        {
        	phi(0,0) +=0.1;
        	phi(1,0) +=0.23;
        	phi(2,0) +=0.12;
        	phi(3,0) +=0.09; 
        }

        else if(i>=1000)
        {
        	phi(0,0) +=0.04;
        	phi(1,0) +=0.13;
        	phi(2,0) +=0.23;
        	phi(3,0) +=0.11; 
        }


        u = J*phi;
        cordi(0,0) = u(0,0)*cos(u(1,0));
        cordi(0,1) = u(0,0)*sin(u(1,0));
 	    xz = (sqrt(pow(u(2,0),2) + pow(u(3,0),2)) * cos(u(1,0)));
        yz = (sqrt(pow(u(2,0),2) + pow(u(3,0),2)) * sin(u(1,0)));
        cordi(0,2) = xz;
        cordi(0,3) = yz;
        dums = join_cols(dums,cordi);
        dummy = join_cols(dummy,trans(u));

	}

	dummy.save("centro_directa.txt",raw_ascii);
	dums.save("dums.txt",raw_ascii);


	return 0;
}
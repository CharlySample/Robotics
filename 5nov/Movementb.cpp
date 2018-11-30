
/* Movement Library 

Esta libreria contiene funciones , las cuales se comunican con la consola Python de FreeCAD para mover componentes.

 Compilacion:
 g++ -g -shared -fPIC Movementb.cpp -o MoveModuleb.so -I/usr/include/python2.7 -lpython2.7 -lboost_python-2.7 -larmadillo -lreflapack -lrefblas

*/

#include <boost/python.hpp>
#include <armadillo>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <cmath>
#define pi 3.14159

using namespace arma;

class Movement
{
  public:

  double w1, v;
  mat j,pref,p, phi, phi1, p1,A,B, C, alfa;
  double fi0 = 0, fi1 = 0, fi2 = 0, fi3 = 0, l3 = 0.360, d1= 0.153, d2 = 0.153;
  double c0, c1, c12, c123, s0, s1, s12, s123, error = 100.0;
  double phi0, phi11, phi2, phi3;
  /* ENGRANE -> ENGRANE
  La funcion recibe el angulo intantaneo del engran conductor "w0", el radio del engran conductor "r0", el radio del engran conducido "r1" y un valor booleano   
  "direction". Este valor debera ser 0 para situaciones en que deben girar en el mismo sentido, y 1 para cuando giran en sentidos contrarios 
  Regresa la posicion instantanea "w1" del engran conducido */

  void gearToGear(double w0, double r0, double r1, bool direction)
  {
    w1 = r0*w0/r1;
    if(direction==1)
    w1*=-1;
  }
  
  // Funcion Oscilante
  void oscilar(double w,double z)
  {
    v = z*sin(w);
  }

  void brazo(int t)
 {
       if(t == 0)
	{
	phi << fi0 << fi1 << d1 << fi2 << d2 << fi3 << endr;
        phi = trans(phi);
      
	}

	      c0 = cos(phi(0,0));
        c1 = cos(phi(1,0));
        c12 = cos(phi(1,0)+phi(3,0));
        c123 = cos(phi(1,0)+phi(3,0)+phi(5,0));
	      s0 = sin(phi(0,0));
        s1 = sin(phi(1,0));
        s12 = sin(phi(1,0)+phi(3,0));
        s123 = sin(phi(1,0)+phi(3,0)+phi(5,0));
        d1 = phi(2,0);
        d2 = phi(4,0);

	if(t==0)
	{
	pref << 1.2 << 0  << 1 << endr;
        pref = trans(pref);
	phi1 << 0 << 0 << 0 << 0 << 0 << 0 << endr;
        phi1 = trans(phi1);
	p1 << 0 << 0 << 0 << endr;
        p1 = trans(p1);
	p << 1 << 0 <<  0 << endr;
        p = trans(p);
	j << -(d1*c1*s0)-(d2*c12*s0)-(l3*c123*s0) << -(d1*s1*c0)-(d2*s12*c0)-(l3*s123*c0) << c1*c0 << -(d2*s12*c0)-(l3*s123*c0) << c12*c0 << -l3*s123*c0 << endr
          << (d1*c1*c0)+(d2*c12*c0)+(l3*c123*c0) << -(d1*s1*s0)-(d2*s12*s0)-(l3*s123*s0) << c1*s0 << -(d2*s12*s0)-(l3*s123*s0) << c12*s0 << -l3*s123*s0 << endr
          << 0 << (d1*c1)+(d2*c12)+(l3*c123) << s1 << (d2*c12)+(l3*c123) << s12 << (l3*c123) << endr;
	}

	if(error <= 0.0001)
	{
		pref << ((0.8*sin(t))+1.1) << endr << 0 << endr << (0.2*sin(t)+0.2) << endr;
		error = 100;
	}

	else if(error >= 0.0001)
	{
		phi1 = phi + pinv(j) * 0.25*(pref-p);
		p1 = p + j * 0.90*(phi1 - phi);

		error = sqrt(pow((pref(0,0) - p(0,0)),2) + (pow((pref(1,0) - p(1,0)),2)) + (pow((pref(2,0) - p(2,0)),2)) ); 
		phi = phi1;
		p= p1;

		c0 = cos(phi(0,0));
        	c1 = cos(phi(1,0));
        	c12 = cos(phi(1,0)+phi(3,0));
        	c123 = cos(phi(1,0)+phi(3,0)+phi(5,0));
		s0 = sin(phi(0,0));
        	s1 = sin(phi(1,0));
        	s12 = sin(phi(1,0)+phi(3,0));
        	s123 = sin(phi(1,0)+phi(3,0)+phi(5,0));

        	d1 = phi(2,0);
        	d2 = phi(4,0);

                phi0 = phi(0,0);
                phi11 = phi(1,0);
                phi2 = phi(3,0);
                phi3 = phi(5,0);

		j << -(d1*c1*s0)-(d2*c12*s0)-(l3*c123*s0) << -(d1*s1*c0)-(d2*s12*c0)-(l3*s123*c0) << c1*c0 << -(d2*s12*c0)-(l3*s123*c0) << c12*c0 << -l3*s123*c0 << endr
          	  << (d1*c1*c0)+(d2*c12*c0)+(l3*c123*c0) << -(d1*s1*s0)-(d2*s12*s0)-(l3*s123*s0) << c1*s0 << -(d2*s12*s0)-(l3*s123*s0) << c12*s0 << -l3*s123*s0 << endr
          	  << 0 << (d1*c1)+(d2*c12)+(l3*c123) << s1 << (d2*c12)+(l3*c123) << s12 << (l3*c123) << endr;
	}
  }
  
};
 
 BOOST_PYTHON_MODULE(MoveModuleb)
 {
   using namespace boost::python;
   
   class_<Movement>("pMovement")
       
   .def("GearToGear", &Movement::gearToGear)
   .def_readwrite("ResultW", &Movement::w1)  
   .def("Oscilar", &Movement::oscilar)
   .def_readwrite("ResultV", &Movement::v)  
   .def("brazo", &Movement::brazo)
   .def_readwrite("phi0", &Movement::phi0)  
   .def_readwrite("phi1", &Movement::phi11)  
    .def_readwrite("phi2", &Movement::phi2)  
    .def_readwrite("phi3", &Movement::phi3)  
    .def_readwrite("d1", &Movement::d1)
    .def_readwrite("d2", &Movement::d2)   
   ;
 }
 
 


/* Movement Library 

Esta libreria contiene funciones , las cuales se comunican con la consola Python de FreeCAD para mover componentes.

 Compilacion:
 g++ -g -shared -fPIC Movement.cpp -o MoveModule.so -I/usr/include/python2.7 -lpython2.7 -lboost_python-2.7

*/

#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <cmath>
#define pi 3.14159

class Movement
{
  public:

  double w1, v;
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
  
};
 
 BOOST_PYTHON_MODULE(MoveModule)
 {
   using namespace boost::python;
   
   class_<Movement>("pMovement")
       
   .def("GearToGear", &Movement::gearToGear)
   .def_readwrite("ResultW", &Movement::w1)  
   .def("Oscilar", &Movement::oscilar)
   .def_readwrite("ResultV", &Movement::v)  
   ;
 }
 
 

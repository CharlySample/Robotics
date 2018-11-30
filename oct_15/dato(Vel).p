set multiplot layout 2,2 title "vel(dato)"
set yrange[0:100]
set grid
set xrange[0:8]
set xlabel "rad/s"
set ylabel "dato"
set title 'Servo 1'
f(x) = 0.0702341*x**0+3.01968*x**1+5.10016*x**2-6.00479*x**3+3.50626*x**4-1.11228*x**5+0.195824*x**6-0.0179695*x**7+0.000670904*x**8
plot 'servo1.txt' using 2:1 with lp title 'Servo 1' linetype 7,f(x) with lp title 'polinomio' linetype 8
set title 'Servo 2'
set xlabel "rad/s"
set ylabel "dato"
set yrange[0:100]
set xrange[0:8]
f1(x) =  0.0701971*x**0+2.95862*x**1+5.00309*x**2-5.83549*x**3+3.38012*x**4-1.06371*x**5+0.185782*x**6-0.0169127*x**7+0.000626453*x**8
plot 'servo2.txt' u 2:1 with lp title 'Servo 2' linetype 7,f1(x) with lp title 'polinomio' linetype 8
set title 'Servo 3'
set xlabel "rad/s"
set ylabel "dato"
set yrange[0:100]
set xrange[0:8]
f2(x) = 0.0806085*x**0+2.40593*x**1+5.6996*x**2-6.4475*x**3+3.62637*x**4-1.10854*x**5+0.188052*x**6-0.0166264*x**7+0.000597989*x**8
plot 'servo3.txt' using 2:1 with lp title 'Servo 3' linetype 7,f2(x) with lp title 'polinomio' linetype 8
unset multiplot

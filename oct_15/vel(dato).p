set multiplot layout 2,2 title "vel(dato)"
set yrange[0:8]
set grid
set xrange[0:100]
set xlabel "dato"
set ylabel "rad/s"
set title 'Servo 1'
f(x) = 5.3340e-05+2.1475e-01*x-9.9040e-05*x**2-2.5995e-05*x**3
plot 'servo1.txt' using 1:2 with lp title 'Servo 1' linetype 7,f(x) with lp title 'polinomio' linetype 8
set title 'Servo 2'
set xlabel "dato"
set ylabel "rad/s"
set yrange[0:8]
set xrange[0:100]
f1(x) = -2.2017e-04+2.1870e-01*x-1.9559e-04*x**2-2.5174e-05*x**3
plot 'servo2.txt' u 1:2 with lp title 'Servo 2' linetype 7,f1(x) with lp title 'polinomio' linetype 8
set title 'Servo 3'
set xlabel "dato"
set ylabel "rad/s"
set yrange[0:8]
set xrange[0:100]
f2(x) = 1.1750e-04+2.3312e-01*x-4.5829e-04*x**2-2.4176e-05*x**3
plot 'servo3.txt' using 1:2 with lp title 'Servo 3' linetype 7,f2(x) with lp title 'polinomio' linetype 8
unset multiplot

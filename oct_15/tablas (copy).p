set multiplot layout 2,2 title "Vehiculo 2WD - referencia 25m 3*pi/4"
set yrange[0:30]
set xrange[0:50]
set xlabel "k"
set ylabel "m"
set title 'Desplazamiento'
plot 'tabla1.txt' using 1 with lp title 'desplazamiento' linetype 7,'tabla2.txt' using 1 with lp title 'desplazamiento' linetype 8
set title 'Angulo'
set xlabel "k"
set ylabel "rad"
set yrange[0:3]
set xrange[0:50]
plot 'tabla1.txt' u 2 with lp title 'Angulo' linetype 4,'tabla2.txt' using 2 with lp linetype 8
set title 'Posicion Cartesiana'
set xlabel "posicion x (m)"
set ylabel "posicion y (m)"
set yrange[0:20]
set xrange[-20:17]
plot 'tabla1.txt' using 3:4 with lp title 'posicion ' linetype 8,'tabla2.txt' using 3:4 with lp title 'posicion ' linetype 2
unset multiplot

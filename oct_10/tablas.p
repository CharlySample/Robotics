set multiplot layout 2,2 title "Vehiculo 2WD - referencia 25m 3*pi/4"
set yrange[0:30]
set xrange[0:65]
set xlabel "k"
set ylabel "m"
set title 'Desplazamiento'
plot 'tabla.txt' using 1 with lp title 'desplazamiento' linetype 7
set title 'Angulo'
set xlabel "k"
set ylabel "rad"
set yrange[0:3]
set xrange[0:65]
plot 'tabla.txt' u 2 with lp title 'Angulo' linetype 4
set title 'Posicion Cartesiana'
set xlabel "posicion x (m)"
set ylabel "posicion y (m)"
set yrange[0:20]
set xrange[-20:10]
plot 'tabla.txt' using 3:4 with lp title 'posicion ' linetype 8
unset multiplot

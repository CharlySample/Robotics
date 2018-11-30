set multiplot layout 2,2 title "Ejercicio Omnibot"
set grid
set yrange[0:4]
set xrange[0:7098]
set xlabel "k"
set ylabel "m"
set title 'Desplazamiento'
plot 'omnipro.txt' using 1 with lp title 'Desplazamiento' linetype 7
set title 'Angulo'
set xlabel "k"
set ylabel "rad"
set yrange[0:4]
set xrange[0:7098]
plot 'omnipro.txt' u 2 with lp title 'Angulo' linetype 7
set title 'Posicion Cartesiana'
set xlabel "posicion x (m)"
set ylabel "posicion y (m)"
set yrange[-10:10]
set xrange[-10:10]
plot 'omnipro.txt' using 3:4 with lp title 'Posicion' linetype 7
unset multiplot

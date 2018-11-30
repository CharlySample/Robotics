set multiplot layout 2,2 title "Omnibot tarea"
set grid
set yrange[0:2]
set xrange[0:4000]
set xlabel "k"
set ylabel "m/s"
set title 'Velocidad Tangencial'
plot 'omniprovel.txt' using 1 with lp title 'Velocidad Tangencial' linetype 7
set title 'Velocidad Angular'
set xlabel "k"
set ylabel "rad/s"
set yrange[0:1.5]
set xrange[0:4000]
plot 'omniprovel.txt' u 2 with lp title 'Velocidad Angular' linetype 7
set title 'Velocidades x y'
set xlabel "velocidad x (m/s)"
set ylabel "velocidad y (m/s)"
set yrange[0:3]
set xrange[0:3]
plot 'omniprovel.txt' using 3:4 with lp title 'Posicion' linetype 7
unset multiplot

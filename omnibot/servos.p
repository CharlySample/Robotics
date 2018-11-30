set multiplot layout 2,2 title "Servos Omnibot"
set grid
set yrange[5:6]
set xrange[0:10]
set xlabel "t(s)"
set ylabel "rad/s"
set title 'Servo1'
plot 'dato.txt' using 1 with lp title 'Servo 1' linetype 7
set title 'Servo 2'
set xlabel "t(s)"
set ylabel "rad/s"
set yrange[5:6]
set xrange[0:100]
plot 'dato.txt' u 2 with lp title 'Servo 2' linetype 8
set title 'Servo 3'
set xlabel 't(s)"
set ylabel 'rad/s'
set yrange[2:4]
set xrange[0:100]
plot 'dato.txt' using 3 with lp title 'Servo 3' linetype 9
unset multiplot

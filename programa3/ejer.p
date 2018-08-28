unset log
unset label
set xtic auto
set ytic auto
set title "Ejercicio_2"
set xlabel "x"
set ylabel "y"
set xrange [1:28]
set yrange [2:65]
set grid
set autoscale
f(x) = x**3 + 1
plot 'dat.txt' using 2:3 w l title 'linea' , f(x) w l title 'funcion'


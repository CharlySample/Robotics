unset log
unset label
set xtic auto
set ytic auto
set title "Tarea_1"
set xlabel "x"
set ylabel "y"
set xrange [-1.5:2]
set yrange [1:5]
set grid
set autoscale
f(x) = x**2 + 1
plot 'datos.txt' using 2:4 w l title 'linea' , f(x) w l title 'funcion'
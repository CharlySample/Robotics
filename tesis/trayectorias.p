set grid
set xrange [-40:40]
set yrange [-40:40]
set xlabel 'pos x (m)'
set ylabel 'pos y (m)'
set title 'Comparacion de trayectorias entre 4w2d y 4wd'
plot '4w2d1.txt' u 3:4 w lp linetype '2' title "4w2d Trayectoria 1",'4w2d2.txt' u 3:4 w lp linetype '2' title '4w2d Trayectoria 2', '4w2d3.txt' u 3:4 w lp linetype '2' title '4w2d Trayectoria 3', '4w2d4.txt' u 3:4 w lp linetype '2' title '4w2d Trayectoria 4','4wd1.txt' u 3:4 w lp linetype '8' title '4wd Trayectoria 1', '4wd2.txt' u 3:4 w lp linetype '8' title '4wd Trayectoria 2', '4wd3.txt' u 3:4 w lp linetype '8' title '4wd Trayectoria 3', '4wd4.txt' u 3:4 w lp linetype '8' title '4wd Trayectoria 4'
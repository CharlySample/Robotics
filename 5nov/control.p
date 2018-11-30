set grid
set xlabel 'pos x(mm)'
set ylabel 'pos y(mm)'
set zlabel 'pos z(mm)'
splot 'control.txt' u 1:2:3 w lp

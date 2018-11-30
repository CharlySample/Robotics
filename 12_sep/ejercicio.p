unset log
unset label
set xtic auto
set ytic auto
set title "Vt"
set xlabel "xp m/s"
set ylabel "yp m/s"
set zlabel "Vm,alpha"
set grid
set autoscale
#splot 'Vm.txt' using 1:2:3 with p title 'Vm' linetype 8, 'Vm.txt' using 1:2:4 with p title 'Valpha' linetype 2
splot 'test.txt' using 1:2:4 with p title 'sd' linetype 3



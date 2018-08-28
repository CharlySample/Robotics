#---------- ARREGLO DE SONARES ------------

define sonar sensor
(
	size [0.01 0.05 0.01]
	range [.5 3.5]
	fov 40
	samples 8
	color_rgba [ 0 1 1 1 ] 
)

define sonares ranger
(
	sonar( pose [ 0.075 0.130 0 85 ] )
 	sonar( pose [ 0.125 0.115 0 60 ] )
 	sonar( pose [ 0.150 0.080 0 35 ] )
 	sonar( pose [ 0.170 0.025 0 10 ] )
 	sonar( pose [ 0.170 -0.025 0 -10 ] )
 	sonar( pose [ 0.150 -0.080 0 -35 ] )
 	sonar( pose [ 0.125 -0.115 0 -60 ] )
 	sonar( pose [ 0.075 -0.130 0 -85 ] )
)

define caracteristicas position
(
	size [0.44 0.38 0.22]
	color "red"
	drive "diff"
	#gui_nose 1
	#way it points
	obstacle_return 1
	ranger_return 1
	mass 23.0
	localization "gps"
	localization_origin [0 0 0 0]
	#origin [-0.04 0 0 0]

)

define carlosbot caracteristicas
(
	block(
	points 8 #cantidad de puntos
    point[0] [-0.2 0.12] #las medidas debes de ser debjao de .0
    point[1] [-0.2 -0.12]
    point[2] [-0.12 -0.2555]
    point[3] [0.12 -0.2555]
    point[4] [0.2 -0.12]
    point[5] [0.2 0.12]
    point[6] [0.12 0.2555]
    point[7] [-0.12 0.2555]
    z [0 0.22] # esta es la elevacion 
	)
	sonares()
)


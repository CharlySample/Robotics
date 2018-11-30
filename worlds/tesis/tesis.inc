#---------- ARREGLO DE SONARES ------------

define sonar sensor
(
	size [0.01 0.05 0.01]
	range [0 15]
	fov 15
	samples 360
	color_rgba [ 0 1 1 0 ] 
)

define hokuyolaser ranger
(
    sensor(
  # laser-specific properties
  # factory settings for LMS200
  range [ 0.0  5.0 ]
  fov 180.0
  samples 270
  )
  # generic model properties
  color "red"
  size [ 0.07 0.07 0.05 ] # dimensions from LMS200 data sheet
)

define sonares ranger
(
	    sonar( pose [ 0.258 0.005 -0 8 ] ) # 1
        sonar( pose [ 0.238 0.010 -0 37 ] ) # 2 
        sonar( pose [ 0.128 0.020 -0 70 ] ) # 3
        sonar( pose [ -0.128 0.020 -0 110 ] ) # 4
        sonar( pose [ -0.238 0.010 -0 147 ] ) # 5
        sonar( pose [ -0.258 0.005 -0 172 ] ) # 6
        sonar( pose [ -0.238 -0.005 -0 -172 ] ) # 7
        sonar( pose [ -0.238 -0.010 -0 -147 ] ) # 8
        sonar( pose [ -0.128 -0.020 -0 -110 ] ) # 9
        sonar( pose [ 0.128 0.020 -0 -70 ] )# 10
        sonar( pose [ 0.238 -0.010 -0 -37 ] ) # 11
        sonar( pose [ 0.258 -0.005 -0 -8 ] ) # 12
)

define caracteristicas position
(
	size [0.7 0.45 0.35]
	color "red"
	drive "diff"
	#gui_nose 1
	#way it points
	obstacle_return 1
	ranger_return 1
    #hokuyolaser(pose [0.100 0 -0.02 0] alwayson 1)
    #hokuyolaser(pose [-0.100 0 -0.02 180] alwayson 1)
	mass 23.0
	localization "gps"
	localization_origin [0 0 0 0]
	origin [0 0 0 0]

)

define carlosbot caracteristicas
(
	sonares()
    #hokuyolaser()
    
  block( 
    points 16
    point[0] [ 0.225 0.000 ]
    point[1] [ 0.208 0.086 ]
    point[2] [ 0.159 0.159 ]
    point[3] [ 0.086 0.208 ]
    point[4] [ 0.000 0.225 ]
    point[5] [ -0.086 0.208 ]
    point[6] [ -0.159 0.159 ]
    point[7] [ -0.208 0.086 ]
    point[8] [ -0.225 0.000 ]
    point[9] [ -0.208 -0.086 ]
    point[10] [ -0.159 -0.159 ]
    point[11] [ -0.086 -0.208 ]
    point[12] [ -0.000 -0.225 ]
    point[13] [ 0.086 -0.208 ]
    point[14] [ 0.159 -0.159 ]
    point[15] [ 0.208 -0.086 ]
    z [0.2 1]
  )

  block( 
    points 16
    point[0] [ 0.155 0.000 ]
    point[1] [ 0.130 0.086 ]
    point[2] [ 0.119 0.159 ]
    point[3] [ 0.086 0.208 ]
    point[4] [ 0.000 0.225 ]
    point[5] [ -0.086 0.208 ]
    point[6] [ -0.119 0.159 ]
    point[7] [ -0.130 0.086 ]
    point[8] [ -0.155 0.000 ]
    point[9] [ -0.130 -0.086 ]
    point[10] [ -0.119 -0.159 ]
    point[11] [ -0.086 -0.208 ]
    point[12] [ -0.000 -0.225 ]
    point[13] [ 0.086 -0.208 ]
    point[14] [ 0.119 -0.159 ]
    point[15] [ 0.130 -0.086 ]
    z [2 1]
  )

  block(
    points 5
    point[0] [ 0.060 0.227 ]
    point[1] [ 0.180 0.227 ]
    point[2] [ 0.180 0.287 ]
    point[3] [ 0.060 0.287 ]
    point[4] [ 0.060 0.207 ]
    z [0 0.53]
       )

     block(
    points 5
    point[0] [ 0.060 -0.227 ]
    point[1] [ 0.180 -0.227 ]
    point[2] [ 0.180 -0.287 ]
    point[3] [ 0.060 -0.287 ]
    point[4] [ 0.060 -0.207 ]
    z [0 0.53]
       )

   block(
    points 5
    point[0] [ -0.060 -0.227 ]
    point[1] [ -0.180 -0.227 ]
    point[2] [ -0.180 -0.287 ]
    point[3] [ -0.060 -0.287 ]
    point[4] [ -0.060 -0.207 ]
    z [0 0.53]
       )

  block(
    points 5
    point[0] [ -0.060 0.227 ]
    point[1] [ -0.180 0.227 ]
    point[2] [ -0.180 0.287 ]
    point[3] [ -0.060 0.287 ]
    point[4] [ -0.060 0.207 ]
    z [0 0.53]
       )
)

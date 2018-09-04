define sonar sensor
(
  size [0.01 0.05 0.01]
  range [.5 3.5]
  fov 40
  samples 8
  color_rgba [ 0 1 1 1 ] 
)


### AMIGOBOT ####

# The AmigoBot sonar array
define amigo_sonar ranger
(
  sonar ( pose [ 0.073 0.105 0 90 ] )
  sonar ( pose [ 0.130 0.078 0 41 ] )
  sonar ( pose [ 0.154 0.030 0 15 ] )
  sonar ( pose [ 0.154 -0.030 0 -15 ] )
  sonar ( pose [ 0.130 -0.078 0 -41 ]	)
  sonar ( pose [ 0.073 -0.105 0 -90 ] )
	sonar ( pose [ -0.146 -0.060 0 -145 ] )
	sonar ( pose [ -0.146 0.060 0 145 ] )
)

define amigobot position
(
  size [0.330 0.280 0.25]
  color "red"
  drive "diff"
  #gui_nose 1
  #way it points
  obstacle_return 1
  ranger_return 1
  mass 23.0
  localization "gps"
  localization_origin [0 0 0 0]
  amigo_sonar( pose [0 0 -0.02 0 ] )
)
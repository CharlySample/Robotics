### AMIGOBOT ####

# The AmigoBot sonar array

#define sonar sensor
#(
#  size [0.01 0.05 0.01]
#  range [.5 2]
#  fov 5
#  samples 360
#  color_rgba [ 0 1 1 1 ]
#)


#define amigo_sonar ranger
#(
#  sonar ( pose [ 0.153 0.105 0 90 ] )
#  sonar ( pose [ -0.0 0.105 0 90 ] )
#  sonar ( pose [ -0.153 0.105 0 90 ] )
#)

define amigobot position
(
  size [0.330 0.280 0.25]
  color "red"
  drive "diff"
  #gui_nose 1
  #way it points
  obstacle_return 1
  #ranger( alwayson 1)
  #ranger_return 1
  #amigo_sonar(pose [0 0 -0.02 0 ] alwayson 1)
  mass 23.0
  localization "gps"
  localization_origin [0 0 0 0]

)

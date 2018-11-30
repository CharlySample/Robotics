### AMIGOBOT ####

# The AmigoBot sonar array

define hokuyolaser ranger
(
	sensor(
  # laser-specific properties
  # factory settings for LMS200
  range [ 0.0  5.0 ]
  fov 270.0
  samples 270
  )
  # generic model properties
  color "blue"
  size [ 0.07 0.07 0.05 ] # dimensions from LMS200 data sheet
)

define amigobot position
(
  size [0.330 0.280 0.25]
  color "red"
  drive "diff"
  #gui_nose 1
  #way it points
  obstacle_return 1
  #ranger( alwayson 1)
  ranger_return 1
  hokuyolaser(pose [0 0 -0.02 0 ] alwayson 1)
  mass 23.0
  localization "gps"
  localization_origin [0 0 0 0]

)

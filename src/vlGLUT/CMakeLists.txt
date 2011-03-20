################################################################################
# VLGLUT Library
################################################################################

project(VLGLUT)

# Gather VLGLUT source files
file(GLOB VLGLUT_SRC "*.cpp")
file(GLOB VLGLUT_INC "*.hpp")

add_library(VLGLUT ${VL_SHARED_OR_STATIC} ${VLGLUT_SRC} ${VLGLUT_INC})
VL_DEFAULT_TARGET_PROPERTIES(VLGLUT)

target_link_libraries(VLGLUT VLCore VLGraphics ${GLUT_LIBRARIES})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLGLUT)

# VLGLUT headers
install(FILES ${VLGLUT_INC} DESTINATION "include/vlGLUT")

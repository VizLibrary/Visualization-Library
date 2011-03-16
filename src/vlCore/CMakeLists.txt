################################################################################
# VLCore Library
################################################################################

project(VLCORE)

# Handle compile-time plugins for VLCore
add_subdirectory("plugins")

# Gather VLCore source files
file(GLOB VLCORE_SRC "*.cpp")
file(GLOB VLCORE_INC "*.hpp")

# Generate the 'vlCore/version.hpp' file
configure_file("version.hpp.in" "version.hpp")
list(APPEND VLCORE_INC "${CMAKE_CURRENT_BINARY_DIR}/version.hpp")

# VLCore must embed and export GLEW
set(GLEW_DIR "${3RDPARTY_DIR}/glew")
set(GLEW_SRC "${GLEW_DIR}/glew.c")
add_definitions(-DGLEW_BUILD)

# Handle extras added by plugins
VL_PROJECT_GET(VLCORE _SOURCES _DEFINITIONS _INCLUDE_DIRS _LIBS)
add_definitions(${_DEFINITIONS})
include_directories(${_INCLUDE_DIRS})

add_library(VLCore ${VL_SHARED_OR_STATIC} ${VLCORE_SRC} ${VLCORE_INC} ${GLEW_SRC} ${_SOURCES})
VL_DEFAULT_TARGET_PROPERTIES(VLCore)

# Because of GLEW, VLCore must also link with OpenGL
target_link_libraries(VLCore ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${_LIBS})

################################################################################
# Source Groups
################################################################################

source_group("glew" FILES ${GLEW_SRC})
source_group("plugins" FILES ${_SOURCES})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLCore)

# VLCore headers
install(FILES ${VLCORE_INC} DESTINATION "include/vlCore")

# GLEW headers
install(DIRECTORY "${GLEW_DIR}/GL" DESTINATION "include")

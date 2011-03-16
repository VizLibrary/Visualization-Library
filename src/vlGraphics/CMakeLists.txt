################################################################################
# VLGraphics Library
################################################################################

project(VLGRAPHICS)

# Handle compile-time plugins for VLGraphics
add_subdirectory("plugins")

# Gather VLGraphics source files
file(GLOB VLGRAPHICS_SRC "*.cpp")
file(GLOB VLGRAPHICS_INC "*.hpp")

# Handle extras added by plugins
VL_PROJECT_GET(VLGRAPHICS _SOURCES _DEFINITIONS _INCLUDE_DIRS _LIBS)
add_definitions(${_DEFINITIONS})
include_directories(${_INCLUDE_DIRS})

add_library(VLGraphics ${VL_SHARED_OR_STATIC} ${VLGRAPHICS_SRC} ${VLGRAPHICS_INC} ${_SOURCES})
VL_DEFAULT_TARGET_PROPERTIES(VLGraphics)

target_link_libraries(VLGraphics VLCore ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${_LIBS})

################################################################################
# Source Groups
################################################################################

source_group("plugins" FILES ${_SOURCES})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLGraphics)

# VLGraphics headers
install(FILES ${VLGRAPHICS_INC} DESTINATION "include/vlGraphics")

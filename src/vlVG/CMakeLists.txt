################################################################################
# VLVG Library
################################################################################

project(VLVG)

# Gather VLVG source files
file(GLOB VLVG_SRC "*.cpp")
file(GLOB VLVG_INC "*.hpp")

add_library(VLVG ${VL_SHARED_OR_STATIC} ${VLVG_SRC} ${VLVG_INC})
VL_DEFAULT_TARGET_PROPERTIES(VLVG)

target_link_libraries(VLVG VLCore VLGraphics)

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLVG)

# VLVG headers
install(FILES ${VLVG_INC} DESTINATION "include/vlVG")

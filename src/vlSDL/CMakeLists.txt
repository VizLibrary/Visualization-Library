################################################################################
# VLSDL Library
################################################################################

project(VLSDL)

# Gather VLSDL source files
file(GLOB VLSDL_SRC "*.cpp")
file(GLOB VLSDL_INC "*.hpp")

add_library(VLSDL ${VL_SHARED_OR_STATIC} ${VLSDL_SRC} ${VLSDL_INC})
VL_DEFAULT_TARGET_PROPERTIES(VLSDL)

target_link_libraries(VLSDL VLCore VLGraphics ${SDL_LIBRARY})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLSDL)

# VLSDL headers
install(FILES ${VLSDL_INC} DESTINATION "include/vlSDL")

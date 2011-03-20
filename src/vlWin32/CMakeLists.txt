################################################################################
# VLWin32 Library
################################################################################

project(VLWin32)

# Gather VLWin32 source files
file(GLOB VLWin32_SRC "*.cpp")
file(GLOB VLWin32_INC "*.hpp")

add_library(VLWin32 ${VL_SHARED_OR_STATIC} ${VLWin32_SRC} ${VLWin32_INC})
VL_DEFAULT_TARGET_PROPERTIES(VLWin32)

target_link_libraries(VLWin32 VLCore VLGraphics)

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLWin32)

# VLWin32 headers
install(FILES ${VLWin32_INC} DESTINATION "include/vlWin32")

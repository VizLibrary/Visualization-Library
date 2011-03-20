################################################################################
# VLQt4 Library
################################################################################

project(VLQt4)

# Gather VLQt4 source files
file(GLOB VLQt4_SRC "*.cpp")
file(GLOB VLQt4_INC "*.hpp")

QT4_WRAP_CPP(MOC_SOURCES Qt4Widget.hpp)

add_library(VLQt4 ${VL_SHARED_OR_STATIC} ${VLQt4_SRC} ${VLQt4_INC} ${MOC_SOURCES})
VL_DEFAULT_TARGET_PROPERTIES(VLQt4)

target_link_libraries(VLQt4 VLCore VLGraphics ${QT_LIBRARIES})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLQt4)

# VLQt4 headers
install(FILES ${VLQt4_INC} DESTINATION "include/VLQt4")

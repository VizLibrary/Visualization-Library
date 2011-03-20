################################################################################
# VLMFC Library
################################################################################

project(VLMFC)

# Gather VLMFC source files
file(GLOB VLMFC_SRC "*.cpp")
file(GLOB VLMFC_INC "*.hpp")

add_definitions(-D_AFXDLL)
add_library(VLMFC ${VL_SHARED_OR_STATIC} ${VLMFC_SRC} ${VLMFC_INC})
VL_DEFAULT_TARGET_PROPERTIES(VLMFC)

target_link_libraries(VLMFC VLCore VLGraphics VLWin32 ${wxWidgets_LIBRARIES})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLMFC)

# VLMolecule headers
install(FILES ${VLMFC_INC} DESTINATION "include/vlMFC")

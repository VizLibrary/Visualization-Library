################################################################################
# Doxygen Documentation
################################################################################

project(DOCS)

file(GLOB VL_DOX_FILES "dox/*.dox")

VL_GENERATE_DOXYGEN(doxygen "Doxyfile" SOURCES ${VL_DOX_FILES})

source_group("dox" FILES ${VL_DOX_FILES})

option(VL_INSTALL_DOCS "Install API Documentation (drastically increases package size)" OFF)
if(VL_INSTALL_DOCS)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/VL_SDK_DOCS-HTML/" DESTINATION "docs/html")
	install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/VL_SDK_DOCS-HTML/" DESTINATION "docs/html")
endif()

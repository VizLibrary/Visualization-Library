project(EXAMPLES)

################################################################################
# Compile all Applets
################################################################################

add_subdirectory("applets")

################################################################################
# Build the Example/Test executables
################################################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Common libraries
set(VL_LIBS_EXAMPLE VLCore VLGraphics ${OPENGL_LIBRARIES})
set(VL_LIBS_TESTS VLCore VLGraphics VLMolecule VLVG VLVolume ${OPENGL_LIBRARIES})

if(GUI_GLUT_EXAMPLES)
	include_directories(${GLUT_INCLUDE_DIR})

	# Example
	add_executable(GLUT_example GLUT_example.cpp Applets/App_RotatingCube.hpp)
	target_link_libraries(GLUT_example VLGLUT ${GLUT_LIBRARIES} ${VL_LIBS_EXAMPLE})
	VL_INSTALL_TARGET(GLUT_example)

	# Tests
	add_executable(GLUT_tests GLUT_tests.cpp)
	target_link_libraries(GLUT_tests VLApplets VLGLUT ${GLUT_LIBRARIES} ${VL_LIBS_TESTS})
	VL_INSTALL_TARGET(GLUT_tests)
endif()

if(GUI_QT4_EXAMPLES)
	include(${QT_USE_FILE})

	# Example
	add_executable(Qt4_example WIN32 Qt4_example.cpp Applets/App_RotatingCube.hpp)
	target_link_libraries(Qt4_example VLQt4 ${QT_LIBRARIES} ${VL_LIBS_EXAMPLE})
	VL_INSTALL_TARGET(Qt4_example)

	# Tests
	add_executable(Qt4_tests WIN32 Qt4_tests.cpp )
	target_link_libraries(Qt4_tests VLApplets VLQt4 ${QT_LIBRARIES} ${VL_LIBS_TESTS})
	VL_INSTALL_TARGET(Qt4_tests)
endif()

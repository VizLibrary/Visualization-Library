project(EXAMPLES)

################################################################################
# Compile all Applets
################################################################################

add_subdirectory("Applets")

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

if (GUI_WIN32_EXAMPLES)
	# Direct
	add_executable(Win32_direct WIN32 Win32_direct.cpp)
	target_link_libraries(Win32_direct VLWin32 ${VL_LIBS_EXAMPLE})
	VL_INSTALL_TARGET(Win32_direct)

	# Example
	add_executable(Win32_example WIN32 Win32_example.cpp Applets/App_RotatingCube.hpp)
	target_link_libraries(Win32_example VLWin32 ${VL_LIBS_EXAMPLE})
	VL_INSTALL_TARGET(Win32_example)

	# Tests
	add_executable(Win32_tests WIN32 Win32_tests.cpp )
	target_link_libraries(Win32_tests VLApplets VLWin32 ${VL_LIBS_TESTS})
	VL_INSTALL_TARGET(Win32_tests)
endif()

if (GUI_MFC_EXAMPLES)
	# Example
	add_executable(MFC_example WIN32 MFC_example/MFC_example.cpp MFC_example/StdAfx.cpp )
	target_link_libraries(MFC_example VLApplets VLMFC ${VL_LIBS_TESTS})
	set_target_properties(MFC_example PROPERTIES COMPILE_FLAGS -D_AFXDLL)
	set_target_properties(MFC_example PROPERTIES LINK_FLAGS /ENTRY:wWinMainCRTStartup)  
	VL_INSTALL_TARGET(MFC_example)
	
	# MDI Example
	file(GLOB MFC_MDI_SRC "MFC_MDI_example/*.cpp")
	file(GLOB MFC_MDI_INC "MFC_MDI_example/*.hpp")
	add_executable(MFC_MDI_example WIN32 ${MFC_MDI_SRC} ${MFC_MDI_INC})
	target_link_libraries(MFC_MDI_example VLApplets VLMFC ${VL_LIBS_TESTS})
	set_target_properties(MFC_MDI_example PROPERTIES COMPILE_FLAGS -D_AFXDLL)
	set_target_properties(MFC_MDI_example PROPERTIES LINK_FLAGS /ENTRY:wWinMainCRTStartup)  
	VL_INSTALL_TARGET(MFC_MDI_example)

	# Tests
	add_executable(MFC_tests WIN32 MFC_tests/MFC_tests.cpp MFC_tests/StdAfx.cpp )
	target_link_libraries(MFC_tests VLApplets VLMFC ${VL_LIBS_TESTS})
	set_target_properties(MFC_tests PROPERTIES COMPILE_FLAGS -D_AFXDLL)
	set_target_properties(MFC_tests PROPERTIES LINK_FLAGS /ENTRY:wWinMainCRTStartup)
	VL_INSTALL_TARGET(MFC_tests)
endif()

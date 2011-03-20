################################################################################
# Core Modules
################################################################################

# Graphics support can be toggled
option(VL_MODULE_GRAPHICS "Enable VL Graphics Library" ON)
if(VL_MODULE_GRAPHICS)
	add_definitions(-DVL_MODULE_GRAPHICS)
endif()

# VLCore
add_subdirectory("vlCore")

# VLGraphics
if(VL_MODULE_GRAPHICS)
	add_subdirectory("vlGraphics")
else()
	unset(VL_IO_3D_MD2 CACHE)
	unset(VL_IO_3D_PLY CACHE)
	unset(VL_IO_3D_STL CACHE)
	unset(VL_IO_3D_AC3D CACHE)
	unset(VL_IO_3D_OBJ CACHE)
	unset(VL_IO_3D_3DS CACHE)
endif()

# VLVG
cmake_dependent_option(VL_MODULE_VG "Enable VL Vector Graphics Library" ON "VL_MODULE_GRAPHICS" OFF)
if(VL_MODULE_VG)
	add_subdirectory("vlVG")
endif()

# VLMolecule
cmake_dependent_option(VL_MODULE_MOLECULE "Enable VL Molecule Library" ON "VL_MODULE_GRAPHICS" OFF)
if(VL_MODULE_MOLECULE)
	add_subdirectory("vlMolecule")
endif()

# VLVolume
cmake_dependent_option(VL_MODULE_VOLUME "Enable VL Volume Library" ON "VL_MODULE_GRAPHICS" OFF)
if(VL_MODULE_VOLUME)
	add_subdirectory("vlVolume")
endif()

################################################################################
# GUI Modules (automatically enabled when their requirements are met)
################################################################################

# GLUT
option(GUI_GLUT_SUPPORT "Build GLUT support" OFF)
if(GUI_GLUT_SUPPORT)
	set(GLUT_ROOT_PATH "${3RDPARTY_DIR}")
	find_package(GLUT REQUIRED)
	add_subdirectory("vlGLUT")
endif()

# Qt4
option(GUI_QT4_SUPPORT "Build Qt4 support" OFF)
if(GUI_QT4_SUPPORT)
	find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL QtMain REQUIRED)
	include("${QT_USE_FILE}")
	add_subdirectory("vlQt4")
endif()

# Win32 & MFC
if(MSVC)
	option(GUI_WIN32_SUPPORT "Build Win32 support" ON)
	option(GUI_MFC_SUPPORT "Build MFC support" OFF)
endif()

if(MINGW)
	option(GUI_WIN32_SUPPORT "Build Win32 support" ON)
endif()

if(GUI_MFC_SUPPORT)
  add_subdirectory("vlMFC")
endif()

if(GUI_WIN32_SUPPORT)
	add_subdirectory("vlWin32")
endif()

# SDL
option(GUI_SDL_SUPPORT "Build SDL support" OFF)

if(GUI_SDL_SUPPORT)
	find_package(SDL REQUIRED)
	add_subdirectory("vlSDL")
endif()

# wxWidgets
option(GUI_WXWIDGETS_SUPPORT "Build wxWidgets support" OFF)
if(GUI_WXWIDGETS_SUPPORT)
	find_package(wxWidgets COMPONENTS gl core base REQUIRED)
	if (wxWidgets_FOUND)
		add_subdirectory("vlWX")
	endif()
endif()

# Cocoa
#if(APPLE)
#	option(GUI_COCOA_SUPPORT "Build Cocoa support" ON)
#endif()
#if(GUI_COCOA_SUPPORT)
#	add_subdirectory("vlCocoa")
#endif()

################################################################################
# Examples
################################################################################

cmake_dependent_option(GUI_GLUT_EXAMPLES "Build GLUT examples" ON "GUI_GLUT_SUPPORT" OFF)
cmake_dependent_option(GUI_QT4_EXAMPLES "Build Qt4 examples" ON "GUI_QT4_SUPPORT" OFF)
cmake_dependent_option(GUI_MFC_EXAMPLES "Build MFC examples" ON "GUI_MFC_SUPPORT" OFF)
cmake_dependent_option(GUI_WIN32_EXAMPLES "Build win32 examples" ON "GUI_WIN32_SUPPORT" OFF)
cmake_dependent_option(GUI_SDL_EXAMPLES "Build SDL examples" ON "GUI_SDL_SUPPORT" OFF)
cmake_dependent_option(GUI_WXWIDGETS_EXAMPLES "Build wxWidgets examples" ON "GUI_WXWIDGETS_SUPPORT" OFF)
#cmake_dependent_option(GUI_COCOA_EXAMPLES "Build Cocoa examples" ON "GUI_COCOA_SUPPORT" OFF)

add_subdirectory("examples")

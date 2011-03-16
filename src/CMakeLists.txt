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
set(GLUT_ROOT_PATH "${3RDPARTY_DIR}")
find_package(GLUT)
option(GUI_GLUT_SUPPORT "Build GLUT support" ${GLUT_FOUND})
if(GUI_GLUT_SUPPORT)
	add_subdirectory("vlGLUT")
endif()

# Qt4
find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL QtMain)
option(GUI_QT4_SUPPORT "Build Qt4 support" ${QT_FOUND})
if(GUI_QT4_SUPPORT)
	include("${QT_USE_FILE}")
	add_subdirectory("vlQt4")
endif()

################################################################################
# Examples
################################################################################

cmake_dependent_option(GUI_GLUT_EXAMPLES "Build GLUT examples" ON "GUI_GLUT_SUPPORT" OFF)
cmake_dependent_option(GUI_QT4_EXAMPLES "Build Qt4 examples" ON "GUI_QT4_SUPPORT" OFF)

add_subdirectory("examples")


################################################################################
# DISABLED - PENDING MODULES
################################################################################

IF( FALSE )

if(VL_MODULE_GRAPHICS)
	if(MSVC)
	  option(GUI_WIN32_SUPPORT "Build Win32 support" ON)
	  option(GUI_MFC_SUPPORT "Build MFC support" OFF)
	endif()
	if(MINGW)
	  option(GUI_WIN32_SUPPORT "Build Win32 support" ON)
	endif()
	option(GUI_SDL_SUPPORT "Build SDL support" OFF)
	option(GUI_WXWIDGETS_SUPPORT "Build wxWidgets support" OFF)
	#if(APPLE)
	#  option(GUI_COCOA_SUPPORT "Build Cocoa support" ON)
	#endif()
else()
	unset(GUI_WIN32_SUPPORT CACHE)
	unset(GUI_MFC_SUPPORT CACHE)
	unset(GUI_SDL_SUPPORT CACHE)
	unset(GUI_GLUT_SUPPORT CACHE)
	unset(GUI_QT4_SUPPORT CACHE)
	unset(GUI_WXWIDGETS_SUPPORT CACHE)
	unset(GUI_COCOA_SUPPORT CACHE)

	unset(GUI_WIN32_EXAMPLES CACHE)
	unset(GUI_MFC_EXAMPLES CACHE)
	unset(GUI_SDL_EXAMPLES CACHE)
	unset(GUI_GLUT_EXAMPLES CACHE)
	unset(GUI_QT4_EXAMPLES CACHE)
	unset(GUI_WXWIDGETS_EXAMPLES CACHE)
	unset(GUI_COCOA_EXAMPLES CACHE)
endif()

if(GUI_MFC_SUPPORT)
  option(GUI_MFC_EXAMPLES "Build MFC examples" ON)
  add_subdirectory("src/vlMFC")
endif()

if(GUI_WIN32_SUPPORT)
  option(GUI_WIN32_EXAMPLES "Build win32 examples" ON)
  add_subdirectory("src/vlWin32")
endif()

if(GUI_SDL_SUPPORT)
  option(GUI_SDL_EXAMPLES "Build SDL examples" ON)
  if(MSVC)
    # Visual Studio
    set(SDL_INCLUDE_DIR  "${VisualizationLibrarySDK_SOURCE_DIR}/3rdparty/include/SDL"    CACHE PATH "Location of the SDL.h include file")
    set(SDLMAIN_LIBRARY  "${VisualizationLibrarySDK_SOURCE_DIR}/3rdparty/lib/SDLmain.lib" CACHE FILEPATH "SDLmain library path")
    set(SDL_LIBRARY      "${VisualizationLibrarySDK_SOURCE_DIR}/3rdparty/lib/SDL.lib"    CACHE FILEPATH "SDL library path")
  else()
    if(MINGW)
      # MinGW
      set(SDL_INCLUDE_DIR "C:/msys/1.0/local/include/SDL"  CACHE PATH "Location of the SDL.h include file")
      set(SDLMAIN_LIBRARY "C:/msys/1.0/local/lib/libSDLmain.a" CACHE FILEPATH "SDL library path")
      set(SDL_LIBRARY     "C:/msys/1.0/local/lib/libSDL.a" CACHE FILEPATH "SDL library path")
    else()
      # Linux / Mac
      find_package(SDL REQUIRED)
    endif()
  endif()
  add_subdirectory("src/vlSDL")
else()
  unset(SDL_INCLUDE_DIR CACHE)
  unset(SDLMAIN_LIBRARY CACHE)
  unset(SDL_LIBRARY CACHE)
endif()

if(GUI_WXWIDGETS_SUPPORT)
  option(GUI_WXWIDGETS_EXAMPLES "Build wxWidgets examples" OFF)
  set(WXWIDGETS_INCLUDE_DIR "FILLME" CACHE PATH "wxWidgets include directories")
  add_subdirectory("src/vlWX")
else()
  unset(WXWIDGETS_INCLUDE_DIR CACHE)
endif()

if(GUI_WXWIDGETS_EXAMPLES)
  set(WXWIDGETS_LIBRARY_DIR "FILLME" CACHE PATH "wxWidgets libraries path")
  set(WXWIDGETS_LIBRARIES   "FILLME" CACHE STRING "wxWidgets core and base libraries (space separated)")
else()
  unset(WXWIDGETS_LIBRARY_DIR CACHE)
  unset(WXWIDGETS_LIBRARIES CACHE)
endif()

#if(GUI_COCOA_SUPPORT)
#  option(GUI_COCOA_EXAMPLES "Build Cocoa examples" ON)
#  add_subdirectory("src/vlCocoa")
#endif()

ENDIF(FALSE)

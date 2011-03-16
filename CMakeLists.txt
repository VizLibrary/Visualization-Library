######################################################################################
#                                                                                    #
#  Visualization Library                                                             #
#  http://www.visualizationlibrary.com                                               #
#                                                                                    #
#  Copyright (c) 2005-2010, Michele Bosi                                             #
#  All rights reserved.                                                              #
#                                                                                    #
#  Redistribution and use in source and binary forms, with or without modification,  #
#  are permitted provided that the following conditions are met:                     #
#                                                                                    #
#  - Redistributions of source code must retain the above copyright notice, this     #
#  list of conditions and the following disclaimer.                                  #
#                                                                                    #
#  - Redistributions in binary form must reproduce the above copyright notice, this  #
#  list of conditions and the following disclaimer in the documentation and/or       #
#  other materials provided with the distribution.                                   #
#                                                                                    #
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND   #
#  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED     #
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE            #
#  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR  #
#  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    #
#  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      #
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON    #
#  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT           #
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS     #
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                      #
#                                                                                    #
######################################################################################

cmake_minimum_required(VERSION 2.6)

################################################################################
# Global VL Settings
################################################################################

# Current Version
set(VLVERSION_MAJOR "2011")
set(VLVERSION_MINOR "02")
set(VLVERSION_PATCH "1133")
set(VLVERSION "${VLVERSION_MAJOR}.${VLVERSION_MINOR}")

# Common Dirs
set(VL_DATA_DIR "${CMAKE_SOURCE_DIR}/data")
set(3RDPARTY_DIR "${CMAKE_SOURCE_DIR}/src/3rdparty")

################################################################################
# Initialization
################################################################################

project(Visualization_Library_SDK-${VLVERSION_MAJOR}.${VLVERSION_MINOR})

# Add our dir to the CMake modules path and include our InternalMacros file
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )
include( InternalMacros )

################################################################################
# Global Build Settings
################################################################################

# Dynamic vs Static Linking
option(VL_DYNAMIC_LINKING "Set to ON to build VL for dynamic linking, or OFF for static." ON)
if(VL_DYNAMIC_LINKING)
	add_definitions(-DVL_DYNAMIC_LINKING)
	set(VL_SHARED_OR_STATIC "SHARED")
else()
	add_definitions(-DVL_STATIC_LINKING)
	set(VL_SHARED_OR_STATIC "STATIC")
endif()

# Debug postfix for all libraries.
set(CMAKE_DEBUG_POSTFIX "-d")

# Default output locations for the various target types.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")

# Shared include paths for all subprojects
include_directories( "src" "${CMAKE_BINARY_DIR}/src" "${3RDPARTY_DIR}/glew" )

# High Warning Level
if(MSVC)
	set(CMAKE_CXX_FLAGS "/W4 /EHsc")
else()
	set(CMAKE_CXX_FLAGS "-W -Wall") # see also: -W -Wall -Wwrite-strings -Wcast-qual -Wconversion -Wshadow
endif()

if(WIN32)
	add_definitions(-DUNICODE)
endif()

if(MSVC)
	set(WINVER "0x0600" CACHE STRING "WINVER version (see MSDN documentation)")
	add_definitions(-DWINVER=${WINVER})
	add_definitions(-D_WIN32_WINNT=${WINVER})
endif()

# Required Dependencies
find_package(OpenGL REQUIRED)

################################################################################
# Packaging
################################################################################

set(CPACK_PACKAGE_NAME					"${CMAKE_PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION_MAJOR			"${VLVERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR			"${VLVERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH			"${VLVERSION_PATCH}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY	"A lightweight C++ OpenGL middleware for 2D and 3D graphics.")

if(WIN32)
	set(CPACK_GENERATOR "ZIP")
else()
	set(CPACK_GENERATOR "TBZ2")
endif()

include( CPack )

################################################################################
# Subdirectories
################################################################################

add_subdirectory("docs")
add_subdirectory("src")

################################################################################
# Install Rules
################################################################################

install(FILES "LICENSE.TXT" "README.TXT" DESTINATION ".")
install(FILES "cmake/FindVL.cmake" DESTINATION "cmake")

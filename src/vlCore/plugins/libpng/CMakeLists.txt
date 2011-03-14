################################################################################
# PNG Library
################################################################################

set(PNG_DIR "${3RDPARTY_DIR}/libpng")

if(UNIX AND VL_DYNAMIC_LINKING)
    add_definitions("-fPIC")
endif()

add_definitions(-DPNG_NO_MMX_CODE -D_CRT_SECURE_NO_WARNINGS)

add_library(PNG STATIC
	"${PNG_DIR}/png.c"
	"${PNG_DIR}/pngerror.c"
	"${PNG_DIR}/pngget.c"
	"${PNG_DIR}/pngmem.c"
	"${PNG_DIR}/pngpread.c"
	"${PNG_DIR}/pngread.c"
	"${PNG_DIR}/pngrio.c"
	"${PNG_DIR}/pngrtran.c"
	"${PNG_DIR}/pngrutil.c"
	"${PNG_DIR}/pngset.c"
	"${PNG_DIR}/pngtrans.c"
	"${PNG_DIR}/pngwio.c"
	"${PNG_DIR}/pngwrite.c"
	"${PNG_DIR}/pngwtran.c"
	"${PNG_DIR}/pngwutil.c"
)

if(NOT VL_DYNAMIC_LINKING)
	VL_INSTALL_TARGET(PNG)
endif()

VL_PROJECT_ADD(VLCORE INCLUDE_DIRECTORIES "${PNG_DIR}" LINK_LIBRARIES PNG)

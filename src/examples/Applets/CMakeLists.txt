PROJECT(VLAPPLETS)

# Gather VLApplets source files
file(GLOB VLAPPLETS_SRC "*.cpp" "App_BlindTests/*.cpp")
file(GLOB VLAPPLETS_INC "*.hpp" "App_BlindTests/*.hpp")

add_library(VLApplets STATIC ${VLAPPLETS_INC} ${VLAPPLETS_SRC})
VL_DEFAULT_TARGET_PROPERTIES(VLApplets)

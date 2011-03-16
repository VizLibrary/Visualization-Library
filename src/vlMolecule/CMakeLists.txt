################################################################################
# VLMolecule Library
################################################################################

project(VLMOLECULE)

# Gather VLMolecule source files
file(GLOB VLMOLECULE_SRC "*.cpp")
file(GLOB VLMOLECULE_INC "*.hpp")

add_library(VLMolecule ${VL_SHARED_OR_STATIC} ${VLMOLECULE_SRC} ${VLMOLECULE_INC})
VL_DEFAULT_TARGET_PROPERTIES(VLMolecule)

target_link_libraries(VLMolecule VLCore VLGraphics ${OPENGL_glu_LIBRARY})

################################################################################
# Install Rules
################################################################################

VL_INSTALL_TARGET(VLMolecule)

# VLMolecule headers
install(FILES ${VLMOLECULE_INC} DESTINATION "include/vlMolecule")

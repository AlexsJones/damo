set(SOURCE ${SOURCE}
${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
PARENT_SCOPE)

set(HEADERS
${HEADERS}
${CMAKE_CURRENT_SOURCE_DIR}/engine.hpp
${CMAKE_CURRENT_SOURCE_DIR}/engine_constraints.hpp
PARENT_SCOPE)

set(LINKER_LIBRARIES
  ${LINKER_LIBRARIES}
  PARENT_SCOPE)

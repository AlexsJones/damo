set(SOURCE ${SOURCE}
${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
PARENT_SCOPE)

#set(HEADERS
#${HEADERS}
#${CMAKE_CURRENT_SOURCE_DIR}/wpmessage.pb-c.h
#PARENT_SCOPE)

set(LINKER_LIBRARIES
  ${LINKER_LIBRARIES}
  PARENT_SCOPE)

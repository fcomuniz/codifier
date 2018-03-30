file(GLOB_RECURSE SRCS *.cpp)
#list(REMOVE_ITEM SRCS ${UNIT_TEST_EXEC} ${TEST_SRCS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(NOT ${SRCS})
	add_library(structures ${SRCS})
endif()

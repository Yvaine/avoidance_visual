PROJECT(avoidance_visual)
cmake_minimum_required(VERSION 2.8)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

IF(WIN32)
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include D:/soft/opencv/build/include)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib D:/soft/opencv/build/x64/vc12/lib)
ELSE(WIN32)
	SET(CMAKE_CXX_COMPILE "g++")
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)
ENDIF(WIN32)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src)
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/test)


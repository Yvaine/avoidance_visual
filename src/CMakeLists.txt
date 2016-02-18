#FIND_PACKAGE(OpenCV REQUIRED)

SET(SRC_LIST
    GridMap.cpp
    BasicVFF.cpp
)
IF(WIN32)
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include D:/soft/opencv/build/include)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib D:/soft/opencv/build/x64/vc12/lib)
ELSE(WIN32)
	SET(CMAKE_CXX_COMPILE "g++")
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)
ENDIF(WIN32)

ADD_LIBRARY(avoidance SHARED ${SRC_LIST})
ADD_LIBRARY(avoidance_static STATIC ${SRC_LIST})

IF(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    opencv_calib3d248d.lib
	opencv_core248d.lib
	opencv_features2d248d.lib
	opencv_highgui248d.lib
	opencv_imgproc248d.lib
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    ${OpenCV_LIBS}
)

IF(WIN32)
TARGET_LINK_LIBRARIES(avoidance_static
    opencv_calib3d248d.lib
	opencv_core248d.lib
	opencv_features2d248d.lib
	opencv_highgui248d.lib
	opencv_imgproc248d.lib
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    ${OpenCV_LIBS}
)
ENDIF(WIN32)


ENDIF(WIN32)



#FIND_PACKAGE(OpenCV REQUIRED)

SET(SRC_LIST
    GridMap.cpp
    BasicVFF.cpp
)
ADD_LIBRARY(avoidance SHARED ${SRC_LIST})
ADD_LIBRARY(avoidance_static STATIC ${SRC_LIST})

IF(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    opencv_calib3d248.lib
	opencv_core248.lib
	opencv_features2d248.lib
	opencv_highgui248.lib
	opencv_imgproc248.lib
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    ${OpenCV_LIBS}
)
ENDIF(WIN32)



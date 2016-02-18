
SET(SRC main.cpp)
ADD_EXECUTABLE(main ${SRC})
IF(WIN32)
TARGET_LINK_LIBRARIES(main 
    opencv_calib3d248.lib
	opencv_core248.lib
	opencv_features2d248.lib
	opencv_highgui248.lib
	opencv_imgproc248.lib
	#avoidance.dll
	avoidance_static.lib
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(main 
    ${OpenCV_LIBS}
    avoidance
)
ENDIF(WIN32)

FIND_PACKAGE(OpenCV REQUIRED)

SET(SRC_LIST
    gridmap.cpp
    #BasicVFF.cpp
    BasicVFH.cpp
)
ADD_LIBRARY(avoidance SHARED ${SRC_LIST})
ADD_LIBRARY(avoidance_static STATIC ${SRC_LIST})

IF(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    ${OpenCV_LIBS}
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(avoidance
    ${OpenCV_LIBS}
)
ENDIF(WIN32)



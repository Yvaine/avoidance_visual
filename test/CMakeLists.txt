
SET(SRC main.cpp)
ADD_EXECUTABLE(main ${SRC})
TARGET_LINK_LIBRARIES(main 
    ${OpenCV_LIBS}
    avoidance
)

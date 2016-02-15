FIND_PACKAGE(OpenCV REQUIRED)

ADD_EXECUTABLE(main
    main.cpp
    GridMap.cpp
    BasicVFF.cpp
)
TARGET_LINK_LIBRARIES(main 
    ${OpenCV_LIBS}
)


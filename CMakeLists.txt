SET(COMMON_C_FLAGS "-Wall -g -fvisibility=hidden")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS}")
SET(CMAKE_BUILD_TYPE "Release")

ADD_LIBRARY(
    base_lib

    SHARED

    base_lib.cpp
)

ADD_LIBRARY(
    dep_lib

    SHARED

    dep_lib.cpp
)

TARGET_LINK_LIBRARIES(dep_lib base_lib)

ADD_EXECUTABLE(
    main

    main.cpp
)
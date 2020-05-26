cmake_minimum_required(VERSION 3.15)
project(console_handler_images)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/handlerimage/handlerimages.h
        )

set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/handlerimage/handlerimages.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/defines.h
        )

set(INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        )

set(LIBS
        )

add_executable(${PROJECT_NAME} main.cpp  ${SOURCE} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBS} ${OpenMP_CXX_FLAGS})
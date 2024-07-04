cmake_minimum_required (VERSION 3.10.2)
#设置项目名称
enable_testing()

project(investment)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/invest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_executable(mytest ${CMAKE_CURRENT_SOURCE_DIR}/src/invest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)

target_link_libraries(mytest gtest)

add_test(NAME mytest COMMAND mytest)

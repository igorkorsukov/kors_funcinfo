cmake_minimum_required(VERSION 3.14)

project(funcinfo_example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_definitions(-D_KORS_NO_STRINGVIEW_CONSTEXPR_METHODS)

add_executable(${PROJECT_NAME}
    main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../funcinfo.h
)

cmake_minimum_required(VERSION 3.28.2)

project(Request)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()



find_library(CURLPP_LIB curlpp HINTS ${CMAKE_CURRENT_SOURCE_DIR}/libs/curlpp/lib64)
if(NOT CURLPP_LIB)
  message(FATAL "Could not find curlpp library")
else()
  message(STATUS "Found curlpp at ${CURLPP_LIB}")
endif()

find_library(CURL_LIB curl HINTS ${CMAKE_CURRENT_SOURCE_DIR}/libs/curl/lib)
if(NOT CURL_LIB)
  message(FATAL "Could not find curl library")
else()
  message(STATUS "Found curl at ${CURL_LIB}")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/curlpp/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/nlohmann)

link_libraries(${CURL_LIB} ${CURLPP_LIB})

add_executable(get src/Get.cpp)
add_executable(post src/Post.cpp)
add_executable(put src/Put.cpp)
add_executable(update src/Update.cpp)

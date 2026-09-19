cmake_minimum_required(VERSION 3.16)

project(keyValueDB LANGUAGES CXX)

add_library(keyValueDB_core db.cpp wal.cpp)
target_include_directories(keyValueDB_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(keyValueDB_core PUBLIC cxx_std_17)

add_executable(keyValueDB main.cpp)
target_link_libraries(keyValueDB PRIVATE keyValueDB_core)
set_target_properties(keyValueDB keyValueDB_core PROPERTIES CXX_EXTENSIONS OFF)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

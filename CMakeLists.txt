# CMake version
cmake_minimum_required(VERSION 3.21.3)

# Project name
project (animal_shelter)

# Define the search path for header files
include_directories(inc)

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" -pthread)
    endif()    
endif()    

set(petFiles
            src/Pet.cpp inc/Pet.hpp
            src/Dog.cpp inc/Dog.hpp
            src/Cat.cpp inc/Cat.hpp
            src/Lock.cpp inc/Lock.hpp)

add_library(lib STATIC ${petFiles})

add_executable(${PROJECT_NAME} 
                src/main.cpp)


target_link_libraries(${PROJECT_NAME} PUBLIC lib pthread)

target_include_directories(${PROJECT_NAME} 
 PRIVATE src INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
	$<INSTALL_INTERFACE:inc>)
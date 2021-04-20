cmake_minimum_required (VERSION 2.8) 
project (raspicam_test)

find_package(wiringPi REQUIRED)
find_package(raspicam REQUIRED)

include_directories(${WIRINGPI_INCLUDE_DIRS})

add_executable (simpletest_raspicam simpletest_raspicam.cpp)  
target_link_libraries(simpletest_raspicam ${WIRINGPI_LIBRARIES})
target_link_libraries (simpletest_raspicam ${raspicam_LIBS})
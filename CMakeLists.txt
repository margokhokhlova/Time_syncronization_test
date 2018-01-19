cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(TimeSyncro_unit)
set( OpenCV_DIR "F:/OPENCV/opencv-3.1.0/buildVS14_64/" )
option( OpenCV_STATIC OFF )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Additional Library Directories
link_directories( ${OpenCV_LIB_DIR} )

add_executable(TimeSyncro_unit TimeSyncro_unit.cpp)
target_link_libraries(TimeSyncro_unit ${OpenCV_LIBS} )
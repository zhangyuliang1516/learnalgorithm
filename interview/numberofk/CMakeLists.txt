file(GLOB PROJECT_SOURCES *.cpp *.h)
include_directories(../utils)
add_executable(numberofk ${PROJECT_SOURCES})

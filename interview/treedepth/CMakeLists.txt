file(GLOB PROJECT_SOURCES *.cpp *.h)
include_directories(../utils)
add_executable(treedepth ${PROJECT_SOURCES})
target_link_libraries(treedepth utils)

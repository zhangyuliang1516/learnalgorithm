file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(pathintree ${PROJECT_SOURCES})
target_link_libraries(pathintree utils)

file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(binarytreetest ${PROJECT_SOURCES})
target_link_libraries(binarytreetest utils)

file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(kthnodefromend ${PROJECT_SOURCES})
target_link_libraries(kthnodefromend utils)

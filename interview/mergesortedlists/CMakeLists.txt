file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(mergesortedlists ${PROJECT_SOURCES})
target_link_libraries(mergesortedlists utils)

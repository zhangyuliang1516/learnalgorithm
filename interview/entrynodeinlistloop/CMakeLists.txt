file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(entrynodeinlistloop ${PROJECT_SOURCES})
target_link_libraries(entrynodeinlistloop utils)

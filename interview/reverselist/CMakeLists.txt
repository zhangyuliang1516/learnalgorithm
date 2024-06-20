file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(reverselist ${PROJECT_SOURCES})
target_link_libraries(reverselist utils)

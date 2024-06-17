file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(printlistinreversedorder ${PROJECT_SOURCES})
target_link_libraries(printlistinreversedorder utils)

file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(deletenodeinlist ${PROJECT_SOURCES})
target_link_libraries(deletenodeinlist utils)

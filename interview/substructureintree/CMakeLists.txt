file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(substructureintree ${PROJECT_SOURCES})
target_link_libraries(substructureintree utils)

file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(serializebinarytree ${PROJECT_SOURCES})
target_link_libraries(serializebinarytree utils)

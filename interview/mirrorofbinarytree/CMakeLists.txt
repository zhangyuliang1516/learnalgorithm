file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(mirrorofbinarytree ${PROJECT_SOURCES})
target_link_libraries(mirrorofbinarytree utils)

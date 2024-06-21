file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(symmetricalbinarytree ${PROJECT_SOURCES})
target_link_libraries(symmetricalbinarytree utils)

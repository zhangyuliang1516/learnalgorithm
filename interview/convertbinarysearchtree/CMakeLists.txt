file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(convertbinarysearchtree ${PROJECT_SOURCES})
target_link_libraries(convertbinarysearchtree utils)

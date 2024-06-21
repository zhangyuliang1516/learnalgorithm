file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(printbinarytreefromtoptobottom ${PROJECT_SOURCES})
target_link_libraries(printbinarytreefromtoptobottom utils)

file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(printbinarytreeinlines ${PROJECT_SOURCES})
target_link_libraries(printbinarytreeinlines utils)

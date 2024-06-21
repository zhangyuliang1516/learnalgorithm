file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(printbinarytreeinzigzag ${PROJECT_SOURCES})
target_link_libraries(printbinarytreeinzigzag utils)

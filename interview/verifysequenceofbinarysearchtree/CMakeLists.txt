file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(verifysequenceofbinarysearchtree ${PROJECT_SOURCES})
target_link_libraries(verifysequenceofbinarysearchtree utils)

file(GLOB PROJECT_SOURCES *.cpp *.h)
include_directories(../utils)
add_executable(kthnodeinbinarysearchtree ${PROJECT_SOURCES})
target_link_libraries(kthnodeinbinarysearchtree utils)

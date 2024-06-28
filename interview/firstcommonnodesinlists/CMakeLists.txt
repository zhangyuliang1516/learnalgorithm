file(GLOB PROJECT_SOURCES *.cpp *.h)
include_directories(../utils)
add_executable(firstcommonnodesinlists ${PROJECT_SOURCES})
target_link_libraries(firstcommonnodesinlists utils)

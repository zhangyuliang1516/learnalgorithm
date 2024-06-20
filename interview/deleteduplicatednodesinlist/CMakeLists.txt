file(GLOB PROJECT_SOURCES *.cpp *.h)
add_executable(deleteduplicatednodesinlist ${PROJECT_SOURCES})
target_link_libraries(deleteduplicatednodesinlist utils)

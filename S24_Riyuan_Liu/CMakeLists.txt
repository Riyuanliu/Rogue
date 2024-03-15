add_executable(Game Source.cpp)

include_directories("../Rogue/include")

target_link_libraries(Game Rogue)
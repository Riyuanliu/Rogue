set(HEADER_FILES
	Bullets.h
	Enemy.h
	Game.h
	Item.h
	Player.h
	Score.h
)

set(SOURCE_FILES
	Bullets.cpp
	Enemy.cpp
	Game.cpp
	Item.cpp
	Player.cpp
	Score.cpp
	main.cpp

)

add_executable(Game ${HEADER_FILES} ${SOURCE_FILES})

include_directories("../Rogue/include")

target_link_libraries(Game Rogue)
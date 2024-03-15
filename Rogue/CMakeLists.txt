set(HEADER_FILEs
	include/Rogue.h
	src/RogueApplication.h
	src/Utility.h
	src/RogueWindow.h
	src/WindowImpl/h
	src/codeGLFW/WindowGLFW.h
)

set(SOURCE_FILES
	src/RogueAPplication.cpp
	src/RogueWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
)


add_library(Rogue SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Rogue
	PUBLIC
		$<$<CONFIG:Debug>:ROGUE_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:ROGUE_DEBUG=1>
	PRIVATE 
		ROGUE_LIB
)

if(MSVC)
	target_compile_definitions(Rogue PUBLIC ROGUE_MS_COMPILER)
endif()

target_include_directories(Rogue PRIVATE ../glfw/include)

target_include_directories(Rogue PRIVATE ../Rogue)


target_precompile_headers(Rogue PRIVATE pch.h)

target_link_libraries(Rogue glfw)
set(HEADER_FILES
	include/Rogue.h
	src/RogueApplication.h
	src/Utility.h
	src/RogueWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGLFW.h
	src/Renderer.h
	src/RendererImplement.h
	src/codeOpenGL/RendererOpenGL.h
	src/Shader.h
	src/ShaderImplement.h
	src/codeOpenGL/ShaderOpenGL.h
	src/Image.h
	src/ImageImplement.h
	src/codeOpenGL/ImageOpenGL.h
	src/RogueEvents.h
	src/RogueKeys.h
	src/Unit.h
)

set(SOURCE_FILES
	src/RogueApplication.cpp
	src/RogueWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
	src/Renderer.cpp
	src/codeOpenGL/RendererOpenGL.cpp
	src/Shader.cpp
	src/codeOpenGL/ShaderOpenGL.cpp
	src/Image.cpp
	src/codeOpenGL/ImageOpenGL.cpp
	src/RogueEvents.cpp
	src/Unit.cpp

)


add_library(Rogue SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Rogue
	PUBLIC
		$<$<CONFIG:Debug>:ROGUE_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:ROGUE_DEBUG=1>
	PRIVATE 
		ROGUE_LIB
		ROGUE_GLFW_WINDOW
		ROGUE_OPENGL
)

if(MSVC)
	target_compile_definitions(Rogue PUBLIC ROGUE_MS_COMPILER)
endif()

target_include_directories(Rogue PRIVATE ../glfw/include)
target_include_directories(Rogue PRIVATE ../Rogue/src)
target_include_directories(Rogue PRIVATE ../glad/include)
target_include_directories(Rogue PRIVATE ../stbi)

target_precompile_headers(Rogue PRIVATE src/pch.h)

target_link_libraries(Rogue glfw)
target_link_libraries(Rogue glad)
target_link_libraries(Rogue stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Rogue)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/Rogue)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/Rogue)

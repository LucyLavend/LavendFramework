# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (LavendFramework)

OPTION(USE_OPENAL "Use OpenAL library" ON)

OPTION(MAKE_VIXEL "Make Vixel game" ON)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# Create a group for Visual Studio
	SOURCE_GROUP(lavendframework REGULAR_EXPRESSION ".*/lavendframework/.*" )
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3/include/
	external/glm-0.9.9.2/
	external/glew-1.9.0/include/
	external/openal/include/
	lavendframework/
	.
)

link_directories( # g++ -Lpath/to/library
	
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_190
)

# LavendFramework (liblavendframework.a)
add_library(lavendframework # ar rcs liblavendframework.a
	lavendframework/camera.h
	lavendframework/camera.cpp
	
	lavendframework/renderer.h
	lavendframework/renderer.cpp
	
	lavendframework/sprite.h
	lavendframework/sprite.cpp
	
	lavendframework/core.h
	lavendframework/core.cpp
	
	#lavendframework/scene.h
	#lavendframework/scene.cpp
	
	lavendframework/entity.h
	lavendframework/entity.cpp
	
	#lavendframework/mesh.h
	#lavendframework/mesh.cpp
	
	#lavendframework/texture.h
	#lavendframework/texture.cpp
	
	#lavendframework/shader.h
	#lavendframework/shader.cpp
	
	#lavendframework/input.h
	#lavendframework/input.cpp
	
	#lavendframework/line.h
	#lavendframework/line.cpp
	
	#lavendframework/resourcemanager.h
	#lavendframework/resourcemanager.cpp
	
	#lavendframework/pointx.h
	#lavendframework/vectorx.h
	#lavendframework/singleton.h
	#lavendframework/lavendframeworkconfig.h
	#lavendframework/color.h
	
	lavendframework/timer.h
	lavendframework/timer.cpp
	
	#lavendframework/text.h
	#lavendframework/text.cpp
	
	#lavendframework/canvas.h
	#lavendframework/canvas.cpp
	
)

# Demo
add_executable(demo # g++ demo/demo.cpp -o demo
	demo/demo.cpp
)
target_link_libraries(demo # g++ -llavendframework
	lavendframework
	${ALL_GRAPHICS_LIBS}
)
# Copy assets and shaders to the build directory
# (In Visual Studio, copy these directories to either 'Release' or 'Build')
file(
	COPY demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY lavendframework/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)

####################################################################
# OpenAL                                                           #
####################################################################
IF(USE_OPENAL)
	add_subdirectory (external/openal)
	include_directories(
		${CMAKE_SOURCE_DIR}/external/openal/include/
	)

	link_directories(
		${CMAKE_SOURCE_DIR}/external/openal/
	)

	IF(WIN32)
		SET(OPENAL OpenAL32)
	ELSE()
		SET(OPENAL openal)
	ENDIF()
ENDIF()

####################################################################
# vixel                                                            #
####################################################################
IF(MAKE_VIXEL)
	add_executable(vixel
		vixel/main.cpp
		vixel/character.cpp
		vixel/character.h
		vixel/home.cpp
		vixel/home.h
		vixel/basicentity.cpp
		vixel/basicentity.h
		vixel/superscene.cpp
		vixel/superscene.h
		vixel/game.cpp
		vixel/game.h
		vixel/audio/audio.cpp
		vixel/audio/audio.h
		vixel/audio/sound.cpp
		vixel/audio/sound.h
		vixel/audio/wav.cpp
		vixel/audio/wav.h
	)
	target_link_libraries(vixel
		${ALL_GRAPHICS_LIBS}
		${OPENAL}
	)
	# Copy assets to the build directory
	file(
		COPY vixel/assets
		DESTINATION ${CMAKE_BINARY_DIR}
	)
ENDIF()

####################################################################



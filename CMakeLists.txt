# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (project)

find_package(GLEW REQUIRED)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -g -pg")
	set(CMAKE_CXX_FLAGS "-Wall -Wstrict-aliasing -std=c++0x -O2")

	set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
	 set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11")
endif(UNIX)



# Look up SDL2 and add the include directory to our include path

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)

find_package(SDL2_mixer REQUIRED)

find_package(SDL2_ttf REQUIRED)

find_package(SDL2_image REQUIRED)


add_subdirectory (external)



# Compile external dependencies


# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	${GLEW_INCLUDE_DIRS}
	external/SDL2-2.0.4/include
	${SDL2_MIXER_INCLUDE_DIRS}
	${SDL2_TTF_INCLUDE_DIR}
	${SDL2_INCLUDE_DIR}
	external/glm-0.9.7.0/
	external/glew-1.9.0/include/
	.
)


set(ALL_LIBS
	${OPENGL_LIBRARY}
	engine
	SDL2
	${SDL2_MIXER_LIBRARIES}
	${SDL2_TTF_LIBRARY}
	${SDL2IMAGE_LIBRARY}
	${GLEW_LIBRARIES}
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS

)

# Project


add_library(engine
	engine/shader.cpp
	engine/shader.h
	engine/vector2.h
	engine/vector2.cpp
	engine/camera.cpp
	engine/camera.h
	engine/renderer.h
	engine/renderer.cpp
	engine/scene.h
	engine/scene.cpp
	engine/image.cpp
	engine/image.h
	engine/entity.h
	engine/entity.cpp
  	engine/recoursemanager.h
 	engine/recoursemanager.cpp
	engine/sound.h
	engine/sound.cpp
   	engine/input.h
	engine/input.cpp
	engine/hudobject.cpp
	engine/hudobject.h
	engine/text.cpp
	engine/text.h
	engine/color.cpp
	engine/color.h
	engine/shape.cpp
	engine/shape.h
)

add_executable(project
	project/main.cpp
	project/mainscene.h
	project/mainscene.cpp
	project/tower.h
	project/tower.cpp
	project/enemy.cpp
	project/enemy.h
	project/bullet.cpp
	project/bullet.h
	project/worker.cpp
	project/worker.h
	project/simpleentity.cpp
	project/simpleentity.h
	project/particle.cpp
	project/particle.h
	project/towers/dogtower.h
	project/towers/dogtower.cpp
    project/bullets/dogbullet.cpp
    project/bullets/dogbullet.h
    project/bullets/bunnybullet.h
    project/bullets/bunnybullet.cpp
    project/towers/bunnytower.cpp
    project/towers/bunnytower.h
    project/menuitem.cpp
    project/menuitem.h
)

target_link_libraries(project
	${ALL_LIBS}
)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	target_link_libraries(project
		-lGL
	)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Xcode and Visual working directories
#set_target_properties(project PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project/“)
#create_target_launcher(project WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/project/“)


SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET project POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/project${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/project/“
#)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )


# Copy assets to the build directory
file(
	COPY project/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY engine/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)

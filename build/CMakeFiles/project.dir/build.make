# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/corne/Desktop/SDL2-Opengl_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/corne/Desktop/SDL2-Opengl_Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/project/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/main.cpp.o: ../project/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/main.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/main.cpp

CMakeFiles/project.dir/project/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/main.cpp > CMakeFiles/project.dir/project/main.cpp.i

CMakeFiles/project.dir/project/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/main.cpp -o CMakeFiles/project.dir/project/main.cpp.s

CMakeFiles/project.dir/project/main.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/main.cpp.o.requires

CMakeFiles/project.dir/project/main.cpp.o.provides: CMakeFiles/project.dir/project/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/main.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/main.cpp.o.provides

CMakeFiles/project.dir/project/main.cpp.o.provides.build: CMakeFiles/project.dir/project/main.cpp.o

CMakeFiles/project.dir/project/mainscene.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/mainscene.cpp.o: ../project/mainscene.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/mainscene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/mainscene.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/mainscene.cpp

CMakeFiles/project.dir/project/mainscene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/mainscene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/mainscene.cpp > CMakeFiles/project.dir/project/mainscene.cpp.i

CMakeFiles/project.dir/project/mainscene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/mainscene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/mainscene.cpp -o CMakeFiles/project.dir/project/mainscene.cpp.s

CMakeFiles/project.dir/project/mainscene.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/mainscene.cpp.o.requires

CMakeFiles/project.dir/project/mainscene.cpp.o.provides: CMakeFiles/project.dir/project/mainscene.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/mainscene.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/mainscene.cpp.o.provides

CMakeFiles/project.dir/project/mainscene.cpp.o.provides.build: CMakeFiles/project.dir/project/mainscene.cpp.o

CMakeFiles/project.dir/project/tower.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/tower.cpp.o: ../project/tower.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/tower.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/tower.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/tower.cpp

CMakeFiles/project.dir/project/tower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/tower.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/tower.cpp > CMakeFiles/project.dir/project/tower.cpp.i

CMakeFiles/project.dir/project/tower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/tower.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/tower.cpp -o CMakeFiles/project.dir/project/tower.cpp.s

CMakeFiles/project.dir/project/tower.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/tower.cpp.o.requires

CMakeFiles/project.dir/project/tower.cpp.o.provides: CMakeFiles/project.dir/project/tower.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/tower.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/tower.cpp.o.provides

CMakeFiles/project.dir/project/tower.cpp.o.provides.build: CMakeFiles/project.dir/project/tower.cpp.o

CMakeFiles/project.dir/project/enemy.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/enemy.cpp.o: ../project/enemy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/enemy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/enemy.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/enemy.cpp

CMakeFiles/project.dir/project/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/enemy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/enemy.cpp > CMakeFiles/project.dir/project/enemy.cpp.i

CMakeFiles/project.dir/project/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/enemy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/enemy.cpp -o CMakeFiles/project.dir/project/enemy.cpp.s

CMakeFiles/project.dir/project/enemy.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/enemy.cpp.o.requires

CMakeFiles/project.dir/project/enemy.cpp.o.provides: CMakeFiles/project.dir/project/enemy.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/enemy.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/enemy.cpp.o.provides

CMakeFiles/project.dir/project/enemy.cpp.o.provides.build: CMakeFiles/project.dir/project/enemy.cpp.o

CMakeFiles/project.dir/project/bullet.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/bullet.cpp.o: ../project/bullet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/bullet.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/bullet.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/bullet.cpp

CMakeFiles/project.dir/project/bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/bullet.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/bullet.cpp > CMakeFiles/project.dir/project/bullet.cpp.i

CMakeFiles/project.dir/project/bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/bullet.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/bullet.cpp -o CMakeFiles/project.dir/project/bullet.cpp.s

CMakeFiles/project.dir/project/bullet.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/bullet.cpp.o.requires

CMakeFiles/project.dir/project/bullet.cpp.o.provides: CMakeFiles/project.dir/project/bullet.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/bullet.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/bullet.cpp.o.provides

CMakeFiles/project.dir/project/bullet.cpp.o.provides.build: CMakeFiles/project.dir/project/bullet.cpp.o

CMakeFiles/project.dir/project/worker.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/worker.cpp.o: ../project/worker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/worker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/worker.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/worker.cpp

CMakeFiles/project.dir/project/worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/worker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/worker.cpp > CMakeFiles/project.dir/project/worker.cpp.i

CMakeFiles/project.dir/project/worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/worker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/worker.cpp -o CMakeFiles/project.dir/project/worker.cpp.s

CMakeFiles/project.dir/project/worker.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/worker.cpp.o.requires

CMakeFiles/project.dir/project/worker.cpp.o.provides: CMakeFiles/project.dir/project/worker.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/worker.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/worker.cpp.o.provides

CMakeFiles/project.dir/project/worker.cpp.o.provides.build: CMakeFiles/project.dir/project/worker.cpp.o

CMakeFiles/project.dir/project/simpleentity.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/simpleentity.cpp.o: ../project/simpleentity.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/simpleentity.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/simpleentity.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/simpleentity.cpp

CMakeFiles/project.dir/project/simpleentity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/simpleentity.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/simpleentity.cpp > CMakeFiles/project.dir/project/simpleentity.cpp.i

CMakeFiles/project.dir/project/simpleentity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/simpleentity.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/simpleentity.cpp -o CMakeFiles/project.dir/project/simpleentity.cpp.s

CMakeFiles/project.dir/project/simpleentity.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/simpleentity.cpp.o.requires

CMakeFiles/project.dir/project/simpleentity.cpp.o.provides: CMakeFiles/project.dir/project/simpleentity.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/simpleentity.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/simpleentity.cpp.o.provides

CMakeFiles/project.dir/project/simpleentity.cpp.o.provides.build: CMakeFiles/project.dir/project/simpleentity.cpp.o

CMakeFiles/project.dir/project/particle.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/particle.cpp.o: ../project/particle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/particle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/particle.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/particle.cpp

CMakeFiles/project.dir/project/particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/particle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/particle.cpp > CMakeFiles/project.dir/project/particle.cpp.i

CMakeFiles/project.dir/project/particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/particle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/particle.cpp -o CMakeFiles/project.dir/project/particle.cpp.s

CMakeFiles/project.dir/project/particle.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/particle.cpp.o.requires

CMakeFiles/project.dir/project/particle.cpp.o.provides: CMakeFiles/project.dir/project/particle.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/particle.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/particle.cpp.o.provides

CMakeFiles/project.dir/project/particle.cpp.o.provides.build: CMakeFiles/project.dir/project/particle.cpp.o

CMakeFiles/project.dir/project/towers/dogtower.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/towers/dogtower.cpp.o: ../project/towers/dogtower.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/towers/dogtower.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/towers/dogtower.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/towers/dogtower.cpp

CMakeFiles/project.dir/project/towers/dogtower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/towers/dogtower.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/towers/dogtower.cpp > CMakeFiles/project.dir/project/towers/dogtower.cpp.i

CMakeFiles/project.dir/project/towers/dogtower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/towers/dogtower.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/towers/dogtower.cpp -o CMakeFiles/project.dir/project/towers/dogtower.cpp.s

CMakeFiles/project.dir/project/towers/dogtower.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/towers/dogtower.cpp.o.requires

CMakeFiles/project.dir/project/towers/dogtower.cpp.o.provides: CMakeFiles/project.dir/project/towers/dogtower.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/towers/dogtower.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/towers/dogtower.cpp.o.provides

CMakeFiles/project.dir/project/towers/dogtower.cpp.o.provides.build: CMakeFiles/project.dir/project/towers/dogtower.cpp.o

CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o: ../project/bullets/dogbullet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/bullets/dogbullet.cpp

CMakeFiles/project.dir/project/bullets/dogbullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/bullets/dogbullet.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/bullets/dogbullet.cpp > CMakeFiles/project.dir/project/bullets/dogbullet.cpp.i

CMakeFiles/project.dir/project/bullets/dogbullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/bullets/dogbullet.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/bullets/dogbullet.cpp -o CMakeFiles/project.dir/project/bullets/dogbullet.cpp.s

CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.requires

CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.provides: CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.provides

CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.provides.build: CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o

CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o: ../project/bullets/bunnybullet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/bullets/bunnybullet.cpp

CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/bullets/bunnybullet.cpp > CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.i

CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/bullets/bunnybullet.cpp -o CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.s

CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.requires

CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.provides: CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.provides

CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.provides.build: CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o

CMakeFiles/project.dir/project/towers/bunnytower.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/project/towers/bunnytower.cpp.o: ../project/towers/bunnytower.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project.dir/project/towers/bunnytower.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project.dir/project/towers/bunnytower.cpp.o -c /home/corne/Desktop/SDL2-Opengl_Engine/project/towers/bunnytower.cpp

CMakeFiles/project.dir/project/towers/bunnytower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/towers/bunnytower.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/corne/Desktop/SDL2-Opengl_Engine/project/towers/bunnytower.cpp > CMakeFiles/project.dir/project/towers/bunnytower.cpp.i

CMakeFiles/project.dir/project/towers/bunnytower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/towers/bunnytower.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/corne/Desktop/SDL2-Opengl_Engine/project/towers/bunnytower.cpp -o CMakeFiles/project.dir/project/towers/bunnytower.cpp.s

CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.requires:
.PHONY : CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.requires

CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.provides: CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.provides.build
.PHONY : CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.provides

CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.provides.build: CMakeFiles/project.dir/project/towers/bunnytower.cpp.o

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/project/main.cpp.o" \
"CMakeFiles/project.dir/project/mainscene.cpp.o" \
"CMakeFiles/project.dir/project/tower.cpp.o" \
"CMakeFiles/project.dir/project/enemy.cpp.o" \
"CMakeFiles/project.dir/project/bullet.cpp.o" \
"CMakeFiles/project.dir/project/worker.cpp.o" \
"CMakeFiles/project.dir/project/simpleentity.cpp.o" \
"CMakeFiles/project.dir/project/particle.cpp.o" \
"CMakeFiles/project.dir/project/towers/dogtower.cpp.o" \
"CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o" \
"CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o" \
"CMakeFiles/project.dir/project/towers/bunnytower.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/project/main.cpp.o
project: CMakeFiles/project.dir/project/mainscene.cpp.o
project: CMakeFiles/project.dir/project/tower.cpp.o
project: CMakeFiles/project.dir/project/enemy.cpp.o
project: CMakeFiles/project.dir/project/bullet.cpp.o
project: CMakeFiles/project.dir/project/worker.cpp.o
project: CMakeFiles/project.dir/project/simpleentity.cpp.o
project: CMakeFiles/project.dir/project/particle.cpp.o
project: CMakeFiles/project.dir/project/towers/dogtower.cpp.o
project: CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o
project: CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o
project: CMakeFiles/project.dir/project/towers/bunnytower.cpp.o
project: CMakeFiles/project.dir/build.make
project: /usr/lib/x86_64-linux-gnu/libGLU.so
project: /usr/lib/x86_64-linux-gnu/libGL.so
project: libengine.a
project: /usr/local/lib/libSDL2_mixer.so
project: /usr/local/lib/libSDL2_ttf.so
project: /usr/local/lib/libSDL2_image.so
project: /usr/lib64/libGLEW.so
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/main.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/mainscene.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/tower.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/enemy.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/bullet.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/worker.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/simpleentity.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/particle.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/towers/dogtower.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/bullets/dogbullet.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/bullets/bunnybullet.cpp.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/project/towers/bunnytower.cpp.o.requires
.PHONY : CMakeFiles/project.dir/requires

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /home/corne/Desktop/SDL2-Opengl_Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corne/Desktop/SDL2-Opengl_Engine /home/corne/Desktop/SDL2-Opengl_Engine /home/corne/Desktop/SDL2-Opengl_Engine/build /home/corne/Desktop/SDL2-Opengl_Engine/build /home/corne/Desktop/SDL2-Opengl_Engine/build/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend


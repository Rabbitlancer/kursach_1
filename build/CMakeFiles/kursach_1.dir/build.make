# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rabbitlancer/code/kursach_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rabbitlancer/code/kursach_1/build

# Include any dependencies generated for this target.
include CMakeFiles/kursach_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kursach_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kursach_1.dir/flags.make

CMakeFiles/kursach_1.dir/src/main.cpp.o: CMakeFiles/kursach_1.dir/flags.make
CMakeFiles/kursach_1.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rabbitlancer/code/kursach_1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kursach_1.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kursach_1.dir/src/main.cpp.o -c /home/rabbitlancer/code/kursach_1/src/main.cpp

CMakeFiles/kursach_1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kursach_1.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rabbitlancer/code/kursach_1/src/main.cpp > CMakeFiles/kursach_1.dir/src/main.cpp.i

CMakeFiles/kursach_1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kursach_1.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rabbitlancer/code/kursach_1/src/main.cpp -o CMakeFiles/kursach_1.dir/src/main.cpp.s

CMakeFiles/kursach_1.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/kursach_1.dir/src/main.cpp.o.requires

CMakeFiles/kursach_1.dir/src/main.cpp.o.provides: CMakeFiles/kursach_1.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/kursach_1.dir/build.make CMakeFiles/kursach_1.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/kursach_1.dir/src/main.cpp.o.provides

CMakeFiles/kursach_1.dir/src/main.cpp.o.provides.build: CMakeFiles/kursach_1.dir/src/main.cpp.o

CMakeFiles/kursach_1.dir/src/logic.cpp.o: CMakeFiles/kursach_1.dir/flags.make
CMakeFiles/kursach_1.dir/src/logic.cpp.o: ../src/logic.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rabbitlancer/code/kursach_1/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kursach_1.dir/src/logic.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kursach_1.dir/src/logic.cpp.o -c /home/rabbitlancer/code/kursach_1/src/logic.cpp

CMakeFiles/kursach_1.dir/src/logic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kursach_1.dir/src/logic.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rabbitlancer/code/kursach_1/src/logic.cpp > CMakeFiles/kursach_1.dir/src/logic.cpp.i

CMakeFiles/kursach_1.dir/src/logic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kursach_1.dir/src/logic.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rabbitlancer/code/kursach_1/src/logic.cpp -o CMakeFiles/kursach_1.dir/src/logic.cpp.s

CMakeFiles/kursach_1.dir/src/logic.cpp.o.requires:
.PHONY : CMakeFiles/kursach_1.dir/src/logic.cpp.o.requires

CMakeFiles/kursach_1.dir/src/logic.cpp.o.provides: CMakeFiles/kursach_1.dir/src/logic.cpp.o.requires
	$(MAKE) -f CMakeFiles/kursach_1.dir/build.make CMakeFiles/kursach_1.dir/src/logic.cpp.o.provides.build
.PHONY : CMakeFiles/kursach_1.dir/src/logic.cpp.o.provides

CMakeFiles/kursach_1.dir/src/logic.cpp.o.provides.build: CMakeFiles/kursach_1.dir/src/logic.cpp.o

CMakeFiles/kursach_1.dir/src/render.cpp.o: CMakeFiles/kursach_1.dir/flags.make
CMakeFiles/kursach_1.dir/src/render.cpp.o: ../src/render.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rabbitlancer/code/kursach_1/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kursach_1.dir/src/render.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kursach_1.dir/src/render.cpp.o -c /home/rabbitlancer/code/kursach_1/src/render.cpp

CMakeFiles/kursach_1.dir/src/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kursach_1.dir/src/render.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rabbitlancer/code/kursach_1/src/render.cpp > CMakeFiles/kursach_1.dir/src/render.cpp.i

CMakeFiles/kursach_1.dir/src/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kursach_1.dir/src/render.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rabbitlancer/code/kursach_1/src/render.cpp -o CMakeFiles/kursach_1.dir/src/render.cpp.s

CMakeFiles/kursach_1.dir/src/render.cpp.o.requires:
.PHONY : CMakeFiles/kursach_1.dir/src/render.cpp.o.requires

CMakeFiles/kursach_1.dir/src/render.cpp.o.provides: CMakeFiles/kursach_1.dir/src/render.cpp.o.requires
	$(MAKE) -f CMakeFiles/kursach_1.dir/build.make CMakeFiles/kursach_1.dir/src/render.cpp.o.provides.build
.PHONY : CMakeFiles/kursach_1.dir/src/render.cpp.o.provides

CMakeFiles/kursach_1.dir/src/render.cpp.o.provides.build: CMakeFiles/kursach_1.dir/src/render.cpp.o

# Object files for target kursach_1
kursach_1_OBJECTS = \
"CMakeFiles/kursach_1.dir/src/main.cpp.o" \
"CMakeFiles/kursach_1.dir/src/logic.cpp.o" \
"CMakeFiles/kursach_1.dir/src/render.cpp.o"

# External object files for target kursach_1
kursach_1_EXTERNAL_OBJECTS =

kursach_1: CMakeFiles/kursach_1.dir/src/main.cpp.o
kursach_1: CMakeFiles/kursach_1.dir/src/logic.cpp.o
kursach_1: CMakeFiles/kursach_1.dir/src/render.cpp.o
kursach_1: CMakeFiles/kursach_1.dir/build.make
kursach_1: CMakeFiles/kursach_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable kursach_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kursach_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kursach_1.dir/build: kursach_1
.PHONY : CMakeFiles/kursach_1.dir/build

CMakeFiles/kursach_1.dir/requires: CMakeFiles/kursach_1.dir/src/main.cpp.o.requires
CMakeFiles/kursach_1.dir/requires: CMakeFiles/kursach_1.dir/src/logic.cpp.o.requires
CMakeFiles/kursach_1.dir/requires: CMakeFiles/kursach_1.dir/src/render.cpp.o.requires
.PHONY : CMakeFiles/kursach_1.dir/requires

CMakeFiles/kursach_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kursach_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kursach_1.dir/clean

CMakeFiles/kursach_1.dir/depend:
	cd /home/rabbitlancer/code/kursach_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rabbitlancer/code/kursach_1 /home/rabbitlancer/code/kursach_1 /home/rabbitlancer/code/kursach_1/build /home/rabbitlancer/code/kursach_1/build /home/rabbitlancer/code/kursach_1/build/CMakeFiles/kursach_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kursach_1.dir/depend


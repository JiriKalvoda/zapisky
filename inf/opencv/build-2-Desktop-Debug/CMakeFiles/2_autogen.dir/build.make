# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jiri/skola/inf/opencv/2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jiri/skola/inf/opencv/build-2-Desktop-Debug

# Utility rule file for 2_autogen.

# Include the progress variables for this target.
include CMakeFiles/2_autogen.dir/progress.make

CMakeFiles/2_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jiri/skola/inf/opencv/build-2-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target 2"
	/usr/bin/cmake -E cmake_autogen /home/jiri/skola/inf/opencv/build-2-Desktop-Debug/CMakeFiles/2_autogen.dir/AutogenInfo.json Debug

2_autogen: CMakeFiles/2_autogen
2_autogen: CMakeFiles/2_autogen.dir/build.make

.PHONY : 2_autogen

# Rule to build all files generated by this target.
CMakeFiles/2_autogen.dir/build: 2_autogen

.PHONY : CMakeFiles/2_autogen.dir/build

CMakeFiles/2_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2_autogen.dir/clean

CMakeFiles/2_autogen.dir/depend:
	cd /home/jiri/skola/inf/opencv/build-2-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jiri/skola/inf/opencv/2 /home/jiri/skola/inf/opencv/2 /home/jiri/skola/inf/opencv/build-2-Desktop-Debug /home/jiri/skola/inf/opencv/build-2-Desktop-Debug /home/jiri/skola/inf/opencv/build-2-Desktop-Debug/CMakeFiles/2_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2_autogen.dir/depend


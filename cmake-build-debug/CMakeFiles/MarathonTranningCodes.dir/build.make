# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\carlo\Desktop\MarathonTranningCodes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MarathonTranningCodes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MarathonTranningCodes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarathonTranningCodes.dir/flags.make

CMakeFiles/MarathonTranningCodes.dir/main.cpp.obj: CMakeFiles/MarathonTranningCodes.dir/flags.make
CMakeFiles/MarathonTranningCodes.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MarathonTranningCodes.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MarathonTranningCodes.dir\main.cpp.obj -c C:\Users\carlo\Desktop\MarathonTranningCodes\main.cpp

CMakeFiles/MarathonTranningCodes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarathonTranningCodes.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carlo\Desktop\MarathonTranningCodes\main.cpp > CMakeFiles\MarathonTranningCodes.dir\main.cpp.i

CMakeFiles/MarathonTranningCodes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarathonTranningCodes.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carlo\Desktop\MarathonTranningCodes\main.cpp -o CMakeFiles\MarathonTranningCodes.dir\main.cpp.s

# Object files for target MarathonTranningCodes
MarathonTranningCodes_OBJECTS = \
"CMakeFiles/MarathonTranningCodes.dir/main.cpp.obj"

# External object files for target MarathonTranningCodes
MarathonTranningCodes_EXTERNAL_OBJECTS =

MarathonTranningCodes.exe: CMakeFiles/MarathonTranningCodes.dir/main.cpp.obj
MarathonTranningCodes.exe: CMakeFiles/MarathonTranningCodes.dir/build.make
MarathonTranningCodes.exe: CMakeFiles/MarathonTranningCodes.dir/linklibs.rsp
MarathonTranningCodes.exe: CMakeFiles/MarathonTranningCodes.dir/objects1.rsp
MarathonTranningCodes.exe: CMakeFiles/MarathonTranningCodes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MarathonTranningCodes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MarathonTranningCodes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarathonTranningCodes.dir/build: MarathonTranningCodes.exe

.PHONY : CMakeFiles/MarathonTranningCodes.dir/build

CMakeFiles/MarathonTranningCodes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MarathonTranningCodes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MarathonTranningCodes.dir/clean

CMakeFiles/MarathonTranningCodes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carlo\Desktop\MarathonTranningCodes C:\Users\carlo\Desktop\MarathonTranningCodes C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug\CMakeFiles\MarathonTranningCodes.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarathonTranningCodes.dir/depend


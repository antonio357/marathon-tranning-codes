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
include CMakeFiles/Testing_stoi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Testing_stoi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Testing_stoi.dir/flags.make

CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.obj: CMakeFiles/Testing_stoi.dir/flags.make
CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.obj: ../TestingBasicCodes/Testing_stoi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Testing_stoi.dir\TestingBasicCodes\Testing_stoi.cpp.obj -c C:\Users\carlo\Desktop\MarathonTranningCodes\TestingBasicCodes\Testing_stoi.cpp

CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carlo\Desktop\MarathonTranningCodes\TestingBasicCodes\Testing_stoi.cpp > CMakeFiles\Testing_stoi.dir\TestingBasicCodes\Testing_stoi.cpp.i

CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carlo\Desktop\MarathonTranningCodes\TestingBasicCodes\Testing_stoi.cpp -o CMakeFiles\Testing_stoi.dir\TestingBasicCodes\Testing_stoi.cpp.s

# Object files for target Testing_stoi
Testing_stoi_OBJECTS = \
"CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.obj"

# External object files for target Testing_stoi
Testing_stoi_EXTERNAL_OBJECTS =

Testing_stoi.exe: CMakeFiles/Testing_stoi.dir/TestingBasicCodes/Testing_stoi.cpp.obj
Testing_stoi.exe: CMakeFiles/Testing_stoi.dir/build.make
Testing_stoi.exe: CMakeFiles/Testing_stoi.dir/linklibs.rsp
Testing_stoi.exe: CMakeFiles/Testing_stoi.dir/objects1.rsp
Testing_stoi.exe: CMakeFiles/Testing_stoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Testing_stoi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Testing_stoi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Testing_stoi.dir/build: Testing_stoi.exe

.PHONY : CMakeFiles/Testing_stoi.dir/build

CMakeFiles/Testing_stoi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Testing_stoi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Testing_stoi.dir/clean

CMakeFiles/Testing_stoi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carlo\Desktop\MarathonTranningCodes C:\Users\carlo\Desktop\MarathonTranningCodes C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug C:\Users\carlo\Desktop\MarathonTranningCodes\cmake-build-debug\CMakeFiles\Testing_stoi.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Testing_stoi.dir/depend

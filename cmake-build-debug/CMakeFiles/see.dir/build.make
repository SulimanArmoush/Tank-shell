# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ITE\Y3\GL\OpenGL\see

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/see.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/see.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/see.dir/flags.make

CMakeFiles/see.dir/main.cpp.obj: CMakeFiles/see.dir/flags.make
CMakeFiles/see.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/see.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\see.dir\main.cpp.obj -c D:\ITE\Y3\GL\OpenGL\see\main.cpp

CMakeFiles/see.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/see.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ITE\Y3\GL\OpenGL\see\main.cpp > CMakeFiles\see.dir\main.cpp.i

CMakeFiles/see.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/see.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ITE\Y3\GL\OpenGL\see\main.cpp -o CMakeFiles\see.dir\main.cpp.s

CMakeFiles/see.dir/PrimitiveDrawer.cpp.obj: CMakeFiles/see.dir/flags.make
CMakeFiles/see.dir/PrimitiveDrawer.cpp.obj: ../PrimitiveDrawer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/see.dir/PrimitiveDrawer.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\see.dir\PrimitiveDrawer.cpp.obj -c D:\ITE\Y3\GL\OpenGL\see\PrimitiveDrawer.cpp

CMakeFiles/see.dir/PrimitiveDrawer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/see.dir/PrimitiveDrawer.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ITE\Y3\GL\OpenGL\see\PrimitiveDrawer.cpp > CMakeFiles\see.dir\PrimitiveDrawer.cpp.i

CMakeFiles/see.dir/PrimitiveDrawer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/see.dir/PrimitiveDrawer.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ITE\Y3\GL\OpenGL\see\PrimitiveDrawer.cpp -o CMakeFiles\see.dir\PrimitiveDrawer.cpp.s

CMakeFiles/see.dir/Point.cpp.obj: CMakeFiles/see.dir/flags.make
CMakeFiles/see.dir/Point.cpp.obj: ../Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/see.dir/Point.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\see.dir\Point.cpp.obj -c D:\ITE\Y3\GL\OpenGL\see\Point.cpp

CMakeFiles/see.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/see.dir/Point.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ITE\Y3\GL\OpenGL\see\Point.cpp > CMakeFiles\see.dir\Point.cpp.i

CMakeFiles/see.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/see.dir/Point.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ITE\Y3\GL\OpenGL\see\Point.cpp -o CMakeFiles\see.dir\Point.cpp.s

CMakeFiles/see.dir/texture.cpp.obj: CMakeFiles/see.dir/flags.make
CMakeFiles/see.dir/texture.cpp.obj: ../texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/see.dir/texture.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\see.dir\texture.cpp.obj -c D:\ITE\Y3\GL\OpenGL\see\texture.cpp

CMakeFiles/see.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/see.dir/texture.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ITE\Y3\GL\OpenGL\see\texture.cpp > CMakeFiles\see.dir\texture.cpp.i

CMakeFiles/see.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/see.dir/texture.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ITE\Y3\GL\OpenGL\see\texture.cpp -o CMakeFiles\see.dir\texture.cpp.s

# Object files for target see
see_OBJECTS = \
"CMakeFiles/see.dir/main.cpp.obj" \
"CMakeFiles/see.dir/PrimitiveDrawer.cpp.obj" \
"CMakeFiles/see.dir/Point.cpp.obj" \
"CMakeFiles/see.dir/texture.cpp.obj"

# External object files for target see
see_EXTERNAL_OBJECTS =

see.exe: CMakeFiles/see.dir/main.cpp.obj
see.exe: CMakeFiles/see.dir/PrimitiveDrawer.cpp.obj
see.exe: CMakeFiles/see.dir/Point.cpp.obj
see.exe: CMakeFiles/see.dir/texture.cpp.obj
see.exe: CMakeFiles/see.dir/build.make
see.exe: CMakeFiles/see.dir/linklibs.rsp
see.exe: CMakeFiles/see.dir/objects1.rsp
see.exe: CMakeFiles/see.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable see.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\see.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/see.dir/build: see.exe

.PHONY : CMakeFiles/see.dir/build

CMakeFiles/see.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\see.dir\cmake_clean.cmake
.PHONY : CMakeFiles/see.dir/clean

CMakeFiles/see.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ITE\Y3\GL\OpenGL\see D:\ITE\Y3\GL\OpenGL\see D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug D:\ITE\Y3\GL\OpenGL\see\cmake-build-debug\CMakeFiles\see.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/see.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\study\cpp\notebook\Util

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\study\cpp\notebook\Util\build

# Include any dependencies generated for this target.
include Sort/CMakeFiles/Sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Sort/CMakeFiles/Sort.dir/compiler_depend.make

# Include the progress variables for this target.
include Sort/CMakeFiles/Sort.dir/progress.make

# Include the compile flags for this target's objects.
include Sort/CMakeFiles/Sort.dir/flags.make

Sort/CMakeFiles/Sort.dir/core/test.cpp.obj: Sort/CMakeFiles/Sort.dir/flags.make
Sort/CMakeFiles/Sort.dir/core/test.cpp.obj: Sort/CMakeFiles/Sort.dir/includes_CXX.rsp
Sort/CMakeFiles/Sort.dir/core/test.cpp.obj: D:/study/cpp/notebook/Util/Sort/core/test.cpp
Sort/CMakeFiles/Sort.dir/core/test.cpp.obj: Sort/CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\study\cpp\notebook\Util\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Sort/CMakeFiles/Sort.dir/core/test.cpp.obj"
	cd /d D:\study\cpp\notebook\Util\build\Sort && E:\msys2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Sort/CMakeFiles/Sort.dir/core/test.cpp.obj -MF CMakeFiles\Sort.dir\core\test.cpp.obj.d -o CMakeFiles\Sort.dir\core\test.cpp.obj -c D:\study\cpp\notebook\Util\Sort\core\test.cpp

Sort/CMakeFiles/Sort.dir/core/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sort.dir/core/test.cpp.i"
	cd /d D:\study\cpp\notebook\Util\build\Sort && E:\msys2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\study\cpp\notebook\Util\Sort\core\test.cpp > CMakeFiles\Sort.dir\core\test.cpp.i

Sort/CMakeFiles/Sort.dir/core/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sort.dir/core/test.cpp.s"
	cd /d D:\study\cpp\notebook\Util\build\Sort && E:\msys2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\study\cpp\notebook\Util\Sort\core\test.cpp -o CMakeFiles\Sort.dir\core\test.cpp.s

# Object files for target Sort
Sort_OBJECTS = \
"CMakeFiles/Sort.dir/core/test.cpp.obj"

# External object files for target Sort
Sort_EXTERNAL_OBJECTS =

Sort/Sort.exe: Sort/CMakeFiles/Sort.dir/core/test.cpp.obj
Sort/Sort.exe: Sort/CMakeFiles/Sort.dir/build.make
Sort/Sort.exe: Sort/CMakeFiles/Sort.dir/linkLibs.rsp
Sort/Sort.exe: Sort/CMakeFiles/Sort.dir/objects1.rsp
Sort/Sort.exe: Sort/CMakeFiles/Sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\study\cpp\notebook\Util\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sort.exe"
	cd /d D:\study\cpp\notebook\Util\build\Sort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Sort/CMakeFiles/Sort.dir/build: Sort/Sort.exe
.PHONY : Sort/CMakeFiles/Sort.dir/build

Sort/CMakeFiles/Sort.dir/clean:
	cd /d D:\study\cpp\notebook\Util\build\Sort && $(CMAKE_COMMAND) -P CMakeFiles\Sort.dir\cmake_clean.cmake
.PHONY : Sort/CMakeFiles/Sort.dir/clean

Sort/CMakeFiles/Sort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\study\cpp\notebook\Util D:\study\cpp\notebook\Util\Sort D:\study\cpp\notebook\Util\build D:\study\cpp\notebook\Util\build\Sort D:\study\cpp\notebook\Util\build\Sort\CMakeFiles\Sort.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Sort/CMakeFiles/Sort.dir/depend


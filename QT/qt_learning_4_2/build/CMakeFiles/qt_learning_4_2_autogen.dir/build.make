# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = D:\ScoopApp\Scoop\apps\cmake\3.26.3\bin\cmake.exe

# The command to remove a file.
RM = D:\ScoopApp\Scoop\apps\cmake\3.26.3\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\admin\code\QT\qt_learning_4_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\admin\code\QT\qt_learning_4_2\build

# Utility rule file for qt_learning_4_2_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/qt_learning_4_2_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/qt_learning_4_2_autogen.dir/progress.make

CMakeFiles/qt_learning_4_2_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\admin\code\QT\qt_learning_4_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target qt_learning_4_2"
	D:\ScoopApp\Scoop\apps\cmake\3.26.3\bin\cmake.exe -E cmake_autogen C:/Users/admin/code/QT/qt_learning_4_2/build/CMakeFiles/qt_learning_4_2_autogen.dir/AutogenInfo.json Debug

qt_learning_4_2_autogen: CMakeFiles/qt_learning_4_2_autogen
qt_learning_4_2_autogen: CMakeFiles/qt_learning_4_2_autogen.dir/build.make
.PHONY : qt_learning_4_2_autogen

# Rule to build all files generated by this target.
CMakeFiles/qt_learning_4_2_autogen.dir/build: qt_learning_4_2_autogen
.PHONY : CMakeFiles/qt_learning_4_2_autogen.dir/build

CMakeFiles/qt_learning_4_2_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\qt_learning_4_2_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/qt_learning_4_2_autogen.dir/clean

CMakeFiles/qt_learning_4_2_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\admin\code\QT\qt_learning_4_2 C:\Users\admin\code\QT\qt_learning_4_2 C:\Users\admin\code\QT\qt_learning_4_2\build C:\Users\admin\code\QT\qt_learning_4_2\build C:\Users\admin\code\QT\qt_learning_4_2\build\CMakeFiles\qt_learning_4_2_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qt_learning_4_2_autogen.dir/depend

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
CMAKE_SOURCE_DIR = C:\Users\zhu14\code\QT\qt_learning_2_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zhu14\code\QT\qt_learning_2_2\build

# Utility rule file for MainWindow_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/MainWindow_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MainWindow_autogen.dir/progress.make

CMakeFiles/MainWindow_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\zhu14\code\QT\qt_learning_2_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MainWindow"
	D:\ScoopApp\Scoop\apps\cmake\3.26.3\bin\cmake.exe -E cmake_autogen C:/Users/zhu14/code/QT/qt_learning_2_2/build/CMakeFiles/MainWindow_autogen.dir/AutogenInfo.json Debug

MainWindow_autogen: CMakeFiles/MainWindow_autogen
MainWindow_autogen: CMakeFiles/MainWindow_autogen.dir/build.make
.PHONY : MainWindow_autogen

# Rule to build all files generated by this target.
CMakeFiles/MainWindow_autogen.dir/build: MainWindow_autogen
.PHONY : CMakeFiles/MainWindow_autogen.dir/build

CMakeFiles/MainWindow_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MainWindow_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MainWindow_autogen.dir/clean

CMakeFiles/MainWindow_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zhu14\code\QT\qt_learning_2_2 C:\Users\zhu14\code\QT\qt_learning_2_2 C:\Users\zhu14\code\QT\qt_learning_2_2\build C:\Users\zhu14\code\QT\qt_learning_2_2\build C:\Users\zhu14\code\QT\qt_learning_2_2\build\CMakeFiles\MainWindow_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MainWindow_autogen.dir/depend


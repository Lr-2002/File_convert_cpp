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
CMAKE_COMMAND = /home/lr-2002/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lr-2002/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lr-2002/code/File_convert_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lr-2002/code/File_convert_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opencv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv.dir/flags.make

CMakeFiles/opencv.dir/cal_image.cpp.o: CMakeFiles/opencv.dir/flags.make
CMakeFiles/opencv.dir/cal_image.cpp.o: ../cal_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lr-2002/code/File_convert_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv.dir/cal_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv.dir/cal_image.cpp.o -c /home/lr-2002/code/File_convert_cpp/cal_image.cpp

CMakeFiles/opencv.dir/cal_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv.dir/cal_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lr-2002/code/File_convert_cpp/cal_image.cpp > CMakeFiles/opencv.dir/cal_image.cpp.i

CMakeFiles/opencv.dir/cal_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv.dir/cal_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lr-2002/code/File_convert_cpp/cal_image.cpp -o CMakeFiles/opencv.dir/cal_image.cpp.s

# Object files for target opencv
opencv_OBJECTS = \
"CMakeFiles/opencv.dir/cal_image.cpp.o"

# External object files for target opencv
opencv_EXTERNAL_OBJECTS =

opencv: CMakeFiles/opencv.dir/cal_image.cpp.o
opencv: CMakeFiles/opencv.dir/build.make
opencv: /usr/local/lib/libopencv_highgui.so.3.4.14
opencv: /usr/local/lib/libopencv_objdetect.so.3.4.14
opencv: /usr/local/lib/libopencv_stitching.so.3.4.14
opencv: /usr/local/lib/libopencv_superres.so.3.4.14
opencv: /usr/local/lib/libopencv_videostab.so.3.4.14
opencv: /usr/local/lib/libopencv_freetype.so.3.4.14
opencv: /usr/local/lib/libopencv_hdf.so.3.4.14
opencv: /usr/local/lib/libopencv_optflow.so.3.4.14
opencv: /usr/local/lib/libopencv_stereo.so.3.4.14
opencv: /usr/local/lib/libopencv_xfeatures2d.so.3.4.14
opencv: /usr/local/lib/libopencv_ximgproc.so.3.4.14
opencv: /usr/local/lib/libopencv_ml.so.3.4.14
opencv: /usr/local/lib/libopencv_photo.so.3.4.14
opencv: /usr/local/lib/libopencv_videoio.so.3.4.14
opencv: /usr/local/lib/libopencv_video.so.3.4.14
opencv: /usr/local/lib/libopencv_imgcodecs.so.3.4.14
opencv: /usr/local/lib/libopencv_calib3d.so.3.4.14
opencv: /usr/local/lib/libopencv_features2d.so.3.4.14
opencv: /usr/local/lib/libopencv_flann.so.3.4.14
opencv: /usr/local/lib/libopencv_imgproc.so.3.4.14
opencv: /usr/local/lib/libopencv_core.so.3.4.14
opencv: CMakeFiles/opencv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lr-2002/code/File_convert_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opencv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv.dir/build: opencv

.PHONY : CMakeFiles/opencv.dir/build

CMakeFiles/opencv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv.dir/clean

CMakeFiles/opencv.dir/depend:
	cd /home/lr-2002/code/File_convert_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lr-2002/code/File_convert_cpp /home/lr-2002/code/File_convert_cpp /home/lr-2002/code/File_convert_cpp/cmake-build-debug /home/lr-2002/code/File_convert_cpp/cmake-build-debug /home/lr-2002/code/File_convert_cpp/cmake-build-debug/CMakeFiles/opencv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv.dir/depend


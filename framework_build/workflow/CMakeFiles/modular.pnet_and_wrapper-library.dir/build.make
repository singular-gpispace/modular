# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1276/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1276/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build

# Utility rule file for modular.pnet_and_wrapper-library.

# Include any custom commands dependencies for this target.
include workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/compiler_depend.make

# Include the progress variables for this target.
include workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/progress.make

workflow/CMakeFiles/modular.pnet_and_wrapper-library: gen_modular.pnet/pnetc/op/libsingular_modular.so
workflow/CMakeFiles/modular.pnet_and_wrapper-library: modular.pnet

modular.pnet: /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/modular.xpnet
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../modular.pnet, ../gen_modular.pnet/pnetc/op/libsingular_modular.so"
	cd /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/workflow && /home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/bin/pnetc --gen-cxxflags=-O3 --gen-cxxflags=-std=c++17 --gen-cxxflags=-I"/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build" --gen-cxxflags=-I"/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5" --gen-cxxflags=-I"/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/src" --gen-cxxflags=-I"/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/include" --gen-cxxflags=-I"/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/external/boost/include" --gen-ldflags="-L/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build" --gen-ldflags="-L/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/src/util-generic" --gen-ldflags="-Wl,-rpath='\$$\$$ORIGIN'" --gen-ldflags="-Wl,-rpath='/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib'" --gen-ldflags="-Wl,-rpath='/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/external/boost/lib'" --force-overwrite-file=true --input="/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/modular.xpnet" --output="/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/modular.pnet" --path-to-cpp="/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/gen_modular.pnet" --Wbackup-file=OFF --Woverwrite-file=OFF && make -C /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/gen_modular.pnet

gen_modular.pnet/pnetc/op/libsingular_modular.so: modular.pnet
	@$(CMAKE_COMMAND) -E touch_nocreate gen_modular.pnet/pnetc/op/libsingular_modular.so

modular.pnet_and_wrapper-library: gen_modular.pnet/pnetc/op/libsingular_modular.so
modular.pnet_and_wrapper-library: modular.pnet
modular.pnet_and_wrapper-library: workflow/CMakeFiles/modular.pnet_and_wrapper-library
modular.pnet_and_wrapper-library: workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/build.make
.PHONY : modular.pnet_and_wrapper-library

# Rule to build all files generated by this target.
workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/build: modular.pnet_and_wrapper-library
.PHONY : workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/build

workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/clean:
	cd /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/workflow && $(CMAKE_COMMAND) -P CMakeFiles/modular.pnet_and_wrapper-library.dir/cmake_clean.cmake
.PHONY : workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/clean

workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/depend:
	cd /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5 /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/workflow /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : workflow/CMakeFiles/modular.pnet_and_wrapper-library.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cheyh/projs/pi0_wrt/i2c_1in3_oled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build

# Include any dependencies generated for this target.
include CMakeFiles/wrt_info.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wrt_info.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wrt_info.dir/flags.make

CMakeFiles/wrt_info.dir/src/main.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/wrt_info.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/src/main.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/src/main.c

CMakeFiles/wrt_info.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/src/main.c > CMakeFiles/wrt_info.dir/src/main.c.i

CMakeFiles/wrt_info.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/src/main.c -o CMakeFiles/wrt_info.dir/src/main.c.s

CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.o: ../lib/Config/DEV_Config.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Config/DEV_Config.c

CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Config/DEV_Config.c > CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.i

CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Config/DEV_Config.c -o CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.s

CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.o: ../lib/Fonts/font12.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font12.c

CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font12.c > CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.i

CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font12.c -o CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.s

CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.o: ../lib/Fonts/font16.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font16.c

CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font16.c > CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.i

CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font16.c -o CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.s

CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.o: ../lib/Fonts/font20.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font20.c

CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font20.c > CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.i

CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font20.c -o CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.s

CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.o: ../lib/Fonts/font24.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font24.c

CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font24.c > CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.i

CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font24.c -o CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.s

CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.o: ../lib/Fonts/font8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font8.c

CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font8.c > CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.i

CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/Fonts/font8.c -o CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.s

CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.o: ../lib/OLED/OLED_Driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/OLED/OLED_Driver.c

CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/OLED/OLED_Driver.c > CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.i

CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/OLED/OLED_Driver.c -o CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.s

CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.o: ../lib/OLED/OLED_GUI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/OLED/OLED_GUI.c

CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/OLED/OLED_GUI.c > CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.i

CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/lib/OLED/OLED_GUI.c -o CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.s

CMakeFiles/wrt_info.dir/src/network.c.o: CMakeFiles/wrt_info.dir/flags.make
CMakeFiles/wrt_info.dir/src/network.c.o: ../src/network.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/wrt_info.dir/src/network.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wrt_info.dir/src/network.c.o -c /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/src/network.c

CMakeFiles/wrt_info.dir/src/network.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wrt_info.dir/src/network.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/src/network.c > CMakeFiles/wrt_info.dir/src/network.c.i

CMakeFiles/wrt_info.dir/src/network.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wrt_info.dir/src/network.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/src/network.c -o CMakeFiles/wrt_info.dir/src/network.c.s

# Object files for target wrt_info
wrt_info_OBJECTS = \
"CMakeFiles/wrt_info.dir/src/main.c.o" \
"CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.o" \
"CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.o" \
"CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.o" \
"CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.o" \
"CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.o" \
"CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.o" \
"CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.o" \
"CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.o" \
"CMakeFiles/wrt_info.dir/src/network.c.o"

# External object files for target wrt_info
wrt_info_EXTERNAL_OBJECTS =

wrt_info: CMakeFiles/wrt_info.dir/src/main.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/Config/DEV_Config.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/Fonts/font12.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/Fonts/font16.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/Fonts/font20.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/Fonts/font24.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/Fonts/font8.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/OLED/OLED_Driver.c.o
wrt_info: CMakeFiles/wrt_info.dir/lib/OLED/OLED_GUI.c.o
wrt_info: CMakeFiles/wrt_info.dir/src/network.c.o
wrt_info: CMakeFiles/wrt_info.dir/build.make
wrt_info: CMakeFiles/wrt_info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable wrt_info"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wrt_info.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wrt_info.dir/build: wrt_info

.PHONY : CMakeFiles/wrt_info.dir/build

CMakeFiles/wrt_info.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wrt_info.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wrt_info.dir/clean

CMakeFiles/wrt_info.dir/depend:
	cd /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cheyh/projs/pi0_wrt/i2c_1in3_oled /home/cheyh/projs/pi0_wrt/i2c_1in3_oled /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build /home/cheyh/projs/pi0_wrt/i2c_1in3_oled/build/CMakeFiles/wrt_info.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wrt_info.dir/depend


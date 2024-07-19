cmake_minimum_required(VERSION 3.16)
project(OPI0-wrt_info C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,--gc-sections -g -O -ffunction-sections -fdata-sections -Wall -DUSE_WIRINGPI_LIB -DRPI")

file(GLOB_RECURSE C_LIB_SRCS ${PROJECT_SOURCE_DIR}/lib/*.c)
file(GLOB_RECURSE C_PROJ_SRCS ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(wrt_info ${PROJECT_SOURCE_DIR}/src/main.c)
target_sources(wrt_info PRIVATE ${C_LIB_SRCS} ${C_PROJ_SRCS})
target_include_directories(wrt_info PRIVATE
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/lib/Fonts
)
target_link_libraries(wrt_info wiringPi)

install(TARGETS wrt_info DESTINATION .)
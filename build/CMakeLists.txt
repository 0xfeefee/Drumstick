##
## Drumstick build
##
cmake_minimum_required(VERSION 3.20)
project(Drumstick
	VERSION   0.1.0
	LANGUAGES C CXX
)

## Basic configuration and variables:
set(CMAKE_C_STANDARD   20)
set(CMAKE_CXX_STANDARD 20)
set(SRC 			   "${CMAKE_CURRENT_LIST_DIR}/../src")

## Check release mode:
if (CMAKE_BUILD_TYPE MATCHES Debug)
	add_compile_definitions(PROJECT_BUILD_DEBUG=1)
else()
	add_compile_definitions(PROJECT_BUILD_RELEASE=1)
endif()

## Set compiler options:
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS_DEBUG 	"-Wall -Werror")
	set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra")
endif()


## Add info string:
set(INFO_STRING
	"${CMAKE_PROJECT_NAME} v${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} (${CMAKE_BUILD_TYPE})"
)

add_executable(Drumstick
	${SRC}/base.pch.cpp
	${SRC}/main.cpp
	${SRC}/Data.cpp
	${SRC}/File_Header.cpp
)

target_include_directories(Drumstick
	PUBLIC
	.
	${SRC}
)

target_precompile_headers(Drumstick
	PUBLIC
	${SRC}/base.pch.hpp
)

if (WIN32)
	target_compile_definitions(${PROJECT_NAME}
		PRIVATE
		PROJECT_PLATFORM_WIN64
	)
endif()

target_compile_definitions(${PROJECT_NAME}
	PRIVATE
	PROJECT_NAME="${PROJECT_NAME}"
	PROJECT_INFO_STRING="${INFO_STRING}"
)

message(NOTICE "${CMAKE_CXX_COMPILER_ID}")

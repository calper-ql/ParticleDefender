cmake_minimum_required(VERSION 3.5)

PROJECT(MOTION_DEFENDER)

INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 14)

set(SOURCES 
	src/ansi_codes.cc 
	src/file_loader.cc 
	src/status_logger.cc 
	src/shader_loader.cc 
	src/shader_program.cc 
	src/particle_drawer.cc 
	src/particles.pb.cc
	src/particle_request.cc
	src/tcp_client.cc
	)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/GL_CODE
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

message(STATUS "COPIED GL SRC")

set(LIBS ${OpenCL_LIBRARY} ${OPENGL_LIBRARIES} glfw ${PROTOBUF_LIBRARY})

add_executable(test_v1 src/test_v1.cc ${SOURCES})
target_link_libraries(test_v1 ${LIBS} )

add_executable(test_v2 src/test_v2.cc ${SOURCES})
target_link_libraries(test_v2 ${LIBS})

add_executable(test_v3 src/test_v3.cc ${SOURCES})
target_link_libraries(test_v3 ${LIBS})

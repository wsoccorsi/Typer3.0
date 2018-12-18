cmake_minimum_required(VERSION 3.12)
project(typer3.0_she_didn't_work_so_good_mr_stark)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-deprecated")

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES} AbstractSpaceObject.cpp AbstractSpaceObject.h Position.cpp Position.h Asteroid.cpp Asteroid.h Laser.cpp Laser.h Player.cpp Player.h Sentence.cpp Sentence.h PlayerInterface.cpp PlayerInterface.h)

target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
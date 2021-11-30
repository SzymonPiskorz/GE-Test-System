CXX			:= g++
CXXFLAGS 	:= -std=c++11 -Wall -Wextra -Werror -g -I.

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

BUILD_DIR	:= ./bin
SRC_DIR		:= ./src

include		:= "C:/msys64/mingw64/include/cppunit"

SRC			:= ./src/*.cpp

all			:= build

build:
	@echo ${MSG_START}
	${CXX} -o MainFile ${SRC} -I${include} -I. -I./include
	@echo ${MSG_END}
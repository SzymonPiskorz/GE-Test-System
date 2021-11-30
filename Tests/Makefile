CXX			:= g++
CXXFLAGS 	:= -std=c++11 -Wall -Wextra -Werror -g -I.

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

BUILD_DIR	:= ./bin
SRC_DIR		:= ./src

include		:= "C:/msys64/mingw64/include/cppunit"
include1	:= "C:/msys64/mingw64/include/cppunit/ui/text"
lib			:= "C:/msys64/mingw64/lib"

SRC			:= ./Src/*.cpp ../Production/src/Lottery.cpp

all			:= build

build:
	@echo ${MSG_START}
	${CXX} -o TestFile ${SRC} -I${include} -I${include1} -I. -I./include -L${lib} -lmingw32 -llibcppunit
	@echo ${MSG_END}
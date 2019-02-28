SHELL:=/bin/bash

#passed in variables
VERSION:=local
BUILD_TYPE:=debug

#compiler variables
OS:=$(shell uname)
ifeq ($(OS), Darwin)
CXX:=clang++
LIB_EXT:=dylib
JNI_MD:=darwin
else
CXX:=g++
LIB_EXT:=so
JNI_MD:=linux
endif

ifeq ($(BUILD_TYPE), release)
CXXFLAGS:=--std=c++1y -Wall -O2 -fPIC
endif
ifeq ($(BUILD_TYPE), debug)
CXXFLAGS:=--std=c++1y -Wall -g -fPIC
endif

INC:=-I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/$(JNI_MD)/
SRC:=$(shell find `pwd`/src/main/cpp/ -name '*.cpp')
OBJ:=$(patsubst %.cpp, %.o, $(SRC))

STATIC_LIB_DEP:=

TMP_DIR:=target
OBJ_DIR:=$(TMP_DIR)/obj
RESOURCE_DIR:=src/main/resources
SHARED_LIB:=$(TMP_DIR)/liboffheapmap.$(LIB_EXT)

default: |lib 
	@mvn -Dversion=$(VERSION) install

lib: |dir $(OBJ)
	@$(CXX) -shared -o $(SHARED_LIB) $(OBJ_DIR)/*.o
	@mv $(SHARED_LIB) $(RESOURCE_DIR)/

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $(INC) $(INC) $< -o $@
	@cp $@ $(OBJ_DIR)/

dir:
	@mkdir -p $(TMP_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@for i in `find . -iname "*.o"`; do rm $$i; done;
	@rm -rf $(TMP_DIR)

VPATH = ../include/cs223:../src
CXX = clang++
CPPFLAGS = -I ../include/cs223
CXXFLAGS = -O3
LDLIBS = -lstdc++ -lm

all: uhftest llhttest

uhftest: uhftest.o UniversalHashFamily.o
llhttest: llhttest.o UniversalHashFamily.o HashTable.o LowLevelHashTable.o

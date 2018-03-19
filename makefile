#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`


CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall -fexceptions -std=c++11 
LINKFLAGS = -lcppunit
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

MEMCHECK_RESULTS = memcheck.out

INC_DEBUG = $(INC) -Iinclude -Irapidxml
CFLAGS_DEBUG = $(CFLAGS) -std=c++11 -g 
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = project/bbcAdventureDebug

INC_RELEASE = $(INC) -Iinclude
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = project/bbcAdventure

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/Console.o $(OBJDIR_DEBUG)/src/main.o $(OBJDIR_DEBUG)/src/Room.o $(OBJDIR_DEBUG)/src/Option.o $(OBJDIR_DEBUG)/src/Npc.o $(OBJDIR_DEBUG)/src/Map.o $(OBJDIR_DEBUG)/src/Item.o $(OBJDIR_DEBUG)/src/Inventory.o $(OBJDIR_DEBUG)/src/Direction.o $(OBJDIR_DEBUG)/src/Action.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/Console.o $(OBJDIR_RELEASE)/src/main.o $(OBJDIR_RELEASE)/src/Room.o $(OBJDIR_RELEASE)/src/Option.o $(OBJDIR_RELEASE)/src/Npc.o $(OBJDIR_RELEASE)/src/Map.o $(OBJDIR_RELEASE)/src/Item.o $(OBJDIR_RELEASE)/src/Inventory.o $(OBJDIR_RELEASE)/src/Direction.o $(OBJDIR_RELEASE)/src/Action.o

all: debug release

clean: clean_debug clean_release clean_test

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src

after_debug: 

SRC_DIR = src
TEST_DIR = test
SRC_INCLUDE = include 
TEST_INCLUDE = include/test 
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}
TEST_CPP_FILES = src/Room.cpp src/Item.cpp src/Npc.cpp

GCOV = gcov 
LCOV = lcov 
COVERAGE_RESULTS = results.coverage 
COVERAGE_DIR = coverage

PROGRAM_TEST = testGame

$(PROGRAM_TEST): 
	$(CXX) $(CFLAGS) $(TEST_DIR)/*.cpp $(TEST_CPP_FILES) -o $(PROGRAM_TEST) $(INCLUDE) $(LINKFLAGS) 
	./$(PROGRAM_TEST)

clean_test: 
	rm -f testGame
	

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/src/Console.o: src/Console.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Console.cpp -o $(OBJDIR_DEBUG)/src/Console.o

$(OBJDIR_DEBUG)/src/main.o: src/main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/main.cpp -o $(OBJDIR_DEBUG)/src/main.o

$(OBJDIR_DEBUG)/src/Room.o: src/Room.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Room.cpp -o $(OBJDIR_DEBUG)/src/Room.o

$(OBJDIR_DEBUG)/src/Option.o: src/Option.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Option.cpp -o $(OBJDIR_DEBUG)/src/Option.o

$(OBJDIR_DEBUG)/src/Npc.o: src/Npc.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Npc.cpp -o $(OBJDIR_DEBUG)/src/Npc.o

$(OBJDIR_DEBUG)/src/Map.o: src/Map.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Map.cpp -o $(OBJDIR_DEBUG)/src/Map.o

$(OBJDIR_DEBUG)/src/Item.o: src/Item.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Item.cpp -o $(OBJDIR_DEBUG)/src/Item.o

$(OBJDIR_DEBUG)/src/Inventory.o: src/Inventory.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Inventory.cpp -o $(OBJDIR_DEBUG)/src/Inventory.o

$(OBJDIR_DEBUG)/src/Direction.o: src/Direction.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Direction.cpp -o $(OBJDIR_DEBUG)/src/Direction.o

$(OBJDIR_DEBUG)/src/Action.o: src/Action.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Action.cpp -o $(OBJDIR_DEBUG)/src/Action.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/src/Console.o: src/Console.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Console.cpp -o $(OBJDIR_RELEASE)/src/Console.o

$(OBJDIR_RELEASE)/src/main.o: src/main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/main.cpp -o $(OBJDIR_RELEASE)/src/main.o

$(OBJDIR_RELEASE)/src/Room.o: src/Room.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Room.cpp -o $(OBJDIR_RELEASE)/src/Room.o

$(OBJDIR_RELEASE)/src/Option.o: src/Option.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Option.cpp -o $(OBJDIR_RELEASE)/src/Option.o

$(OBJDIR_RELEASE)/src/Npc.o: src/Npc.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Npc.cpp -o $(OBJDIR_RELEASE)/src/Npc.o

$(OBJDIR_RELEASE)/src/Map.o: src/Map.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Map.cpp -o $(OBJDIR_RELEASE)/src/Map.o

$(OBJDIR_RELEASE)/src/Item.o: src/Item.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Item.cpp -o $(OBJDIR_RELEASE)/src/Item.o

$(OBJDIR_RELEASE)/src/Inventory.o: src/Inventory.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Inventory.cpp -o $(OBJDIR_RELEASE)/src/Inventory.o

$(OBJDIR_RELEASE)/src/Direction.o: src/Direction.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Direction.cpp -o $(OBJDIR_RELEASE)/src/Direction.o

$(OBJDIR_RELEASE)/src/Action.o: src/Action.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Action.cpp -o $(OBJDIR_RELEASE)/src/Action.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src
	rm -rf $(MEMCHECK_RESULTS)

memcheck: $(OUT_RELEASE)
	valgrind --tool=memcheck --leak-check=yes --log-file=$(MEMCHECK_RESULTS) $(OUT_RELEASE)


.PHONY: before_debug after_debug clean_debug before_release after_release clean_release


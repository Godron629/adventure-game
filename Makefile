CXX=g++
CXXFLAGS= -std=c++0x -g -fprofile-arcs -ftest-coverage

LINKFLAGS= -lcppunit

SRC_DIR = src

TEST_DIR = test

SRC_INCLUDE = include
TEST_INCLUDE = include/test
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

MEMCHECK_RESULTS = memcheck.xml

PROGRAM_TEST = testShapes

.PHONY: all
all: $(PROGRAM_TEST) coverage docs

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o *.gcov *.gcda *.gcno $(COVERAGE_RESULTS) $(PROGRAM_TEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)


.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM) $(PROGRAM_TEST)

$(PROGRAM_TEST):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)
	$(PROGRAM_TEST)

memcheck-test: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM_TEST)

coverage: $(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/src/*" -o $(COVERAGE_RESULTS)
	#Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	#Remove all of the generated files from gcov
	rm -f *.gc*

docs: ${SRC_INCLUDE}
	doxygen doxyfile

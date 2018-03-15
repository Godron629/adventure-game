CXX=g++
CXXFLAGS= -std=c++0x -g 

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

CXX = g++
CXXFLAGS = -g -Wall

OBJS = complex.o compNum.o


compNum: $(OBJS)
	$(CXX) $(CXXFLAGS) -o compNum $(OBJS)

compNum.o: compNum.cpp complex.hpp
	$(CXX) $(CXXFLAGS) -c compNum.cpp complex.o

complex.o: complex.cpp complex.hpp doubleCheck.hpp
	$(CXX) $(CXXFLAGS) -c complex.cpp


.PHONY: clean 

clean:
	$(RM) $(OBJS)


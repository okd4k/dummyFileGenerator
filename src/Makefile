CXX = g++
CXXFLAGS = -Wall -g

fileGenerator: fileGenerator.o
	$(CXX) $(CXXFLAGS) -o fileGenerator fileGenerator.o

fileGenerator.o: fileGenerator.cc 
	$(CXX) $(CXXFLAGS) -c fileGenerator.cc


all: fileGenerator

clean:
	rm fileGenerator.o fileGenerator
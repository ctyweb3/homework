CXX = g++
CXXFLAGS = -Wall -std=c++11

SOURCES = main.cpp Package.cpp TwoDayPackage.cpp OvernightPackage.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = package_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean 
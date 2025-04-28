CXX = g++
CXXFLAGS = -Wall -std=c++11

SOURCES = main.cpp Account.cpp SavingsAccount.cpp CheckingAccount.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = banking_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean 
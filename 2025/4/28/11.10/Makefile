CXX = g++
CXXFLAGS = -std=c++11 -Wall

SOURCES = Account.cpp SavingsAccount.cpp CheckingAccount.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = bank_app

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean 
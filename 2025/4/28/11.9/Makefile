CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Package.cpp TwoDayPackage.cpp OvernightPackage.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = package_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iestruturas
LDFLAGS =

SOURCES = test.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /f /q $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean

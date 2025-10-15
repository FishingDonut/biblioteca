CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iestruturas
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
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean

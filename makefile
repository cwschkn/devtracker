CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -g
INCLUDES = -I include

.PHONY: all main test run-main run-test clean

all: main test

main:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/main.cpp -o build/devtracker

test:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(INCLUDES) tests/test.cpp -o build/test

run-main: main
	./build/devtracker

run-test: test
	./build/test

clean:
	rm -rf build
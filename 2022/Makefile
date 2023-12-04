# the compiler: gcc for C program, define as g++ for C++
CC=clang++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS=-O3 -Wall -std=c++17 -lgmpxx -lgmp

# The build target 
TARGET=aoc11

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)

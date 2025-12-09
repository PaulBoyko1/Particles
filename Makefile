CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp Engine.cpp Matrices.cpp Particle.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
  $(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
  $(CXX) $(CXXFLAGS) -c $<

clean:
  rm -f $(OBJ) $(TARGET)

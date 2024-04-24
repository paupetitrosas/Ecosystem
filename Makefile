# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -L/usr/X11R6/lib -lm -lpthread -lX11 -lboost_iostreams -L/usr/include/boost

# Source files
SRCS := main.cpp foodchain.cpp utilities.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable
TARGET := myprogram

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS)

# Object file rule
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
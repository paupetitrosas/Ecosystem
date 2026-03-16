CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic
LDFLAGS :=
LDLIBS := -lX11 -lpthread -lm -lboost_iostreams

SRCS := main.cpp foodchain.cpp utilities.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := ecosystem

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

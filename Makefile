TARGET=template

all:$(TARGET)

$(TARGET):*.cpp
	g++ -std=c++0x -g $< -o $@
	
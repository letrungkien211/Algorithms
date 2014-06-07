CC = g++ -g
RM = rm -rf

LIBS = #-lglut -lGL -lGLU -lm -lpthread 

TARGET = a
OBJ = 
all: $(TARGET)

.cpp.o:
	$(CC) -c $< $(LIBS)

$(TARGET): %: %.o $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

clean:
	$(RM) *.o $(TARGET) *~ *#*
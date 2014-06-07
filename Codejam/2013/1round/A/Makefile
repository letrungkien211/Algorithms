CC = g++ -g
RM = rm -rf
MV = mv


TARGET = a
all: $(TARGET)

.cpp.o:
	$(CC) -c $< $(LIBS)

$(TARGET): %: %.o
	$(CC) -o $@ $^ 

clean:
	$(RM) *.o $(TARGET) *~ *#*

small:
	$(MV) ~/Downloads/A-small-attempt.in .

large:
	$(MV) ~/Downloads/A-large.in .
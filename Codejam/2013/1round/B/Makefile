CC = g++ -g
RM = rm -rf
MV = mv


TARGET = b
all: $(TARGET)

.cpp.o:
	$(CC) -c $< $(LIBS)

$(TARGET): %: %.o
	$(CC) -o $@ $^ 

clean:
	$(RM) *.o $(TARGET) *~ *#*

small:
	$(MV) ~/Downloads/B-small-attempt.in .

large:
	$(MV) ~/Downloads/B-large.in .
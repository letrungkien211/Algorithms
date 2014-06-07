CC = g++ -g
RM = rm -rf
MV = mv


TCRGET = a
all: $(TARGET)

.cpp.o:
	$(CC) -c $< $(LIBS)

$(TARGET): %: %.o
	$(CC) -o $@ $^ 

clean:
	$(RM) *.o $(TARGET) *~ *#*

small:
	$(MV) ~/Downloads/C-small-attempt.in .

large:
	$(MV) ~/Downloads/C-large.in .
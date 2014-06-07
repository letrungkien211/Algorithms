all: a.out b.out c.out
CC = g++ --std=c++11


a.out: a.cpp
	$(CC) a.cpp -o a.out
b.out: b.cpp
	$(CC) b.cpp -o b.out
c.out: c.cpp
	$(CC) c.cpp -o c.out

clean:
	rm *.out *~

CC =	g++
PROG =	bufferTester

$(PROG):	main.o kbBuffer.o
	$(CC) main.o kbBuffer.o -o $(PROG)

main.o: main.cpp
	$(CC) -c main.cpp

kbBuffer.o:	kbBuffer.cpp
	$(CC) -c kbBuffer.cpp

clean:	
	rm *.o
	rm $(PROG)

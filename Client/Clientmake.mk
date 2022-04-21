CC = g++
CFLAGS = -g -Wall

client: Driver.o Datalink.o
	$(CC) $(CFLAGS) Driver.o Datalink.o -o client

Driver.o: Driver.cpp Driver.h
	$(CC) $(CFLAGS) -c Driver.cpp

Dataink.o: Datalink.cpp Datalink.h
	$(CC) $(CFLAGS) -c Datalink.cpp

clean:
	rm *.o client

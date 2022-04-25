CC = g++
CFLAGS = -g -Wall

client: Driver.o Datalink.o mockTransport.o
	$(CC) $(CFLAGS) Driver.o Datalink.o mockTransport.o -o client

Driver.o: Driver.cpp Driver.h
	$(CC) $(CFLAGS) -c Driver.cpp

Dataink.o: Datalink.cpp Datalink.h
	$(CC) $(CFLAGS) -c Datalink.cpp

mockTransport.o: mockTransport.cpp
	$(CC) $(CFLAGS) -c mockTransport.cpp

clean:
	rm *.o client

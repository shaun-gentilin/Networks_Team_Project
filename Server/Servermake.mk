CC = g++
CFLAGS = -g -Wall

server: Driver.o Datalink.o Transport.o AppServer.o
	$(CC) $(CFLAGS) Driver.o Datalink.o Transport.o AppServer.o -o server

Driver.o: Driver.cpp Driver.h
	$(CC) $(CFLAGS) -c Driver.cpp

Dataink.o: Datalink.cpp Datalink.h
	$(CC) $(CFLAGS) -c Datalink.cpp

Transport.o: Transport.cpp Transport.h
	$(CC) $(CFLAGS) -c Transport.cpp

AppServer.o: AppServer.cpp
	$(CC) $(CFLAGS) -c AppServer.cpp

clean:
	rm *.o

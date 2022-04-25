CC = g++
CFLAGS = -g -Wall

client: Driver.o Datalink.o Transport.o AppClient.o
	$(CC) $(CFLAGS) Driver.o Datalink.o Transport.o AppClient.o -o client

Driver.o: Driver.cpp Driver.h
	$(CC) $(CFLAGS) -c Driver.cpp

Dataink.o: Datalink.cpp Datalink.h
	$(CC) $(CFLAGS) -c Datalink.cpp

Transport.o: Transport.cpp Transport.h
	$(CC) $(CFLAGS) -c Transport.cpp

AppClient.o: AppClient.cpp
	$(CC) $(CFLAGS) -c AppClient.cpp

clean:
	rm *.o client

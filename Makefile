
CC=clang
CFLAGS= -g -Wall -D_GNU_SOURCE
LFLAGS= -lcurl
# -g add debuggig information to output
# -Wall turn on most warnings

TARGET = pub_ip

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LFLAGS)

clean:
	rm -f *.o
	echo make cleanup done!


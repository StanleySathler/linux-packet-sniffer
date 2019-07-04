# Compiler
CC = /usr/bin/gcc

# Binary output
PROG = bin/packet_sniffer

# Objects that must be compiled
OBJS = src/main.o

# Watched files
WATCH = $(OBJS) src/socket/socket.h src/ip/parser.h

# Compiler flags
CFLAGS = -Wall

# Sources and headers
SRCS = src/main.c
HDRS = src/socket/socket.h

# Rebuild the executable file
rebuild: clean build

# Build the executable file
build: $(WATCH)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

# Run the binary file
exec: $(PROG)
	sudo $(PROG)

# Clean all generated files
clean:
	rm -f **/*.o

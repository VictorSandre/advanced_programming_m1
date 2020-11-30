CC=g++ 
VERSION=-std=c++17
TARGET=runme 
SOURCES=laClasse.cpp
CFLAGS=-O3
LFLAGS=-lm

OBJSC=$(SOURCES:.c=.o)
OBJS=$(OBJSC:.cpp=.o)

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(VERSION) $(LFLAGS) $(OBJS) -o $(TARGET)

purge: clean
	rm -f $(TARGET)

clean:
	rm -f *.o


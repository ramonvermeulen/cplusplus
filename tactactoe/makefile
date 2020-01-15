CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=./sources/main.cpp \
				./sources/Game.cpp \
				./sources/GameRunner.cpp \
				./sources/CManager.cpp 
        # Command.cpp \
				# CommandManager.cpp \
				# MakePlay.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.exe
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm ./sources/*.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)
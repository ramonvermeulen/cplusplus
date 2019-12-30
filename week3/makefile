CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
SOURCES=main.cpp \
        DataProviderJson.cpp \
				Drawable.cpp \
				DrawableFactory.cpp \
				Rectangle.cpp \
				Line.cpp \
				Circle.cpp \
				Constants.cpp \
				Image.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.exe
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm *.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)
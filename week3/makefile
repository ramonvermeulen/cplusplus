# OBJS = ${wildcard *.o}
# HEADERS = ${wildcard *.hpp}
# SOURCES = ${wildcard *.cpp}

# GXX := g++ -std=c++17
# LIBS := -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp

# # comment me out on first `make` run
# main: ${OBJS}
# 	${GXX} -o main.exe ${OBJS} ${LIBS}

# main.o: ${HEADERS}
# 	${GXX} -c ${SOURCES}

# clean:
# 	rm main.exe ${OBJS}


CC=g++
CFLAGS=-c -Wall -std=c++11 
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
SOURCES=main.cpp DataProviderJson.cpp Drawable.cpp DrawableFactory.cpp Rectangle.cpp Line.cpp Circle.cpp Constants.cpp
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
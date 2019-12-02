OBJS = ${wildcard *.o}
HEADERS = ${wildcard *.hpp}
SOURCES = ${wildcard *.cpp}

GXX := g++ -std=c++17
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp

# comment me out on first `make` run
main: ${OBJS}
	${GXX} -o main.exe ${OBJS} ${LIBS}

main.o: ${HEADERS}
	${GXX} -c ${SOURCES}

clean:
	rm main.exe ${OBJS}

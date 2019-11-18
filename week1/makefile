IMPLEMENTATION_FILES := *.cpp
OBJECT_FILES := *.o

main: ${OBJECT_FILES} # linking
	g++ ${OBJECT_FILES} -o main -lsfml-graphics -lsfml-window -lsfml-system -std=c++17

main.o: ${IMPLEMENTATION_FILES} # compiling
	g++ -c ${IMPLEMENTATION_FILES}

clean:
	rm *.o main
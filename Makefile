all: main

main:
	g++ src/*.c src/*.cpp -Iinclude/ -lglfw3 -o bin/cps.exe
	bin/cps.exe

# por enquanto só pra windows

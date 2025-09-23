all: main

main:
	gcc src/*.c -Iinclude/ -lglfw3 -o bin/cps.exe
	bin/cps.exe

# por enquanto só pra windows

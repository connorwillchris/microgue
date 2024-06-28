all:
	gcc src/main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -llua -o microgue

clean:
	rm -rf microgue

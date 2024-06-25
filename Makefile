all:
	gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o microgue

clean:
	rm -rf microgue

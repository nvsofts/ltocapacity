all: ltocapacity

ltocapacity: ltocapacity.o
	gcc -o $@ $^

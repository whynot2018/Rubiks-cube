cc = gcc
cflags = -lglut -lGLU -lGL -lm
output = -o rubiks

target: 
	$(cc) rubiks.c  $(output) $(cflags) 

clean:
	rm rubiks
 
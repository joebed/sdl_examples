OBJS = 01_hello_SDL.cpp 02_getting_an_image_on_the_screen.cpp

OBJ_NAME = 01_hello_SDL 02_getting_an_image_on_the_screen

all: $(OBJS)
	1
	2

1: 01_hello_SDL.cpp
	g++ 01_hello_SDL.cpp -w -lSDL2 -o 01_hello_SDL

2: 02_getting_an_image_on_the_screen.cpp
	g++ 02_getting_an_image_on_the_screen.cpp -w -lSDL2 -o 02_getting_an_image_on_the_screen

clean:
	rm $(OBJS) $(OBJ_NAME)
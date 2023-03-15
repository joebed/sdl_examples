#include <SDL2/SDL.h>
#include <iostream>

using std::cout, std::endl;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void print_sdl_error() {
    cout << "SDL_Error: " << SDL_GetError() << endl;
}

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! ";
        print_sdl_error();
        success = false;
    }
    else {
        gWindow = SDL_CreateWindow(
            "SDL Tutorial", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN);
        
        if (gWindow == NULL) {
            cout << "Window could not be created! ";
            print_sdl_error();
        }
        else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia() {
    bool success = true;

    gHelloWorld = SDL_LoadBMP("./assets/yes.bmp");
    if (gHelloWorld == NULL) {
        cout << "Unable to load image ./assets/yes.bmp! ";
        print_sdl_error();
        success = false;
    }
    return success;
}

void close() {
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    if (!init()) {
        cout << "Failed to initialize\n";
    }
    else {
        if (!loadMedia()) {
            cout << "Failed to load media!\n";
        }
        else {
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            SDL_UpdateWindowSurface(gWindow);
            SDL_Event e; 
            bool quit = false; 
            while( quit == false ){ 
                while( SDL_PollEvent( &e ) ){ 
                    if( e.type == SDL_QUIT ) quit = true; 
                } 
            }
        }
    }
    close();
    return 0;
}
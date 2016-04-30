/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: corealugly
 *
 * Created on April 30, 2016, 1:19 AM
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <cstdio>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
bool quit = false;
SDL_Event event;
    
    
if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Quit();
        
SDL_Window *window;        
SDL_Renderer *renderer;
SDL_Texture *texture;
      
window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
if (window == nullptr){
	std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	SDL_Quit();
	return 1;
}
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
if (renderer == nullptr){
	SDL_DestroyWindow(window);
	std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	SDL_Quit();
	return 1;
}

IMG_Init(IMG_INIT_JPG);

SDL_Surface *image = IMG_Load("/home/corealugly/Pictures/mygoddes_wings.jpg");
if (!image ) {
    perror("image no load");
    return 1;
}
texture = SDL_CreateTextureFromSurface(renderer, image);

while (!quit)
    {
    
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
 
        //SDL_Rect dstrect = { 5, 5, 320, 240 };
        //SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }




SDL_DestroyTexture(texture);
SDL_FreeSurface(image);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);

IMG_Quit();
SDL_Quit();
return 0;
}


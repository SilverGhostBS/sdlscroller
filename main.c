/* 
 * File:   main.c
 * Author: SilverGhost
 *
 * Created on 19 february 2018, 12:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

/*
 * 
 */
int main(int argc, char** argv) {

    SDL_Surface* screen = NULL;
    //Start SDL
    SDL_Init( SDL_INIT_VIDEO );

	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo ();
	
	int systemX = videoInfo->current_w ;
	int systemY = videoInfo->current_h ;
	Uint8 bpp = videoInfo->vfmt->BitsPerPixel ;
	
    //Set up screen
    screen = SDL_SetVideoMode( systemX, systemY, bpp, SDL_SWSURFACE );
    if (!screen)
    {
        printf("SDL_SetVideoMode failed\n");
        return 0;
    }
    
    SDL_Rect r = {0,0,320,240};
    SDL_FillRect(screen,&r, SDL_MapRGB(screen->format, 200,200,0) );

    //Update Screen
    SDL_Flip( screen );
    //Pause
    SDL_Delay( 2000 );

    //Quit SDL
    SDL_Quit();
    
    return (EXIT_SUCCESS);
}


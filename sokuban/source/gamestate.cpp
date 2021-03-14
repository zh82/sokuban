#include "gamestate.hpp"
#include <fstream>
#include "gamemap.hpp"

GameState::GameState() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Sokuban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    manager = TextureManager(renderer);
}

GameState::~GameState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

SDL_Renderer *GameState::get_renderer() {
    return renderer;
}

TextureManager *GameState::get_texture_manager() {
    return &manager;
}

void GameState::loop() {
    SDL_Event event;

  /* Poll for events. SDL_PollEvent() returns 0 when there are no  */
  /* more events on the event queue, our while loop will exit when */
  /* that occurs.
                                               */
  while(true){
  while( SDL_PollEvent( &event ) ){
    /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
    switch( event.type ){
      case SDL_KEYDOWN:
       if(event.key.keysym.sym==SDLK_LEFT){
std::cout <<"down";
    }
        else{
            std::cout <<"up";
        }
        break;

      case SDL_KEYUP:
        printf( "Up\n" );
        break;


      default:
        break;


    }


  }
  }

}

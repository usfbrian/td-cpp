#include "TowerDefense.hpp"
#include "Tower.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <SDL2/SDL.h>
#include <stdio.h>

#define VERSION "0.9"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main(int argc, char *argv[]) {
  std::string argOptionVersion = "--version";
  if (std::find(argv, argv + argc, argOptionVersion) != argv + argc) {
    std::cout << VERSION << std::endl;
    return 0;
  }

  bool init();
  bool loadMedia();
  void close();

  SDL_Window *p;
  SDL_Renderer *w;
  p = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, 800, 640, SDL_WINDOW_SHOWN);
  w = SDL_CreateRenderer(p, -1, 0);

  SDL_RenderClear(w);

  SDL_SetRenderDrawColor(w, 255, 0, 0, 255);
  SDL_Rect Rect = {220, 140, 200, 200};

  SDL_RenderFillRect(w, &Rect);

  SDL_RenderPresent(w);

  SDL_Delay(3000);

  SDL_DestroyRenderer(w);
  SDL_DestroyWindow(p);
  SDL_Quit();

  std::vector<Tower> towerList;
  Tower thisTower;
  towerList.push_back(thisTower);
  Tower thatTower;
  thatTower.changeHealth(-20);
  towerList.push_back(thatTower);
  auto lambda = [](auto x){ return x; };
  std::cout << lambda("Generic lambda") << std::endl;
  for(Tower& t : towerList) {
    std::cout << t.getHealth() << std::endl;
  }
  return 0;
}

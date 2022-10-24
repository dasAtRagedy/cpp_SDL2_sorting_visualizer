#include <SDL.h>
#include <iostream>
#include <random>
#include <algorithm>

#define n 100 // number of elements to be sorted

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int a, unsigned int b){
    for(int i = 0; i < n; i++){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, i, 99, i, v[i]);
    }
}

int main(int argc, char* args[]) {
    // Populate vector with shuffled unique numbers 0 ~ n
    std::vector<int> v;
    for(int i = 0; i < n; i++)
        v.push_back(i);

    // std::random_shuffle is removed in c++17
    std::shuffle(v.begin(), v.end(), std::mt19937(std::random_device()()));

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(
                                200, 200, 0,
                                &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);

    // Sorting algorithm - bubble sort
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] > v[j])
                std::swap(v[i],v[j]);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw_state(v, renderer, i, j);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }

    // print result
    for(int i : v){
       std::cout<<i<<' ';
    }

    return 0;
}

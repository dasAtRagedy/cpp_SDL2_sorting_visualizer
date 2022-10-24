#include <SDL.h>
#include <iostream>
#include <random>
#include <algorithm>

#define n 100 // number of elements to be sorted
#define scale 4 // scale of elements on screen
#define delay 5 // delay between every comparison

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int a, unsigned int b){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int i = 0; i < n; i++){
        if (i == a)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if(i == b)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, i, n-1, i, v[i]);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(delay);
}

void bubble_sort(std::vector<int> v, SDL_Renderer* renderer){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] > v[j])
                std::swap(v[i],v[j]);
            draw_state(v, renderer, i, j);
        }
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
    SDL_CreateWindowAndRenderer(scale*n, scale*n, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, scale, scale);

    // Sorting algorithm - bubble sort
    bubble_sort(v, renderer);

    return 0;
}

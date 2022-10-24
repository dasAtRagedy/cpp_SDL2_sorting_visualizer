#include <iostream>
#include <random>
#include <algorithm>

#define n 100 // number of elements to be sorted

int main() {
    // Populate vector with shuffled unique numbers 0 ~ n
    std::vector<int> v;
    for(int i = 0; i < n; i++)
        v.push_back(i);

    // std::random_shuffle is removed in c++17
    std::shuffle(v.begin(), v.end(), std::mt19937(std::random_device()()));

    // Sorting algorithm - bubble sort
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] > v[j])
                std::swap(v[i],v[j]);
        }
    }

    // print result
    for(int i : v){
       std::cout<<i<<' ';
    }

    return 0;
}

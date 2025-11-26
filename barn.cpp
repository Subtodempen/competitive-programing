#include <iostream>
#include <cstdio>
#include <vector>

#include <limits>
#include <cmath>

int main(){
    freopen("barn.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    std::vector<int> barn;
    for(int i=0; i < n; i++){
        int barnSize;
        scanf("%d", &barnSize);

        barn.push_back(barnSize);
    }

    int distance, minDistance = std::numeric_limits<int>::max(); 
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            int index = (i + j) % n;
            
            distance += barn.at(index) * j;
        }
        
        minDistance = std::min(distance, minDistance);
        distance = 0;
    }

    std::cout<<minDistance;
}
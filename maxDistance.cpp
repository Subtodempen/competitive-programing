#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>


int main(){
    freopen("maxDData.txt", "r", stdin);\

    int N;
    scanf("%d", &N);

    std::pair<std::vector<int>,  std::vector<int>> coords;

    for(int i=0; i < N; i++){
        int x;
        scanf("%d", &x);

        coords.first.push_back(x);
    }
    
    for(int i=0; i < N; i++){
        int y;
        scanf("%d", &y);

        coords.second.push_back(y);
    }

    int maxSquare = 0;

    for(int i = 0; i < N; i++){
        for(int j= i + 1; j < N; j++){
            int dx = coords.first[j] - coords.first[i];
            int dy = coords.second[j] - coords.second[i];

            int square = (dy * dy) + (dx * dx);

            maxSquare = std::max(maxSquare, square);
        }
    }


    std::cout<<maxSquare;
}

#include <cstdio>
#include <utility>
#include <vector>

#include <iostream>

int main(){
    freopen("mixingData.txt", "r", stdin);

    std::vector<std::pair<int, int>> buckets;
    for(int i = 0; i < 3; i++){
        int c, m;
        scanf("%d %d", &c, &m);

        buckets.push_back({c, m});
    }

    for(int i=0; i < 100; i++){
        auto& a = buckets.at(i % 3);
        auto& b = buckets.at((i + 1) % 3);

        if(b.first < a.second + b.second){
            b.second = b.first;
            a.second = a.first - b.second;
        
        }else{
            b.second += a.second;
            a.second = 0;
        }

        std::cout << buckets[0].second 
              << buckets[1].second 
              << buckets[2].second
              << std::endl; 
    }


}
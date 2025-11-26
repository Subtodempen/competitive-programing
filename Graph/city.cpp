#include <stdio.h>
#include <utility>
#include <vector>
#include <iostream>


std::vector<int> cities[1000000];
std::vector<bool> visited;

std::vector<std::pair<int, int>> roads;

void dfs(int n){
    if(visited[n]) return;
    visited[n] = true;

    for(auto u : cities[n])
        dfs(u);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    visited.resize(n+1, false);

    for(int i=0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        a--;
        b--;

        cities[a].push_back(b);
        cities[b].push_back(a); 
    }

    int prevNode = 0;
    dfs(0);

    for(int i=0; i < n; i++){
        if(visited[i]) continue;
        roads.push_back({prevNode, i});

        dfs(i);
        prevNode = i;
    }

    std::cout<<roads.size()<<std::endl;
    for(auto r : roads)
        std::cout<<r.first+1<<" "<<r.second+1<<std::endl;
    
}
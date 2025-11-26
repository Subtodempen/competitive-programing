#include <vector>
#include <cstdio>
#include <iostream>

std::vector<int> graph[100000];
std::vector<bool> visited;

std::vector<int> colorVec;
bool bipartness = true;

// DFS also peforms bipartness check
void dfs(int n, int color){
    if(visited[n]){
        if(colorVec[n] != color && colorVec[n] != 0) bipartness = false;
        return;
    }

    visited[n] = true;
    colorVec[n] = color;

    for(auto u : graph[n]){
        int colorU = (color == 1) ? 2 : 1;
        dfs(u, colorU);
    }
}

int main(){
    freopen("build.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    colorVec.resize(n + 1, 0);
    visited.resize(n + 1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i < n; i++){
        if(visited[n]) continue;

        bipartness = true;
        dfs(i, 1);

        if(!bipartness){
            std::cout<<"IMPOSSIBLE"<<std::endl;
            return 0;
        }   
    }

    for(auto b : colorVec){
        std::cout<<(int)b + 1<<" ";
    }
}
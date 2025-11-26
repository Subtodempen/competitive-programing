#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

std::vector<int> farmGraph[3000];
std::vector<bool> visited;

void dfs(int s){
    if (visited[s]) return;
    visited[s] = true;

    for(auto n : farmGraph[s])
        dfs(n);
}

std::string checkConectivity(std::vector<int> removed){
    for(int i=0; i < visited.size(); i++){
        if(!visited[i] && (std::find(removed.begin(), removed.end(), i) == removed.end()))
            return "NO";
    }

    return "YES";
}

int main(){
    freopen("farm.txt", "r", stdin);

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        a--; b--;

        farmGraph[a].push_back(b);
        farmGraph[b].push_back(a);
    }

    int r;
    std::vector<int> removed;

    visited.resize(N, false);
    dfs(0);
    std::cout<<checkConectivity(removed);

    for(int i = 1; i < N; i++){
        visited.clear();
        visited.resize(N, false);
        
        scanf("%d", &r);
        farmGraph[r] = {};

        for(int j=0; j < N; j++){
            if(farmGraph[j].empty())
                break;

            farmGraph[j].erase(
                std::find(farmGraph[j].begin(), farmGraph[j].end(), r));
        }

        removed.push_back(r);

        dfs(i);
        std::cout<<checkConectivity(removed);
    }
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

int countPaths(std::vector<int> graph[], int index, int &count, std::vector<bool> &visited){
    if(visited[index]) return 0;
    visited[index] = true;

    count++;

    for(auto u : graph[index]){
        countPaths(graph, u, count, visited);
    }

    return count;
}

int destroyBridges(int n, int k){
    std::vector<int> graph[n];
    
    // set up the graph
    for (int i=0; i < n; i++) {
        for(int j=0; j < n; j++){   
            if(j != i)
                graph[i].push_back(j);
        }
    }


    // destroy the optimal bridges
    for(int i=0; i < k; i++){
        int j = (i + 1) % n;
        
        graph[i].erase(std::find(graph[i].begin(), graph[i].end(), j));
        graph[j].erase(std::find(graph[j].begin(), graph[j].end(), i));
    }
    
    // dfs to count the paths
    std::vector<bool> visited(n, false);
    int count = 0;

    return countPaths(graph, 0, count, visited);
}



int main(){
    freopen("destroyB.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);

    for(int i=0; i < N; i++){
        int n, k;
        scanf("%d %d", &n, &k);

        std::cout<<destroyBridges(n, k);
    }

    return 0;
}
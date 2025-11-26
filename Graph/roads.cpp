#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

// SOLVED CORRECT

std::vector<std::vector<char>> grid;

std::vector<std::vector<bool>> visited;
void dfs(int x, int y){
    if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return;
    if(visited[y][x] || grid[y][x] == '#') return;

    visited[y][x] = true;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    grid.resize(N );
    visited.resize(N );

    for(int i=0; i < N; i++){
        grid[i].resize(M);
        visited[i].resize(M );

        for(int j=0; j < M; j++){
            char c;
            scanf(" %c", &c);

            grid[i][j] = c;
        }
    }


    int rooms = 0;
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            if(visited[i][j])
                continue;

            if(grid[i][j] == '.'){
                rooms++;
                dfs(j, i);
            }
        }
    }

    std::cout<<rooms;
}
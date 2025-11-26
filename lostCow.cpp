#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <cmath>

int main(){
    freopen("lostCow.txt", "r", stdin);
    
    int x, y;
    scanf("%d %d", &x, &y);

    unsigned int distance = 0; 
    int travel = 1, prevTravel = 0;

    while (x < y){
        distance += abs(x);
        x += travel; 
        travel *= -2;

        std::cout<<travel<<std::endl;
    }

    std::cout << distance;
}
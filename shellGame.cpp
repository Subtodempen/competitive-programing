#include <iostream>
#include <algorithm>
#include <cstdio>

#include <utility>
#include <vector>

int main(){
    freopen("shelldata.txt", "r", stdin);
    
    int n;
    scanf("%d", &n);

    std::vector<int> shells(3);
    std::fill(shells.begin(), shells.end(), 1);


    for(int i = 0; i < n; i++){
        int a, b, g;
        scanf("%d %d %d", &a, &b, &g);

        iter_swap(shells.begin() + a, 
                  shells.begin() + b);

        shells.at(g) += 1;
    }
    
    std::cout << *std::max_element(shells.begin(), shells.end());
}
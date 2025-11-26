#include <cstdio>
#include <iostream>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    if(a == b){
        std::cout<<1;
        return 0;
    }


    int years = 0;
    while(a <= b){
        a *= 3;
        b *= 2;

        years++;
    }

    std::cout<<years;
}
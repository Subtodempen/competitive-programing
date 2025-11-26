#include <functional>
#include <stack>
#include <vector>

#include <iostream>
#include <string>

using func = std::function<int(int)>;
std::vector<int> memo;

std::stack<func> order;


int even(int i){
    return i * 2;
}

int odd(int i){
    return (i * 2) + 1;
}

int T(int i){
    if (memo.size() >= i)
        return memo[i];
    
    for(int j = 0; j < i; j++){
        for(int y = 0; y < j; y++){
            memo.push_back(j);
        }
    }

    return memo[i];
}

void combine(func L, func R){
    order.push(R);
    order.push(L);
    order.push(R);
}

std::stack<func> parseString(std::string s){

}

int main(){
    std::string s;
    std::cin>>s;

}


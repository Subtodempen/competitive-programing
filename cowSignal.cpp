#include <codecvt>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>


int main(){
    freopen("cowData.txt", "r", stdin);

    int M, N, k;
    scanf("%d %d %d", &M, &N, &k);

    std::vector<std::vector<std::string>> signal(M * k);

    for (int i=0; i < M; i++){
        for(int j=0; j < N; j++){
            char c;
            scanf(" %c", &c);

            std::string newChar(k, c);
            signal[i].push_back(newChar);
        }

        signal.push_back(signal[i]);
    }

    for (auto s : signal){
        for(auto str : s){
            std::cout << str;
        }
        std::cout<< std::endl;
    }
}
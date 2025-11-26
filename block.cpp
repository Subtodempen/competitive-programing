#include <cstdio>
#include <iostream>
#include <vector>



int main(){
    freopen("block.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    std::vector<int> alpha(26, 0);
    N += 1;

    for(int i=0; i < N; i++){
        std::string words;  
        std::getline(std::cin, words);

        std::vector<bool> occour(26, 0);

        for(const char& c : words){
            if(c == ' ')
                continue;
            
            int index = (int)c % 97;
            
            if(!occour.at(index)){
                alpha.at(index) += 1;
                occour.at(index) = true;
            }
        }
        
        occour.clear();
    }


    for(int o : alpha){
        std::cout<<o<<std::endl;
    }
}  
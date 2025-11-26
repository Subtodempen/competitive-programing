#include <string>
#include <vector>
#include <iostream>


int main(){
    std::vector<int> cog1;
    std::vector<int> cog2;
    std::vector<int> cog3;
   
    for(int i=1; i <= 8; i++){
        cog1.push_back(i);
    }
    
    for(int i=1; i <= 9; i++){
        cog3.push_back(i);
    }

    for(int i=10; i <= 20; i++){
        cog2.push_back(i);
    }

    long long T = 0;
    long long S = 0;
    
    for(int i=0; i < 792; i++){
        int index1 = i % cog1.size();
        int index2 = i % cog2.size();
        int index3 = i % cog3.size();

        std::string s = std::to_string(cog1.at(index1)) + std::to_string(cog2.at(index2)) + std::to_string(cog3.at(index3));
        S += std::stoi(s);
        T += (cog1.at(index1) * cog2.at(index2) * cog3.at(index3));

        //std::cout<<std::stoi(s)<<std::endl;
    }
    std::cout<<S << std::endl << T <<std::endl;
}
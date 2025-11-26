#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <utility>

void calcMin(int x1, int y1, int& x2, int& y2){
    x2 = std::max(x1, x2);
    y2 = std::min(y1, y2);
}

std::string readWord(){
    std::string s;
    char currC;
    
    while (currC != ' '){
        scanf("%c", &currC);
        
        if ((int)currC > 96)
            s += currC;
    }
    return s;
}

int main(){
    freopen("traffic.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    std::string currWord;
    int flowX = 0, flowY = 0;

    for(int i=0; i < N; i++){
        std::string currWord = readWord();
        
        int x, y;
        scanf("%d %d", &x, &y);

        if (currWord == "none"){
            calcMin(x, y, flowX, flowY);

        }else if(currWord == "on"){
            flowY += y;
        
        }else if(currWord == "off"){
            flowX -= x;
        }
    }

    std::cout << flowX << " " << flowY; 
}
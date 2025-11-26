
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Circle{
    double a, b, c; 
};


bool pointCircleIntersection(double x, double y, std::vector<Circle> c){
    for(auto R : c){
        if(std::pow((x - R.a), 2) + std::pow((y - R.b), 2) > R.c * R.c){
            return false;
        }
    }

    return true;
}

int main(){
    long long N = 100000000;
    
    double a = 1;
    double b = 8;

    int sum = 0; 
    
    std::vector<double> abc = {3, 4, 5};
    std::vector<Circle> circles;

    std::uniform_real_distribution<double> unif(a, b);
    std::default_random_engine re;
    
    do{
        Circle c = {abc[0], abc[1], abc[2]};
        circles.push_back(c);

    }while(std::next_permutation(abc.begin(), abc.end()));


    for(long long i = 0; i < N; i++){
        double xi = unif(re);
        double yi = unif(re);

        sum += (int)pointCircleIntersection(xi, yi, circles);
    }

    std::cout<<(double)((std::pow((b-a), 2) * sum) / N);
}
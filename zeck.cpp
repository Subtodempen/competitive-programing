#include <iostream>
#include <unordered_map>
#include <vector>

#include <cmath>

std::unordered_map<int, int> memo;
int genFactorial(int n){
  if(memo.find(n)  != memo.end()) return memo[n];
  if(n <= 0)
    return 0;

  else if(n == 1)
    return 1;

  else if (n == 2)
    return 2;
  memo[n] = genFactorial(n - 1) + genFactorial(n - 2);
  return memo[n];
}

int main(){
  int n;
  std::cin >> n;
  
  std::vector<int> sum;

  genFactorial(ceil(sqrt(n)));
  for(int i=n; i >= 0; i--){
    if(memo.find(i) != memo.end() && memo[i] <= n){
      sum.push_back(memo[i]);
      n -= memo[i];

      i--;
    }
  }

  for(int i : sum)
    std::cout<< i << " ";
}

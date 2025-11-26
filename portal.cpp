#include <iostream>
#include <utility>

int main() {
  std::string s;
  std::cin >> s;

  std::string sBegin = s;
  for (int i = 1; i <= s.size(); i++) {
    char c1 = s[i - 1];
    char c2 = s[i];

    if ((int)(c2 - 65) == (27 - ((int)c1 - 65))) {
      if (c1 < c2)
        std::swap(s[i], s[s.size() - 1]);

      else
        std::swap(c2, s[0]);
    }
  }

  if (s == sBegin) {
    std::cout << "Indefinite";
    return -1;
  }

  std::cout << s;
}

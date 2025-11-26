#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string letterBox;
  std::string word;
  int n, m;

  std::cin >> letterBox;
  std::cin >> word;
  std::cin >> n >> m;

  bool isValid = false;

  for (int i = 0; i < word.size(); i++) {
    // check if word is n letters to the same side
    // if not then valid else return i at the point + 1
    for (int j = std::max(i - n, 0); j < (n + i); j++) {
      if (j >= word.size() || j == i)
        continue;

      int side1 = (int)(letterBox.find(word[j]) / 3);
      int side2 = (int)(letterBox.find(word[i]) / 3);

      if (side1 == side2) {
        std::cout << i + 1;
        return 0;
      }
    }

    isValid = false;
    // check that letter is m words from its oppisite
    // if (go out of bound return end)
    // if m doesnnt runs out and still not valid return i+1
    int j = std::max(i - m, 0);
    for (; j <= i + m; j++) {
      if (j == i)
        continue;

      if (j >= word.size()) {
        std::cout << "End";
        return 0;
      }

      int opposite = (letterBox.find(word[i]) + 6) % 12;
      if (word[j] == letterBox[opposite]) {
        isValid = true;
        break;
      }
    }

    if (!isValid) {
      std::cout << j;
      return 0;
    }
  }

  if (isValid) {
    std::cout << "Valid";
  }
}

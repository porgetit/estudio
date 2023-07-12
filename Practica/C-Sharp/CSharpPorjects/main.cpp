# include <string>
#include <iostream>

std::string disemvowel(const std::string& str) {
  std::string stringCopy = str;
  int len = stringCopy.length();
  int position = 0;

  while (position < len) {

    if (stringCopy[position] == 'a' || stringCopy[position] == 'A') {
      stringCopy.erase(position, 1);
      position -= 1;
    } else if (stringCopy[position] == 'e' || stringCopy[position] == 'E') {
      stringCopy.erase(position, 1);
      position -= 1;
    } else if (stringCopy[position] == 'i' || stringCopy[position] == 'I') {
      stringCopy.erase(position, 1);
      position -= 1;
    } else if (stringCopy[position] == 'o' || stringCopy[position] == 'O') {
      stringCopy.erase(position, 1);
      position -= 1;
    } else if (stringCopy[position] == 'u' || stringCopy[position] == 'U') {
      stringCopy.erase(position, 1);
      position -= 1;
    }

    position += 1;
  }
  
  return stringCopy;
}

int main() {
    std::string out = disemvowel("abacadaeaf");
    std::cout << out << std::endl;
}
#include <iostream>
#include <string>

int main() {

    std::string dnaSequence;
    std::cin >> dnaSequence;
    char currentChar = dnaSequence[0];
    int currentLength = 1;
    int maxLength = 1;
    for (int i = 1; i < dnaSequence.length(); ++i) {
        if (dnaSequence[i] == currentChar) {
            currentLength++;
        } else {
            maxLength = std::max(maxLength, currentLength);
 currentChar = dnaSequence[i];
            currentLength = 1;
        }
    }
 maxLength = std::max(maxLength, currentLength);
 std::cout << maxLength << std::endl;

    return 0;
}

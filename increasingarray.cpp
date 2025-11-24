#include <iostream>
#include <vector>

int main() {
   
    int n;
    std::cin >> n;
 std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
   long long moves = 0;
    int minExpectedValue = array[0];
   for (int i = 1; i < n; ++i) {
        if (array[i] < minExpectedValue) {
            moves += (minExpectedValue - array[i]);
        } else {
             minExpectedValue = array[i];
        }
    }
 std::cout << moves << std::endl;

    return 0;
}

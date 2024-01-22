#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n;
    cin >> n;
  vector<long long> numbers(n - 1);
    long long expected_sum = n * (n + 1) / 2; 
    long long actual_sum = 0;
 for (long long i = 0; i < n - 1; ++i) {
        cin >> numbers[i];
        actual_sum += numbers[i];
    }
  long long missing_number = expected_sum - actual_sum;
 cout << missing_number << endl;
 return 0;
}

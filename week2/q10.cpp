#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {
        int n;
        cin >> n;  // Read the number of elements in the current test case
        
        map<long double, long long> freq;  // Map to store frequency of transformed values
        
        // Read the input numbers and apply the transformation
        for (int i = 0; i < n; ++i) {
            long double a;
            cin >> a;
            long double r = a - log2l(a);  // Transformation using long double and log2l for precision
            freq[r]++;  // Increment frequency of transformed value
        }

        long long result = 0;

        // Calculate the number of pairs
        for (const auto& entry : freq) {
            long long count = entry.second;
            if (count > 1) {
                result += (count * (count - 1)) / 2;  // Calculate combinations of pairs
            }
        }

        cout << result << endl;  // Output the result for the current test case
    }

    return 0;
}

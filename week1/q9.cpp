#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int substrings_with_k_distinct_characters(int k, string s) {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<char> one;
        for (int j = i; j < n; j++) {
            one.insert(s[j]);
            if (one.size() == k) {
                count++;
            } else if (one.size() > k) {
                break;
            }
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t>0) {
        int k;
        cin >> k;
        string s;
        cin >> s;

        cout << substrings_with_k_distinct_characters(k, s) << endl;
        t--;
    }

    return 0;
}
